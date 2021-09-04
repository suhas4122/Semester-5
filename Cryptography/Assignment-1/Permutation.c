// Permutation Cipher
#include <stdio.h>
#include <string.h>
#define CAPACITY 100

void encrypt(char *pt, int *key, int m, char *et);
void decrypt(char *et, int *key, int m, char *pt);

int main(){
    char pt[CAPACITY];
    printf("Enter the message to be encrypted : ");
    scanf("%[^\n]", pt);
    int m = strlen(pt);
    int key[m];
    printf("Enter a space seperated permutation of numbers from 1 to %d : ", m);
    for (int i = 0; i < m; i++){
        scanf("%d", &key[i]);
    }
    char et[CAPACITY];
    encrypt(pt, key, m, et);
    printf("Encrypted message: %s \n", et);
    char dt[CAPACITY];
    decrypt(et, key, m, dt);
    printf("Decrypted message: %s \n", dt);
}

void encrypt(char *pt, int *key, int m, char *et){
    int len = 0;
    while (pt[len] != '\0') len++;
    int j = 0;
    for (int i = 0; i < len; i += m){
        for (int j = 0; j < m; j++){
            int tmp = key[j] - 1;
            if (i + j < len) et[i + tmp] = pt[i + j];
            else et[i + tmp] = 'z';
        }
    }
}

void decrypt(char *et, int *key, int m, char *pt){
    int ik[m];
    for (int i = 0; i < m; i++){
        ik[key[i] - 1] = i + 1;
    }
    encrypt(et, ik, m, pt);
    pt[m] = '\0';
}