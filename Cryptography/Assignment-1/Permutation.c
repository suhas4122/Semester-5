// Permutation Cipher
#include <stdio.h>
#define CAPACITY 100

void permutation_encrypt(char *plainTxt, int *key, int m, char *encyptTxt){
    int txt_len = 0;
    while (plainTxt[txt_len] != '\0') txt_len++;
    int j = 0;
    for (int i=0;i<txt_len;i+=m){
        for (int j=0;j<m;j++){
            int tmp = key[j] - 1;
            if (i+j<txt_len) encyptTxt[i + tmp] = plainTxt[i + j];
            else encyptTxt[i + tmp] = 'z';
        }
    }
}

void permutation_decrypt(char *encrypTxt, int *key, int m, char *plainTxt){
    int inv_key[m];
    for (int i=0;i<m;i++){
        inv_key[key[i] - 1] = i+1;
    }
    permutation_encrypt(encrypTxt, inv_key, m, plainTxt);
}

int main(){
    char plainTxt[CAPACITY];
    printf("Enter the plain text to be encrypted: \n");
    scanf("%s", plainTxt);
    int m;
    printf("Enter length of key array: \n");
    scanf("%d", &m);
    int key[CAPACITY];
    for (int i=0;i<m;i++){
        printf("Enter the array number: \n");
        scanf("%d", &key[i]);
    }
    char encrypTxt[CAPACITY];
    permutation_encrypt(plainTxt, key, m, encrypTxt);
    printf("Encrypted String: %s \n", encrypTxt);
    char decryptTxt[CAPACITY];
    permutation_decrypt(encrypTxt, key, m, decryptTxt);
    printf("Decrypted string: %s \n", decryptTxt);
}