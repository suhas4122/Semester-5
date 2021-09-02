// Playfair Cipher
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

void getKeyMat(char *key, char **keyMat){
    int alphabets[26];
    for (int i=0;i<26;i++) alphabets[i] = 0;
    int i = 0, j = 0, k = 0;
    while (key[k] != '\0'){
        keyMat[j][i] = key[k];
        alphabets[key[k] - 'a'] = 1;
        if (i == 4){
            i = 0;
            if (j == 4) return;
            else j++;
        }
        else i++;
        k++;
    }

    for (int c = 0;c<26;c++){
        if (!alphabets[c] && (c != ('j' - 'a'))){
            if (alphabets['j' - 'a'] && (c == 'i' - 'a')) continue;
            keyMat[j][i] = (char)('a' + c);
            alphabets[c] = 1;
            if (i == 4){
                i = 0;
                if (j == 4) return;
                else j++;
            }
            else i++;
        }
    }
}

void findCell(char **keyMat, char c, int *p){
    int found = 0;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if (keyMat[i][j] == c){
                p[0] = i;
                p[1] = j;
                found = 1;
                break;
            }
        }
    }
    if (!found){
        p[0] = -1;
        p[1] = -1;
    }
}

void playfair_encrypt(char *plainTxt, char *key, char *encrypTxt){
    char **keyMat = (char **)malloc(5*sizeof(char *));
    for (int i=0;i<5;i++){
        keyMat[i] = (char *)malloc(5*sizeof(char));
    }
    getKeyMat(key, keyMat);
    int jPresent = 0;
    int jp[2];
    findCell(keyMat, 'j', jp);
    if (jp[0] > -1) jPresent = 1;

    int i = 0;
    while (plainTxt[i] != '\0'){
        if (jPresent){
            if (plainTxt[i] == 'i') plainTxt[i] = 'j';
        }
        else{
            if (plainTxt[i] == 'j') plainTxt[i] = 'i';
        }
        i++;
    }

    int txt_len = i;
    int j = 0;
    for (int i=0;i<txt_len;i+=2){
        char a, b;
        a = plainTxt[i];
        if (i+1 == txt_len) b = 'x';
        else b = plainTxt[i+1];

        int pa[2], pb[2];
        findCell(keyMat, a, pa);
        findCell(keyMat, b, pb);

        if (pa[0] == pb[0]){
            int tmp = (((pa[1]-1)%5) + 5)%5;
            encrypTxt[j++] = keyMat[pa[0]][tmp];
            tmp = (((pb[1]-1)%5) + 5)%5;
            encrypTxt[j++] = keyMat[pb[0]][tmp];
        }
        else if (pa[1] == pb[1]){
            int tmp = (((pa[0]+1)%5) + 5)%5;
            encrypTxt[j++] = keyMat[tmp][pa[1]];
            tmp = (((pb[0]+1)%5) + 5)%5;
            encrypTxt[j++] = keyMat[tmp][pb[1]];
        }
        else{
            encrypTxt[j++] = keyMat[pa[0]][pb[1]];
            encrypTxt[j++] = keyMat[pb[0]][pa[1]];
        }
    }
    encrypTxt[j++] = '\0';
}

void playfair_decrypt(char *encrypTxt, char *key, char *plainTxt){
    char **keyMat = (char **)malloc(5*sizeof(char *));
    for (int i=0;i<5;i++){
        keyMat[i] = (char *)malloc(5*sizeof(char));
    }
    getKeyMat(key, keyMat);
    int jPresent = 0;
    int jp[2];
    findCell(keyMat, 'j', jp);
    if (jp[0] > -1) jPresent = 1;

    int i = 0;
    while (encrypTxt[i] != '\0'){
        if (jPresent){
            if (encrypTxt[i] == 'i') encrypTxt[i] = 'j';
        }
        else{
            if (encrypTxt[i] == 'j') encrypTxt[i] = 'i';
        }
        i++;
    }

    int txt_len = i;
    int j = 0;
    for (int i=0;i<txt_len;i+=2){
        char a, b;
        a = encrypTxt[i];
        if (i+1 == txt_len) b = 'x';
        else b = encrypTxt[i+1];

        int pa[2], pb[2];
        findCell(keyMat, a, pa);
        findCell(keyMat, b, pb);

        if (pa[0] == pb[0]){
            int tmp = (((pa[1]+1)%5) + 5)%5;
            plainTxt[j++] = keyMat[pa[0]][tmp];
            tmp = (((pb[1]+1)%5) + 5)%5;
            plainTxt[j++] = keyMat[pb[0]][tmp];
        }
        else if (pa[1] == pb[1]){
            int tmp = (((pa[0]-1)%5) + 5)%5;
            plainTxt[j++] = keyMat[tmp][pa[1]];
            tmp = (((pb[0]-1)%5) + 5)%5;
            plainTxt[j++] = keyMat[tmp][pb[1]];
        }
        else{
            plainTxt[j++] = keyMat[pa[0]][pb[1]];
            plainTxt[j++] = keyMat[pb[0]][pa[1]];
        }
    }
    plainTxt[j++] = '\0';
}

int main(){
    char plainTxt[CAPACITY];
    printf("Enter the plain text to be encrypted: \n");
    scanf("%s", plainTxt);
    char key[CAPACITY];
    printf("Enter the key: \n");
    scanf("%s", key);
    char encrypTxt[CAPACITY];
    playfair_encrypt(plainTxt, key, encrypTxt);
    printf("Encrypted String: %s \n", encrypTxt);
    char decryptTxt[CAPACITY];
    playfair_decrypt(encrypTxt, key, decryptTxt);
    printf("Decrypted string: %s \n", decryptTxt);
}