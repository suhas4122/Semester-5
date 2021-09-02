// Substitution Permutation Network
#include <stdio.h>
#include <stdlib.h>
#define R 4        
#define BIT 16      
#define L 4         
#define LS 16       
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef uint16_t uint16_t;


uint32_t key = 0x3214F63F;
uint16_t s[LS] = {14,4,13,1,2,15,11,3,8,10,6,12,5,9,0,7};
uint16_t s_in[LS] =  {14,3,4,7,1,12,10,15,8,13,9,6,11,2,0,5};

uint16_t sbox(uint16_t c){
    uint16_t s_cipher = 0;
    uint16_t mask = 0xf;
    uint16_t m;         
    int i = 1;
    for(i = 1;i <= (BIT/L);i++){
        m = (c >> (BIT - (i*4))) & mask;
        s_cipher = (s[m] << (BIT - (i*4))) | s_cipher;
    }
    return s_cipher;
}

uint16_t sbox_inv(uint16_t c){
    uint16_t s_cipher = 0;
    uint16_t mask = 0xf;
    uint16_t m;         
    int i = 1;
    for(i = 1;i <= (BIT/L);i++){
        m = (c >> (BIT - (i*4))) & mask;
        s_cipher = (s_in[m] << (BIT - (i*4))) | s_cipher;
    }
    return s_cipher;
}

uint16_t pbox(uint16_t c){
    uint16_t v1, v2, v3, v4, v5, v6, v7;
    v1 = c & 0x8421;
    v2 = c & 0x4210;
    v3 = c & 0x0842;
    v4 = c & 0x2100;
    v5 = c & 0x0084;
    v6 = c & 0x1000;
    v7 = c & 0x0008;
    return v1 | (v2 >> 3) | (v3 << 3) | (v4 >> 6) | (v5 << 6) | (v6 >> 9) | (v7 << 9);
}

uint16_t key_schedule(int i){
    uint16_t k = key >> (BIT - (i*4));
    return k;
}

uint16_t spn_encrypt(uint16_t plain){
    uint16_t middle = plain;    
    int i = 0;
    for(i = 0;i < R-1 ;i++){
        middle = middle ^ key_schedule(i);
        middle = sbox(middle);
        middle = pbox(middle);
    }
    middle = middle ^ key_schedule(i++);
    middle = sbox(middle);
    return middle ^ key_schedule(i);
}

uint16_t spn_decrypt(uint16_t cipher){
    uint16_t middle = cipher;
    middle = middle ^ key_schedule(R);
    middle = sbox_inv(middle);
    int i;
    for(i = R - 1; i > 0 ; i--){
        middle = middle ^ key_schedule(i);
        middle = pbox(middle);
        middle = sbox_inv(middle);
    }
    return middle ^ key_schedule(0);
}

int main(void){
    uint16_t cipher = 0x0000;         
    uint16_t plain = 0x26b7;          
    printf("Plain text is: %0x\n",plain);
    cipher = spn_encrypt(plain);
    printf("Encrypted String: %0x\n",cipher);
    plain = spn_decrypt(cipher);
    printf("Decrypted String: %0x\n",plain);
    return 0;
}