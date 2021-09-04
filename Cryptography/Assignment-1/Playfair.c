// Playfair Cipher
#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM 100

void findInMatrix(char c, int *p);
void encrypt(char *pt, char *key, char *et);
void decrypt(char *et, char *key, char *pt);
char matrix[5][5];

int main(){
    char pt[MAXIMUM];
    printf("Enter the plain text to be encrypted (any lowercase string) : ");
    scanf("%s", pt);
    char key[MAXIMUM];
    printf("Enter the key (any lowercase string) : ");
    scanf("%s", key);
    int alphabets[26];
    for (int i = 0; i < 26; i++) alphabets[i] = 0;
    int i = 0, j = 0, k = 0;
    int flag = 0;
    while (key[k] != '\0'){
        matrix[j][i] = key[k];
        alphabets[key[k] - 'a'] = 1;
        if (i == 4){
            i = 0;
            if (j == 4){
                flag = 1;
                break;
            }
            else j++;
        }
        else i++;
        k++;
    }
    if(flag == 0){
        for (int c = 0; c < 26; c++){
            if (!alphabets[c] && (c != ('j' - 'a'))){
                if (alphabets['j' - 'a'] && (c == 'i' - 'a')) continue;
                matrix[j][i] = (char)('a' + c);
                alphabets[c] = 1;
                if (i == 4){
                    i = 0;
                    if (j == 4) 
                        break;
                    else j++;
                }
                else i++;
            }
        }
    }
    char et[MAXIMUM];
    encrypt(pt, key, et);
    printf("Encrypted String : %s \n", et);
    char dt[MAXIMUM];
    decrypt(et, key, dt);
    printf("Decrypted string : %s \n", dt);
}

void findInMatrix(char c, int *p){
    int flag = 0;
    for (int i = 0; i < 5; i++){
        for (int j=0;j<5;j++){
            if (matrix[i][j] == c){
                p[0] = i;
                p[1] = j;
                flag = 1;
                break;
            }
        }
    }
    if (!flag){
        p[0] = -1;
        p[1] = -1;
    }
}

void encrypt(char *pt, char *key, char *et){
    int isj = 0;
    int jp[2];
    findInMatrix('j', jp);
    if (jp[0] > -1) isj = 1;
    int i = 0;
    while (pt[i] != '\0'){
        if (isj){
            if (pt[i] == 'i') pt[i] = 'j';
        }
        else{
            if (pt[i] == 'j') pt[i] = 'i';
        }
        i++;
    }
    int length = i;
    int j = 0;
    for (int i=0;i<length;i+=2){
        char a, b;
        a = pt[i];
        if (i+1 == length) b = 'x';
        else b = pt[i+1];
        int pa[2], pb[2];
        findInMatrix(a, pa);
        findInMatrix(b, pb);
        if (pa[0] == pb[0]){
            int temp = (((pa[1]-1)%5) + 5)%5;
            et[j++] = matrix[pa[0]][temp];
            temp = (((pb[1]-1)%5) + 5)%5;
            et[j++] = matrix[pb[0]][temp];
        }
        else if (pa[1] == pb[1]){
            int temp = (((pa[0]+1)%5) + 5)%5;
            et[j++] = matrix[temp][pa[1]];
            temp = (((pb[0]+1)%5) + 5)%5;
            et[j++] = matrix[temp][pb[1]];
        }
        else{
            et[j++] = matrix[pa[0]][pb[1]];
            et[j++] = matrix[pb[0]][pa[1]];
        }
    }
    et[j++] = '\0';
}

void decrypt(char *et, char *key, char *pt){
    int isj = 0;
    int jp[2];
    findInMatrix('j', jp);
    if (jp[0] > -1) isj = 1;
    int i = 0;
    while (et[i] != '\0'){
        if (isj){
            if (et[i] == 'i') et[i] = 'j';
        }
        else{
            if (et[i] == 'j') et[i] = 'i';
        }
        i++;
    }
    int length = i;
    int j = 0;
    for (int i = 0; i < length; i += 2){
        char a, b;
        a = et[i];
        if (i+1 == length) b = 'x';
        else b = et[i+1];
        int pa[2], pb[2];
        findInMatrix(a, pa);
        findInMatrix(b, pb);
        if (pa[0] == pb[0]){
            int temp = (((pa[1]+1)%5) + 5)%5;
            pt[j++] = matrix[pa[0]][temp];
            temp = (((pb[1]+1)%5) + 5)%5;
            pt[j++] = matrix[pb[0]][temp];
        }
        else if (pa[1] == pb[1]){
            int temp = (((pa[0]-1)%5) + 5)%5;
            pt[j++] = matrix[temp][pa[1]];
            temp = (((pb[0]-1)%5) + 5)%5;
            pt[j++] = matrix[temp][pb[1]];
        }
        else{
            pt[j++] = matrix[pa[0]][pb[1]];
            pt[j++] = matrix[pb[0]][pa[1]];
        }
    }
    pt[j++] = '\0';
}
