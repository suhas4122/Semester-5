// Substitution Cipher
#include <stdio.h>
#define MAXIMUM 100

void encrypt(char *pt, char *et);
void decrypt(char *et, char *pt);

char key1 [] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
char key2 [] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
char forSpace = '#';

int main(){
    char pt[MAXIMUM];
    printf("Enter the message text to be encrypted (any string) : ");
    scanf("%[^\n]", pt);
    printf("Using default key (can be changed in code)\n");
    char et[MAXIMUM];
    encrypt(pt, et);
    printf("Encrypted String: %s \n", et);
    char dt[MAXIMUM];
    decrypt(et, dt);
    printf("Decrypted string: %s \n", dt);
}

void encrypt(char *pt, char *et){
    int i = 0;
    while (pt[i] != '\0'){
        if(pt[i] >= 'a' && pt[i] <= 'z')
            et[i++] = key1[pt[i] - 'a'];
        else if(pt[i] >= 'A' && pt[i] <= 'Z')
            et[i++] = key2[pt[i] - 'A'];
        else
            et[i++] = forSpace;
    }
    et[i++] = '\0';
} 

void decrypt(char *et, char *pt){
    char key_inv1[26];
    char key_inv2[26];
    for (int i=0;i<26;i++){
        key_inv1[key1[i] - 'a'] = (char)('a' + i);
        key_inv2[key2[i] - 'A'] = (char)('A' + i);
    }
    int i = 0;
    while (et[i] != '\0'){
        if(et[i] >= 'a' && et[i] <= 'z')
            pt[i++] = key_inv1[et[i] - 'a'];
        else if((et[i] >= 'A' && et[i] <= 'Z'))
            pt[i++] = key_inv2[et[i] - 'A'];
        else
            pt[i++] = ' ';
    }
    pt[i++] = '\0';
}

