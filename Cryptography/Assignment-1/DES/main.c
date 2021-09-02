#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Permutation tables
int Ip[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7
};

int Ipinv[64] = {
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25
};

// Key scheduling tables
int left[28] = {
   57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
   10,  2, 59, 51, 43, 35, 27,
   19, 11,  3, 60, 52, 44, 36
};

int right[28] = {
   63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
   14,  6, 61, 53, 45, 37, 29,
   21, 13,  5, 28, 20, 12,  4
};

int pc2[48] = {
   14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
   23, 19, 12,  4, 26,  8,
   16,  7, 27, 20, 13,  2,
   41, 52, 31, 37, 47, 55,
   30, 40, 51, 45, 33, 48,
   44, 49, 39, 56, 34, 53,
   46, 42, 50, 36, 29, 32
};

int Rotations[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

// Round tables
int E[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,
     6,  7,  8,  9,  8,  9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32,  1
}; 

// DES Sboxes
int S[8][4][16] = {
   {
   {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
   { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
   { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
   {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
   },
 
   {
   {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
   { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
   { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
   {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
   },
 
   {
   {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
   {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
   {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
   { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
   },
 
   {
   { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
   {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
   {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
   { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
   },
 
   {
   { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
   {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
   { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
   {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
   },
 
   {
   {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
   {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
   { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
   { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
   },
 
   {
   { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
   {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
   { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
   { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
   },
 
   {
   {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
   { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
   { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
   { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
   },
};

int P[32] = {
    16,  7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26,  5, 18, 31, 10,
     2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25
};


// Function to convert a binary number to decimal number 
int bin2dec(int A[], int n){
	int pos = n-1;
	int m = 0;
	int num = 0;
	while(pos>=0){
		num += (A[pos] << m);
		pos--;
		m++;
	}
	return num;
}

// Function to convert a decimal number to binary number 
void dec2bin(int n,int *size,int A[]){
	int i = 0;
	while(n!=0){
		A[i++] = n%2;
		n /= 2;
	}

	int begin = 0, end = i-1;
	*size = end+1;
	int temp;
	while(begin<end){
		temp = A[begin];
		A[begin++] = A[end];
		A[end--] = temp;
	}
}

// Function that performs operations for each half of the 64-bit number
void f(int A[],int J[],int Res[]){

	int EA[48];

	//expanding A from 32 bits to 48 bits using E --> EA
	for(int i=0;i<48;i++){
		EA[i] = A[E[i]-1];
	}

	int ind;
	int EAxorJ[8][6];
	for(int i=0;i<8;i++){
		for(int j=0;j<6;j++){
			ind = (6*i+j);
			EAxorJ[i][j] = EA[ind]^J[ind];
		}
	}

	//getting array C of 32 bits from ExorJ of 48 bits using S
	int C[8][4];

	for(int i=0;i<8;i++){
		//use S[i] to get C[i] from EAxorJ[i]
		int temp[2];
		temp[0] = EAxorJ[i][0];
		temp[1] = EAxorJ[i][5];
		int row = bin2dec(temp,2);
		int temp2[4];
		for(int j=1;j<=4;j++){
			temp2[j-1] = EAxorJ[i][j];
		}
		int col = bin2dec(temp2,4);
        // printf("%d, %d", row, col);
		int val = S[i][row][col];
		int size;
		int tmp[10];
		dec2bin(val,&size,tmp);
		int k = 0;
		if(size<4){
			int t = 4 - size;
			for(;k<t;k++){
				C[i][k] = 0;
			}
		}
		for(int l = 0;l<size;k++,l++){
			C[i][k] = tmp[l]; 
		}
	}

	//permuting the 32 bit array C to obtain res
	int index;
	for(int i=0;i<32;i++){
		index = P[i]-1;
		Res[i] = C[index/4][index%4];
	}
}

void IP(int P[]){
	int temp[64];
	for(int i=0;i<64;i++){
		temp[i] = P[Ip[i]-1];
	} 

	for(int i=0;i<64;i++){
		P[i] = temp[i];
	}
}

void IPinv(int C[]){
	int temp[64];
	for(int i=0;i<64;i++){
		temp[i] = C[Ipinv[i]-1];
	} 

	for(int i=0;i<64;i++){
		C[i] = temp[i];
	}
}

void PC1(int K[],int LKey[],int RKey[]){
	for(int i=0;i<28;i++){
		LKey[i] = K[left[i]-1];
	}

	for(int i=0;i<28;i++){
		RKey[i] = K[right[i]-1];
	}
}

void PC2(int K[], int roundKey[]){
	for(int i=0;i<48;i++){
		roundKey[i] = K[pc2[i]-1];
	}
}

void leftRotate(int A[],int Siz, int r){
	int* temp;
	temp = (int*)malloc(r*sizeof(int));
	int i;

	for(i=0;i<r;i++){
		temp[i] = A[i];
	}

	for(;i<Siz;i++){
		A[i-r]=A[i];
	}

	i=Siz-r;
	for(;i<Siz;i++){
		A[i] = temp[i-Siz+r];
	}
}

void encrypt(int P[],int K[],int C[]){
	//P and K are 64 bit long
	IP(P);
	int LKey[28];
	int RKey[28];
	PC1(K,LKey,RKey);
	int Rounds[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	int temp[56],roundKey[48],leftPart[32],rightPart[32];
	
	for(int i=0;i<32;i++){
		leftPart[i] = P[i];
		rightPart[i] = P[i+32];
	}

	int fRes[32],temporary;
	for(int i=0;i<16;i++){
		leftRotate(LKey,28,Rounds[i]);
		leftRotate(RKey,28,Rounds[i]);
		for(int j=0;j<28;j++){
			temp[j] = LKey[j];
			temp[j+28] = RKey[j];
		}
		PC2(temp,roundKey);
		f(rightPart,roundKey,fRes);
		for(int j=0;j<32;j++){
			temporary = leftPart[j];
			leftPart[j] = rightPart[j];
			rightPart[j] = temporary ^ (fRes[j]);
		}			
	}

	for(int j=0;j<32;j++){
		C[j] = rightPart[j];
		C[j+32] = leftPart[j];
	}	
	IPinv(C);
}

void decrypt(int C[],int K[],int P[]){
	//C and K are 64 bit long
	int LKey[28];
	int RKey[28];
	PC1(K,LKey,RKey);
	int Rounds[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	int roundKey[16][48],temp[56];
	
	for(int i=0;i<16;i++){
		leftRotate(LKey,28,Rounds[i]);
		leftRotate(RKey,28,Rounds[i]);
		for(int j=0;j<28;j++){
			temp[j] = LKey[j];
			temp[j+28] = RKey[j];
		}
		PC2(temp,roundKey[i]);
	}
	
	IP(C);
	int leftPart[32], rightPart[32], temporary, fRes[32];

	for(int j=0;j<32;j++){
		rightPart[j] = C[j];
		leftPart[j] = C[j+32];
	}	

	for (int i = 15; i >=0; --i){	
		f(leftPart,roundKey[i],fRes);
		for(int j=0;j<32;j++){
			temporary = rightPart[j];
			rightPart[j] = leftPart[j];
			leftPart[j] = temporary ^ fRes[j]; 
		}	
	}

	for(int i=0;i<32;i++){
		P[i] = leftPart[i];
		P[i+32] = rightPart[i];
	}

	IPinv(P);
}

void ascii2bin(char c,int res[]){
	int i = 0, temp[8];
	int n = (int)(c);

	while(n){
		temp[i] = n%2;
		n /= 2;
		if(n)i++;
	}

	while(i<8){
		temp[++i] = 0;
	}

	int k = 7;
	i = 0;
	while(k>=0){
		res[k--] = temp[i++];
	}

}

void copyString(char* target, char *original, int from, int to){
    for (int i = from; i <= to; i++) {
        target[i - from] = original[i];
    }
}

char* concatenateString(char* target, char *original, int originalLength){
    int nullIndex = 0;
    for (int i = 0; target[i] != '\0'; i++) {
        nullIndex++;
    }

    char *ch = malloc((nullIndex+originalLength+1)*sizeof(char));
    for (int i = 0; target[i] != '\0'; i++)
        ch[i] = target[i];

    for (int i = 0; original[i] != '\0'; i++)
        ch[nullIndex+i] = original[i];

    ch[nullIndex+originalLength] = '\0';
    return ch;
}

char* readFile(char *path){
    FILE *keyFile = fopen(path, "r");
    if(keyFile == NULL){
        printf("File not found\n");
        exit (-1);
    }

    char line[BUFSIZ];
    char *fileLine = malloc(BUFSIZ*sizeof(char));
    while (fgets(line, sizeof(line), keyFile) != NULL){
        int lineSize = 0;
        for (int i = 0; line[i] != '\0'; i++) lineSize++;
        fileLine = concatenateString(fileLine, line, lineSize);
    }

    fclose(keyFile);
    return fileLine;
}

void writeToFile(char* content, char*path){
    FILE *cyphertextFile= fopen(path, "w");
    fprintf(cyphertextFile, "%s", content);
    fclose(cyphertextFile);
}

int main(int argc, char* argv[]){
    bool toencrypt;
    if(argv[1] == NULL){
        printf(ANSI_COLOR_RED "ERROR\nExample usage: DES (-e|-d) [KEY_FILE TEXT_FILE]\n" ANSI_COLOR_RESET);
        return -1;
    }else{
        if (strcmp(argv[1], "-e") == 0){
            FILE *cyphertextFile = fopen("cyphertext.txt", "w+");
            fclose(cyphertextFile);
            toencrypt = true;
        } else if (strcmp(argv[1], "-d") == 0) {
            toencrypt = false;
        } else {
            printf(ANSI_COLOR_RED "ERROR\nExample usage: DES (-e|-d) [KEY_FILE TEXT_FILE]\n" ANSI_COLOR_RESET);
            return -1;
        }
    }
    char key[9];
    if(argv[2] == NULL || argv[3] == NULL){
        printf(ANSI_COLOR_RED "ERROR\nExample usage: DES (-e|-d) [KEY_FILE TEXT_FILE]\n" ANSI_COLOR_RESET);
        return -1;
    }else{
        copyString(key, readFile(argv[2]), 0, 7);
        key[8] = '\0';
    }

    char *ch = readFile(argv[3]);

    if(toencrypt){
        int len = (int)(strlen(ch));
        int i,j,k;
        int Ken = len - len%8;
        int set=1;
        if(len%8 == 0)	set = 0;
        int P[Ken/8 + set][64];
        int R = Ken/8 + set;
        int C = 64;
        int res[8];

        for(i = 0;i<Ken/8;i++){
            for(j=0 ; j<8;j++){
                ascii2bin(ch[i*8+j],res);
                for(k=0;k<8;k++){
                    P[i][8*j+k] = res[k];
                }
            }
        }

        for(i=Ken;i<len;i++){
            ascii2bin(ch[i],res);
            for(k=0;k<8;k++){
                P[Ken/8][8*(i-Ken)+k] = res[k];
            }
        }

        if(len%8!=0){
            int h = 8*(len%8);
            for(j=h;j<C;j++){
                P[R-1][j] = 1;
            }
        }

        int K[64];
        for(i=0; i<8; i++){
            ascii2bin(key[i],res);
            for(k=0;k<8;k++){
                K[8*i+k] = res[k];
            }
        }

        int Cipher[R][C];
        for(i = 0;i<R;i++){
            encrypt(P[i],K,Cipher[i]);
        }

        int A[8],retNum;
        char cy[R*C/8];
        int counter = 0;
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                A[j%8] = Cipher[i][j];
                if((j%8)==7){
                    retNum = bin2dec(A,8);
                    cy[counter] = (char)(retNum);
                    counter++;
                }
            }
        }

        writeToFile(cy, "cyphertext.txt");
        int size = sizeof(cy)/sizeof(cy[0]);
        printf(ANSI_COLOR_GREEN "\n+-ENCRYPTION SUCCESSFUL" ANSI_COLOR_RESET);
        printf("\n+----ORIGINAL MESSAGE : %s\n", ch);
        printf("+----CYPHERTEXT BITS : ");
        for(i=0;i<R;i++){
            for (j = 0; j<C; ++j){
                printf("%d",Cipher[i][j]);
            }
        }
        printf("\n+----CYPHERTEXT : %s\n\n", cy);

    }else{
        int len = (int)(strlen(ch));
        int res[8];
        int C[8*len];
        int counter = 0;
        for(int i=0; i<len; i++){
            int number = (int)ch[i];
            int bits[8];
            for (int i = 0; i < 8; i++){
                bits[i] = (number >> i) & 1;
                C[counter*8 + (7-i)] = bits[i];
            }
            counter++;
        }
        
        int K[64];
        for(int i=0; i<8; i++){
            ascii2bin(key[i],res);
            for(int k=0;k<8;k++){
                K[8*i+k] = res[k];
            }
        }

        int sizeC = sizeof(C)/sizeof(C[0]);
        int blocks = sizeC/64;
        int P[blocks*64],globP = 0,gl=0;
        while(blocks){
            blocks--;
            int cipherText[64],Plain[64];
            for(int p=0;p<64;p++,globP++)
                cipherText[p] = C[globP];
            decrypt(cipherText,K,Plain);
            for(int p=0;p<64;p++,gl++){
                P[gl] = Plain[p];
            }
        }

        int i, j;
        int A[8];
        char plaintext[1000];

        for(i = 0; i<8*(sizeC/64);i++){
            for(j=0;j<8;j++){
                A[j] = P[i*8 + j];
            }
            plaintext[i] = (char)(bin2dec(A,8));
        }
        plaintext[i] = '\0';
        
        printf(ANSI_COLOR_GREEN "\n+-DECRYPTION SUCCESSFUL\n" ANSI_COLOR_RESET);
        printf("+----CYPHERTEXT : %s", ch);
        printf("\n+----PLAINTEXT BITS : ");
        for(int i = 0; i<8*len; i++){
            printf("%d", P[i]);
        }
        printf("\n+----PLAINTEXT : %s\n\n", plaintext);
        writeToFile(plaintext, "plaintext.txt");
    }
    return 0;
}
