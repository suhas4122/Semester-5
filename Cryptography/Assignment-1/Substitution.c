// Substitution Cipher
#include <stdio.h>
#define CAPACITY 100

void substitution_encrypt(char *plainTxt, char *key, char *encypTxt){
    int i = 0;
    while (plainTxt[i] != '\0'){
        encypTxt[i++] = key[plainTxt[i] - 'a'];
    }
    encypTxt[i++] = '\0';
} 

void substitution_decrypt(char *encrypTxt, char *key, char *plainTxt){
    char key_inv[26];
    for (int i=0;i<26;i++){
        key_inv[key[i] - 'a'] = (char)('a' + i);
    }
    int i = 0;
    while (encrypTxt[i] != '\0'){
        plainTxt[i++] = key_inv[encrypTxt[i] - 'a'];
    }
    plainTxt[i++] = '\0';
}

int main(){
    char plainTxt[CAPACITY];
    printf("Enter the plain text to be encrypted: \n");
    scanf("%s", plainTxt);
    char key[CAPACITY];
    printf("Enter the key: \n");
    scanf("%s", key);
    char encrypTxt[CAPACITY];
    substitution_encrypt(plainTxt, key, encrypTxt);
    printf("Encrypted String: %s \n", encrypTxt);
    char decryptTxt[CAPACITY];
    substitution_decrypt(encrypTxt, key, decryptTxt);
    printf("Decrypted string: %s \n", decryptTxt);
}