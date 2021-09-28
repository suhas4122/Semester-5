#include <stdio.h>
#include <stdint.h>

#define AES_BLOCK_SIZE      16    
#define AES_ROUNDS          10  
#define AES_ROUND_KEY_SIZE  176   // 11 keys of size 16, 11*16 = 176 

#define FEISTEL_BLOCK_SIZE  8
#define FEISTEL_ROUNDS      4     
#define FEISTEL_KEY_SIZE    32    // 4 keys of size 8, 4*8 = 32

/* Round constants */
uint8_t RC[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

/* Sbox */
uint8_t SBOX[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

/*
 * Inverse Sboxs
 */
uint8_t INV_SBOX[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};

/*
 * Multiply two numbers in the GF(2^8) finite field defined
 * by the polynomial x^8 + x^4 + x^3 + x + 1 = 0
 */
uint8_t mul2(uint8_t a) {
    return (a&0x80) ? ((a<<1)^0x1b) : (a<<1);
}

/*
 *  ShiftRows
 *  Row0: s0  s4  s8  s12   <<< 0 byte
 *  Row1: s1  s5  s9  s13   <<< 1 byte
 *  Row2: s2  s6  s10 s14   <<< 2 bytes
 *  Row3: s3  s7  s11 s15   <<< 3 bytes
 */
void shift_rows(uint8_t *state) {
    uint8_t temp;
    // row1
    temp        = *(state+1);
    *(state+1)  = *(state+5);
    *(state+5)  = *(state+9);
    *(state+9)  = *(state+13);
    *(state+13) = temp;
    // row2
    temp        = *(state+2);
    *(state+2)  = *(state+10);
    *(state+10) = temp;
    temp        = *(state+6);
    *(state+6)  = *(state+14);
    *(state+14) = temp;
    // row3
    temp        = *(state+15);
    *(state+15) = *(state+11);
    *(state+11) = *(state+7);
    *(state+7)  = *(state+3);
    *(state+3)  = temp;
}

/*
 *  Inverse ShiftRows
 *  Row0: s0  s4  s8  s12   >>> 0 byte
 *  Row1: s1  s5  s9  s13   >>> 1 byte
 *  Row2: s2  s6  s10 s14   >>> 2 bytes
 *  Row3: s3  s7  s11 s15   >>> 3 bytes
 */
void inv_shift_rows(uint8_t *state) {
    uint8_t temp;
    // row1
    temp        = *(state+13);
    *(state+13) = *(state+9);
    *(state+9)  = *(state+5);
    *(state+5)  = *(state+1);
    *(state+1)  = temp;
    // row2
    temp        = *(state+14);
    *(state+14) = *(state+6);
    *(state+6)  = temp;
    temp        = *(state+10);
    *(state+10) = *(state+2);
    *(state+2)  = temp;
    // row3
    temp        = *(state+3);
    *(state+3)  = *(state+7);
    *(state+7)  = *(state+11);
    *(state+11) = *(state+15);
    *(state+15) = temp;
}

void key_schedule(const uint8_t *key, uint8_t *aeskeys, uint8_t *feistelkeys) {

    uint8_t temp[4];
    uint8_t *last4bytes; // point to the last 4 bytes of one round
    uint8_t *lastround;
    uint8_t i;

    for (i = 0; i < 16; ++i) {
        *aeskeys++ = *key++;
    }

    last4bytes = aeskeys-4;
    for (i = 0; i < AES_ROUNDS; ++i) {
        // k0-k3 for next round
        temp[3] = SBOX[*last4bytes++];
        temp[0] = SBOX[*last4bytes++];
        temp[1] = SBOX[*last4bytes++];
        temp[2] = SBOX[*last4bytes++];
        temp[0] ^= RC[i];
        lastround = aeskeys-16;
        *aeskeys++ = temp[0] ^ *lastround++;
        *aeskeys++ = temp[1] ^ *lastround++;
        *aeskeys++ = temp[2] ^ *lastround++;
        *aeskeys++ = temp[3] ^ *lastround++;
        // k4-k7 for next round        
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        // k8-k11 for next round
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        // k12-k15 for next round
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
        *aeskeys++ = *last4bytes++ ^ *lastround++;
    }

    for (i = 0; i < FEISTEL_ROUNDS/2; ++i) {
        temp[3] = SBOX[*last4bytes++];
        temp[0] = SBOX[*last4bytes++];
        temp[1] = SBOX[*last4bytes++];
        temp[2] = SBOX[*last4bytes++];
        temp[0] ^= RC[i];
        lastround = aeskeys-16;
        *feistelkeys++ = temp[0] ^ *lastround++;
        *feistelkeys++ = temp[1] ^ *lastround++;
        *feistelkeys++ = temp[2] ^ *lastround++;
        *feistelkeys++ = temp[3] ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
        *feistelkeys++ = *last4bytes++ ^ *lastround++;
    }
}

void block_encrypt(const uint8_t *aeskeys, const uint8_t *feistalkeys, uint8_t *ciphertext, const uint8_t *plaintext) {
    printf("--------------------- ENCRYPTION STARTS --------------------\n\n");

    uint8_t tmp[16], t;
    uint8_t i, j, k = 0;

    printf("Initial Plaintext:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", plaintext[i]);
	}

    /* 
     * FIRST FIVE ROUNDS OF AES ENCRYPTION 
     */

    // Initial AddRoundKey Operation 
    for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
        *(ciphertext+i) = *(plaintext+i) ^ *aeskeys++;
    }

    // 5 rounds
    for (j = 1; j < 6; ++j) {

        // SubBytes
        for (i = 0; i < AES_BLOCK_SIZE; ++i) {
            *(tmp+i) = SBOX[*(ciphertext+i)];
        }

        // Shift rows operation 
        shift_rows(tmp);

        /*
         * MixColumns 
         * [02 03 01 01]   [s0  s4  s8  s12]
         * [01 02 03 01] . [s1  s5  s9  s13]
         * [01 01 02 03]   [s2  s6  s10 s14]
         * [03 01 01 02]   [s3  s7  s11 s15]
         */
        for (i = 0; i < AES_BLOCK_SIZE; i+=4) {
            t = tmp[i] ^ tmp[i+1] ^ tmp[i+2] ^ tmp[i+3];
            ciphertext[i]   = mul2(tmp[i]   ^ tmp[i+1]) ^ tmp[i]   ^ t;
            ciphertext[i+1] = mul2(tmp[i+1] ^ tmp[i+2]) ^ tmp[i+1] ^ t;
            ciphertext[i+2] = mul2(tmp[i+2] ^ tmp[i+3]) ^ tmp[i+2] ^ t;
            ciphertext[i+3] = mul2(tmp[i+3] ^ tmp[i]  ) ^ tmp[i+3] ^ t;
        }

        // AddRoundKey
        for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
            *(ciphertext+i) ^= *aeskeys++;
        }

    }

    printf("\n\nEncrypted Message After 5 AES Rounds:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", ciphertext[i]);
	}

    /* 
     * FOUR ROUNDS OF FEISTEL ENCRYPTION  
     */

    uint8_t left[FEISTEL_BLOCK_SIZE], right[FEISTEL_BLOCK_SIZE], temp[FEISTEL_BLOCK_SIZE];

    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        left[i] = ciphertext[i];
    }

    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        right[i] = ciphertext[i + FEISTEL_BLOCK_SIZE];
    }

    for (i = 0; i < FEISTEL_ROUNDS; i++){
        for (j = 0; j < FEISTEL_BLOCK_SIZE; j++){
            temp[j] = left[j] ^ right[j] ^ feistalkeys[k++];
            left[j] = right[j];
            right[j] = temp[j];
        }
    }

    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        ciphertext[i] = left[i];
    }

    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        ciphertext[i + FEISTEL_BLOCK_SIZE] = right[i];
    }

    printf("\n\nEncrypted Message After 5 AES and 4 Feistel Rounds:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", ciphertext[i]);
	}

    /* 
     * LAST FIVE ROUNDS OF AES ENCRYPTION 
     */

    for (j = 1; j < 5; ++j) {

        // SubBytes
        for (i = 0; i < AES_BLOCK_SIZE; ++i) {
            *(tmp+i) = SBOX[*(ciphertext+i)];
        }

        // Shift rows operation 
        shift_rows(tmp);

        /*
         * MixColumns 
         * [02 03 01 01]   [s0  s4  s8  s12]
         * [01 02 03 01] . [s1  s5  s9  s13]
         * [01 01 02 03]   [s2  s6  s10 s14]
         * [03 01 01 02]   [s3  s7  s11 s15]
         */
        for (i = 0; i < AES_BLOCK_SIZE; i+=4) {
            t = tmp[i] ^ tmp[i+1] ^ tmp[i+2] ^ tmp[i+3];
            ciphertext[i]   = mul2(tmp[i]   ^ tmp[i+1]) ^ tmp[i]   ^ t;
            ciphertext[i+1] = mul2(tmp[i+1] ^ tmp[i+2]) ^ tmp[i+1] ^ t;
            ciphertext[i+2] = mul2(tmp[i+2] ^ tmp[i+3]) ^ tmp[i+2] ^ t;
            ciphertext[i+3] = mul2(tmp[i+3] ^ tmp[i]  ) ^ tmp[i+3] ^ t;
        }

        // AddRoundKey
        for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
            *(ciphertext+i) ^= *aeskeys++;
        }

    }
    
    // last round
    for (i = 0; i < AES_BLOCK_SIZE; ++i) {
        *(ciphertext+i) = SBOX[*(ciphertext+i)];
    }

    shift_rows(ciphertext);

    for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
        *(ciphertext+i) ^= *aeskeys++;
    }

    printf("\n\nFinal Encrypted Message After 10 AES and 4 Feistel Rounds: \n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", ciphertext[i]);
	}
}

void block_decrypt(const uint8_t *aeskeys, const uint8_t *feistalkeys, const uint8_t *ciphertext, uint8_t *plaintext) {

    printf("\n\n--------------------- DECRYPTION STARTS --------------------\n\n");

    uint8_t tmp[16];
    uint8_t t, u, v;
    uint8_t i, j;

    printf("Initial Ciphertext:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", ciphertext[i]);
	}

    aeskeys += 160;
    feistalkeys += 24;

    /* 
     * INITIAL FIVE ROUNDS OF AES DECRYPTION  
     */

    // first round
    for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
        *(plaintext+i) = *(ciphertext+i) ^ *(aeskeys+i);
    }
    aeskeys -= 16;
    inv_shift_rows(plaintext);
    for (i = 0; i < AES_BLOCK_SIZE; ++i) {
        *(plaintext+i) = INV_SBOX[*(plaintext+i)];
    }

    for (j = 1; j < 5; ++j) {
        
        // Inverse AddRoundKey
        for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
            *(tmp+i) = *(plaintext+i) ^ *(aeskeys+i);
        }
        
        /*
         * Inverse MixColumns
         * [0e 0b 0d 09]   [s0  s4  s8  s12]
         * [09 0e 0b 0d] . [s1  s5  s9  s13]
         * [0d 09 0e 0b]   [s2  s6  s10 s14]
         * [0b 0d 09 0e]   [s3  s7  s11 s15]
         */
        for (i = 0; i < AES_BLOCK_SIZE; i+=4) {
            t = tmp[i] ^ tmp[i+1] ^ tmp[i+2] ^ tmp[i+3];
            plaintext[i]   = t ^ tmp[i]   ^ mul2(tmp[i]   ^ tmp[i+1]);
            plaintext[i+1] = t ^ tmp[i+1] ^ mul2(tmp[i+1] ^ tmp[i+2]);
            plaintext[i+2] = t ^ tmp[i+2] ^ mul2(tmp[i+2] ^ tmp[i+3]);
            plaintext[i+3] = t ^ tmp[i+3] ^ mul2(tmp[i+3] ^ tmp[i]);
            u = mul2(mul2(tmp[i]   ^ tmp[i+2]));
            v = mul2(mul2(tmp[i+1] ^ tmp[i+3]));
            t = mul2(u ^ v);
            plaintext[i]   ^= t ^ u;
            plaintext[i+1] ^= t ^ v;
            plaintext[i+2] ^= t ^ u;
            plaintext[i+3] ^= t ^ v;
        }
        
        // Inverse ShiftRows
        inv_shift_rows(plaintext);
        
        // Inverse SubBytes
        for (i = 0; i < AES_BLOCK_SIZE; ++i) {
            *(plaintext+i) = INV_SBOX[*(plaintext+i)];
        }

        aeskeys -= 16;
    }

    printf("\n\nDecrypted Message After 5 AES Rounds:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", plaintext[i]);
	}

    /* 
     * FOUR ROUNDS OF FEISTEL DECRYPTION  
     */

    uint8_t left[FEISTEL_BLOCK_SIZE], right[FEISTEL_BLOCK_SIZE], temp[FEISTEL_BLOCK_SIZE];

    // Filling up the left array 
    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        left[i] = plaintext[i];
    }

    // Filling up the right array 
    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        right[i] = plaintext[i + FEISTEL_BLOCK_SIZE];
    }

    // Carrying out 4 rounds of feistel decryption 
    for (i = 0; i < FEISTEL_ROUNDS; i++){
        for (j = 0; j < FEISTEL_BLOCK_SIZE; j++){
            temp[j] = left[j] ^ right[j] ^ feistalkeys[j];
            right[j] = left[j];
            left[j] = temp[j];
        }
        feistalkeys -= 8;
    }

    // Transferring back to plaintext array 
    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        plaintext[i] = left[i];
    }

    // Transferring back to plaintext array
    for (i = 0; i < FEISTEL_BLOCK_SIZE; i++){
        plaintext[i + FEISTEL_BLOCK_SIZE] = right[i];
    }

    printf("\n\nDecrypted Message After 5 AES and 4 Feistel Rounds:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", plaintext[i]);
	}

    /* 
     * FINAL FIVE ROUNDS OF AES DECRYPTION  
     */
    for (j = 1; j < 6; ++j) {
        
        // Inverse AddRoundKey
        for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
            *(tmp+i) = *(plaintext+i) ^ *(aeskeys+i);
        }
        
        /*
         * Inverse MixColumns
         * [0e 0b 0d 09]   [s0  s4  s8  s12]
         * [09 0e 0b 0d] . [s1  s5  s9  s13]
         * [0d 09 0e 0b]   [s2  s6  s10 s14]
         * [0b 0d 09 0e]   [s3  s7  s11 s15]
         */
        for (i = 0; i < AES_BLOCK_SIZE; i+=4) {
            t = tmp[i] ^ tmp[i+1] ^ tmp[i+2] ^ tmp[i+3];
            plaintext[i]   = t ^ tmp[i]   ^ mul2(tmp[i]   ^ tmp[i+1]);
            plaintext[i+1] = t ^ tmp[i+1] ^ mul2(tmp[i+1] ^ tmp[i+2]);
            plaintext[i+2] = t ^ tmp[i+2] ^ mul2(tmp[i+2] ^ tmp[i+3]);
            plaintext[i+3] = t ^ tmp[i+3] ^ mul2(tmp[i+3] ^ tmp[i]);
            u = mul2(mul2(tmp[i]   ^ tmp[i+2]));
            v = mul2(mul2(tmp[i+1] ^ tmp[i+3]));
            t = mul2(u ^ v);
            plaintext[i]   ^= t ^ u;
            plaintext[i+1] ^= t ^ v;
            plaintext[i+2] ^= t ^ u;
            plaintext[i+3] ^= t ^ v;
        }
        
        // Inverse ShiftRows
        inv_shift_rows(plaintext);
        
        // Inverse SubBytes
        for (i = 0; i < AES_BLOCK_SIZE; ++i) {
            *(plaintext+i) = INV_SBOX[*(plaintext+i)];
        }

        aeskeys -= 16;
    }

    // last AddRoundKey
    for ( i = 0; i < AES_BLOCK_SIZE; ++i ) {
        *(plaintext+i) ^= *(aeskeys+i);
    }

    printf("\n\nFinal Decrypted Message After 10 AES and 4 Feistel Rounds:\n");
	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		printf("%2x ", ciphertext[i]);
	}
}

int main(int argc, char *argv[]) {

	uint8_t i, r;

	// 128 bit key 
	uint8_t key[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
	};

	// 128 bit plain text
	uint8_t plaintext[] = {
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
	};

 	uint8_t ciphertext[AES_BLOCK_SIZE];
	
	uint8_t aeskeys[AES_ROUND_KEY_SIZE];
	uint8_t feistelkeys[FEISTEL_KEY_SIZE];

	printf("\n-------- WELCOME TO AES-FEISTEL BLOCK CIPHER EXAMPLE --------\n");

	// Scheduling, storing and printing keys 
	key_schedule(key, aeskeys, feistelkeys);

    // Printing AES round keys 
	printf("\nAES Round Keys:\n");
	for ( r = 0; r <= AES_ROUNDS; r++ ) {
        printf("Key %d: ", r+1);
        if(r<9) printf(" ");
		for (i = 0; i < AES_BLOCK_SIZE; i++) {
			printf("%2x ",aeskeys[r*AES_BLOCK_SIZE+i]);
		}
		printf("\n");
	}
	printf("\n");

    // Printing feistel round keys 
    printf("Feistel Round Keys:\n");
	for ( r = 0; r < 4; r++ ) {
        printf("Key %d: ", r+1);
        if(r<9) printf(" ");
		for (i = 0; i < FEISTEL_BLOCK_SIZE; i++) {
			printf("%2x ",feistelkeys[r*FEISTEL_BLOCK_SIZE+i]);
		}
		printf("\n");
	}
	printf("\n");

    // Encryption process
	block_encrypt(aeskeys, feistelkeys, ciphertext, plaintext);
	
    // Decryption process
    block_decrypt(aeskeys, feistelkeys, ciphertext, ciphertext);

    printf("\n\n------------------------- THANK YOU -------------------------\n\n");
	
    return 0;
}
