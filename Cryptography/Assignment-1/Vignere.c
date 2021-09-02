// Vignere Cipher
#include <stdio.h>
#define CAPACITY 100

void vignere_encrypt(char *plainTxt, char *key, char *encrypTxt){
    int key_len = 0, i = 0;
    while (key[key_len] != '\0') key_len++;
    i = 0;
    int j = 0;
    while (plainTxt[i] != '\0'){
        int tmp = ((((int)plainTxt[i] + (int)key[(j++)%key_len] - 2*(int)('a'))%26) + 26)%26;
        encrypTxt[i++] = (char)('a' + tmp);
    }
    encrypTxt[i++] = '\0';
}

void vignere_decrypt(char *encrypTxt, char *key, char *plainTxt){
    int key_len = 0, i = 0;
    while (key[key_len] != '\0') key_len++;
    i = 0;
    int j = 0;
    while (encrypTxt[i] != '\0'){
        int tmp = ((((int)encrypTxt[i] - (int)key[(j++)%key_len])%26) + 26)%26;
        plainTxt[i++] = (char)('a' + tmp);
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
    vignere_encrypt(plainTxt, key, encrypTxt);
    printf("Encrypted String: %s \n", encrypTxt);
    char decryptTxt[CAPACITY];
    vignere_decrypt(encrypTxt, key, decryptTxt);
    printf("Decrypted string: %s \n", decryptTxt);
}