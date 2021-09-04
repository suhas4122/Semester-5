// Vignere Cipher
#include <stdio.h>
#define MAXIMUM 100

void encrypt(char *pt, char *key, char *et){
    int key_len = 0, i = 0;
    while (key[key_len] != '\0') key_len++;
    i = 0;
    int j = 0;
    while (pt[i] != '\0'){
        int tmp = ((((int)pt[i] + (int)key[(j++)%key_len] - 2*(int)('a'))%26) + 26)%26;
        et[i++] = (char)('a' + tmp);
    }
    et[i++] = '\0';
}

void vignere_decrypt(char *et, char *key, char *pt){
    int key_len = 0, i = 0;
    while (key[key_len] != '\0') key_len++;
    i = 0;
    int j = 0;
    while (et[i] != '\0'){
        int tmp = ((((int)et[i] - (int)key[(j++)%key_len])%26) + 26)%26;
        pt[i++] = (char)('a' + tmp);
    }
    pt[i++] = '\0';
}

int main(){
    char pt[MAXIMUM];
    printf("Enter the message text to be encrypted: ");
    scanf("%s", pt);
    char key[MAXIMUM];
    printf("Enter the key (any string) : ");
    scanf("%s", key);
    char et[MAXIMUM];
    encrypt(pt, key, et);
    printf("Encrypted String: %s \n", et);
    char dt[MAXIMUM];
    vignere_decrypt(et, key, dt);
    printf("Decrypted string: %s \n", dt);
}