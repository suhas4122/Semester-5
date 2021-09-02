// Shift Cipher
#include <stdio.h>
#define CAPACITY 100

void shift_encrypt(char *plainTxt, int key, char *encrypTxt){
    int i = 0;
    while (plainTxt[i] != '\0'){
        int tmp = ((((int)plainTxt[i]) + key - (int)('a'))%26);
        encrypTxt[i++] = (char)(tmp + 'a');
    }
    encrypTxt[i++] = '\0';
}

void shift_decrypt(char *encrypTxt, int key, char *plainTxt){
    int i = 0;
    while (encrypTxt[i] != '\0'){
        int tmp = (((((int)encrypTxt[i]) - key - (int)('a'))%26) + 26)%26;
        plainTxt[i++] = (char)(tmp + 'a');
    }
    plainTxt[i++] = '\0';
}

int main(){
    char plainTxt[CAPACITY];
    printf("Enter the plain text to be encrypted: \n");
    scanf("%s", plainTxt);
    int key;
    printf("Enter the key: \n");
    scanf("%d", &key);
    char encrypTxt[CAPACITY];
    shift_encrypt(plainTxt, key, encrypTxt);
    printf("Encrypted String: %s \n", encrypTxt);
    char decryptTxt[CAPACITY];
    shift_decrypt(encrypTxt, key, decryptTxt);
    printf("Decrypted string: %s \n", decryptTxt);
}