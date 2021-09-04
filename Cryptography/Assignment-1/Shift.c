// Shift Cipher
#include <stdio.h>
#define MAXIMUM 100

void encrypt(char *pt, int key, char *et);
void decrypt(char *et, int key, char *pt);

int main(){
    char pt[MAXIMUM];
    printf("Enter the message to be encrypted (any string) : ");
    scanf("%[^\n]", pt);
    int key;
    printf("Enter the key (any non-zero integer) : ");
    scanf("%d", &key);
    char et[MAXIMUM];
    encrypt(pt, key, et);
    printf("Encrypted String : %s \n", et);
    char dt[MAXIMUM];
    decrypt(et, key, dt);
    printf("Decrypted string : %s \n", dt);
}

void encrypt(char *pt, int key, char *et){
    int i = 0;
    while (pt[i] != '\0'){
        if(pt[i] >= 'a' && pt[i] <= 'z'){
            int tmp = ((((int)pt[i]) + key - (int)('a'))%26);
            et[i++] = (char)(tmp + 'a');
        }else if(pt[i] >= 'A' && pt[i] <= 'Z'){
            int tmp = ((((int)pt[i]) + key - (int)('A'))%26);
            et[i++] = (char)(tmp + 'A');
        }else{
            et[i++] = pt[i] + key;
        }
    }
    et[i++] = '\0';
}

void decrypt(char *et, int key, char *pt){
    int i = 0;
    while (et[i] != '\0'){
        if(et[i] >= 'a' && et[i] <= 'z'){
            int tmp = (((((int)et[i]) - key - (int)('a'))%26) + 26)%26;
            pt[i++] = (char)(tmp + 'a');
        }else if(et[i] >= 'A' && et[i] <= 'Z'){
            int tmp = (((((int)et[i]) - key - (int)('A'))%26) + 26)%26;
            pt[i++] = (char)(tmp + 'A');
        }else{
            pt[i++] = et[i] - key;
        }
    }
    pt[i++] = '\0';
}