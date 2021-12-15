#include "myl.h"
#define BUFF 100 
#define INT_MAX 2147483647 

int printStr(char *str)
{
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

int printInt(int n)
{
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

// int readInt(int *eP) {
//     int i=0;
//     char str[10];
//     int sign=1,val=0;
//     *eP=OK;
//     while(1){
//         __asm__ __volatile__ ("syscall"::"a"(0), "D"(0), "S"(str), "d"(1));
//         if(str[0]==' ' || str[0] == '\t' || str[0]=='\n')break;
//         if(!i && str[0]=='-')sign=-1;
//         else{
//             if(str[0] >'9' || str[0]<'0' )*eP=ERR;
//             else{
//                 val=10*val+(int)(str[0]-'0');
//             }
//         }
//         i++;
//     }
//     return val*sign;
// }

int readInt(int *eP){
    int i = 0, neg = 0, len = 0;
    long int number = 0;
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
            *eP = ERR;
        }     
    }
    if(buff[i] == '-'){
        neg = 1;
        i++;
        if(len == 1 || buff[1] == ' '){
            *eP = ERR;
        } 
    }
    while(i < len){
        char read = buff[i];
        i++;
        if(read <= '9' && read >= '0'){
            number = number*10 + (long int)(read - '0');
            if(neg == 0 && number > INT_MAX){
                *eP = ERR;
            }
            if(neg == 1 && number > ((long int)INT_MAX + 1)){
                *eP = ERR;
            }
        }else if(read == ' '){
            break;
        }else{
            *eP = ERR;
        }
    }
    if(neg == 1){
        number *= -1;
    }
    *eP = OK;

    return (int)number;
}