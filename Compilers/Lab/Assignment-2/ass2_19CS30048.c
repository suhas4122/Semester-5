/*
COMPILERS LABORATORY (CS39003)
Name - Suhas Jain 
Roll no. - 19CS30048
Assignment - 2
Creating Library
*/

#define ERR 0
#define OK 1
#define BUFF 100 
#define INT_MAX 2147483647 
#define DECIMAL_POINTS_PRECISION 1000000
#include <stdio.h>

int printStr(char* str){
    int len = 0;
    while(1){
        if(str[len] == '\0')
            break;
        len++;
    }
    int error;
    __asm__ __volatile__(
        "movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:"=a"(error)
		:"S"(str), "d"(len)
    );
    if(error >= 0)
        return len;
    else    
        return ERR;
}

int readInt(int* n){
    int i = 0, neg = 0, len = 0;
    long int number = 0;
    *n = 0;
    char buff[BUFF] = "";
    __asm__ __volatile__(
		"movl $0,%%eax \n\t"
		"movq $0, %%rdi \n\t"
		"syscall \n\t"
		:"=a"(len)
		:"S"(buff),"d"(BUFF)
	);
    len--;
    while(buff[i] == ' '){
        i++;            
    }  
    if(buff[i] == '+'){
        i++;
        if(len == 1 || buff[1] == ' '){
            return ERR;
        }     
    }
    if(buff[i] == '-'){
        neg = 1;
        i++;
        if(len == 1 || buff[1] == ' '){
            return ERR;
        } 
    }
    while(i < len){
        char read = buff[i];
        i++;
        if(read <= '9' && read >= '0'){
            number = number*10 + (long int)(read - '0');
            if(neg == 0 && number > INT_MAX){
                return ERR;
            }
            if(neg == 1 && number > ((long int)INT_MAX + 1)){
                return ERR;
            }
        }else if(read == ' '){
            break;
        }else{
            return ERR;
        }
    }
    if(neg == 1){
        number *= -1;
    }
    *n = (int)number;
    return OK;
}

int printInt(int n){
    int i = 0, j = 0, k = 0, neg = 0;
    long temp;
    char buff[BUFF];
    if(n == 0){
        buff[i++] = '0';
        temp = 0;
    }else if(n < 0){
        neg = 1;
        temp = -1*(long)n;
    }else{
        temp = n;
    }
    while(temp > 0){
        int curr = temp % 10;
        temp /= 10;
        buff[i++] = (char)(curr + '0');
    }
    k = i - 1;
    while(j < k){
        char swap = buff[j];
        buff[j] = buff[k];
        buff[k] = swap;
        k--, j++;
    }
    if(neg == 1){
        for(int l = i+1; l > 0; l--){
            buff[l] = buff[l-1];
        }
        buff[0] = '-';
        i++;
    }
    int flag;
	__asm__ __volatile__(
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:"=a"(flag)
		:"S"(buff), "d"(i)
	); 
	if(flag < 0)
		return ERR;
	else 
		return flag; 
}

int readFlt(float *f){
    int i, j, len, neg = 0, dec = 0, expo = 0, dcount = 0;
    long int ip = 0;
    char buff[BUFF];                
    float fact = 0.1, dp = 0, number;
    *f = 0;
    __asm__ __volatile__(
		"movl $0,%%eax \n\t"
		"movq $0, %%rdi \n\t"
		"syscall \n\t"
		:"=a"(len)
		:"S"(buff),"d"(BUFF)
	);
    j = len - 1;
    buff[j] = 0x0; 
    i = j-1;                                           
    while(buff[i] == ' ' && i > -1){
        i--;           
    }
    buff[i+1] = 0x0;                                
    len = i+1;                              
    i = 0;
    while(buff[i] == ' '){
        i++;            
    }           
    if(buff[i] == '+'){
        neg = 0;
        i++;
    }else if(buff[i] == '-'){
        neg = 1;
        i++;
    }
    while(i < len){ 
        char read = buff[i]; 
        i++;                    
        if(read == '.'){                
            if(dec == 1)
                return ERR;    
            dec = 1;
        }else if(read == 'e' || read == 'E'){
            expo = 1;
            break;
        }else if(read < '0' || read > '9'){    
            return ERR;
        }else if(dec == 1){
            dcount++;
            if(dcount > 6){
                continue;
            }
            dp = dp + fact * (read-'0');                 
            fact = fact * 0.1;
        }else{
            ip = ip * 10 + ( read - '0');        
        }
    }  
    number = (int)ip + dp;
    if(expo == 1){
        int num = 0, sign = 0;
        if(buff[i] == '-'){
            sign = 1;
            i++;
        }
        if(buff[i] == '+'){
            i++;
        }
        while(i < len){
            char read = buff[i];
            if(read <= '9' && read >= '0'){
                num = num*10 + read - '0';
            }else if(read == ' '){
                break;
            }else{
                return ERR;
            }
            i++;
        }
        if(sign == 0){
            while(num--){
                number *= 10;
            }
        }else{
            while(num--){
                number /= 10;
            }
        }
    }
    *f = number;
    if(neg == 1)
        *f *= -1;                                                             
    return OK;
}

int printFlt(float f){
	char buff[BUFF];
	int i = 0, j = 0, k = 0, neg = 0;
	if(f < 0){
		neg = 1;
		f *= -1;
	}
	long int ip = (long int)f;
	int fp = (int)((long int)(f*DECIMAL_POINTS_PRECISION)%DECIMAL_POINTS_PRECISION);
	if(ip == 0){
		buff[i++] = '0';
	}else{
		long int temp = ip;
		while(temp > 0){
			buff[i++] = (char)(temp%10 + '0');
			temp /= 10;
		}
		k = i - 1;
    	while(j < k){
			char swap = buff[j];
			buff[j] = buff[k];
			buff[k] = swap;
			k--, j++;
		}
		if(neg == 1){
			for(int l = i+1; l > 0; l--){
				buff[l] = buff[l-1];
			}
			buff[0] = '-';
			i++;
		}
    }
    buff[i++] = '.';
	if(fp == 0){
        int counter = 0;
		while (counter < 6){
            counter++;
            buff[i++] = '0';
        } 
	}else{
		j = i;
		int temp = fp;
        int counter = 0;
		while(temp > 0){
            counter++;
			buff[i++] = (char)(temp%10 + '0');
			temp /= 10;
		}
		k = i - 1;
    	while(j < k){
			char swap = buff[j];
			buff[j] = buff[k];
			buff[k] = swap;
			k--, j++;
		}
        while (counter < 6){
            counter++;
            buff[i++] = '0';
        } 
	}
	int size = i;
	int flag;
	__asm__ __volatile__(
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:"=a"(flag)
		:"S"(buff), "d"(size)
	); 
	if(flag < 0)
		return ERR;
	else 
		return flag;
}