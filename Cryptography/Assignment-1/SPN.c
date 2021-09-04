// Substitution Permutation Network
#include <stdio.h>
#include <stdlib.h>  

const int key = 840234559;
const int s[16] = {14,4,13,1,2,15,11,3,8,10,6,12,5,9,0,7};
const int s_in[16] =  {14,3,4,7,1,12,10,15,8,13,9,6,11,2,0,5};

int sbox(int c, int inv);
int pbox(int c);
int key_schedule(int i);
int decrypt(int cp);
int encrypt(int cp);

int main(void){
    int cp, pt = 0x26b7;          
    printf("Using default plaintext and key (can be changed in code)\nPlain Text (HEX Code) : %0x\n", pt);
    cp = encrypt(pt);
    printf("Encrypted String (HEX Code) : %0x\n", cp);
    pt = decrypt(cp);
    printf("Decrypted String (HEX Code) : %0x\n", pt);
    return 0;
}

int sbox(int c, int inv){
    int s_cp = 0;
    int mask = 0xf;
    int m;         
    int i = 1;
    if(inv == 0){
        for(i = 1; i <= (16/4); i++){
            m = (c >> (16 - (i*4))) & mask;
            s_cp = (s[m] << (16 - (i*4))) | s_cp;
        }
    }else{
        for(i = 1; i <= (16/4); i++){
            m = (c >> (16 - (i*4))) & mask;
            s_cp = (s_in[m] << (16 - (i*4))) | s_cp;
        }
    }
    return s_cp;
}

int pbox(int c){
    return (c & 33825) | ((c & 16912) >> 3) | ((c & 2114) << 3) | ((c & 8448) >> 6) | ((c & 132) << 6) | ((c & 4096) >> 9) | ((c & 8) << 9);
}

int key_schedule(int i){
    int k = key >> (16 - (i*4));
    return k;
}

int encrypt(int pt){
    int mid = pt;    
    int i = 0;
    for(i = 0; i < 3; i++){
        mid = mid ^ key_schedule(i);
        mid = sbox(mid, 0);
        mid = pbox(mid);
    }
    mid = mid ^ key_schedule(i++);
    mid = sbox(mid, 0);
    return mid ^ key_schedule(i);
}

int decrypt(int cp){
    int mid = cp;
    mid = mid ^ key_schedule(4);
    mid = sbox(mid, 1);
    int i;
    for(i = 3; i > 0 ; i--){
        mid = mid ^ key_schedule(i);
        mid = pbox(mid);
        mid = sbox(mid, 1);
    }
    return mid ^ key_schedule(0);
}