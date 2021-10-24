int fact (int n) {                               // Recursive functions To calculate factorial 
    if (n == 0) 
        return 1; 
    return n * fact(n-1); 
} 

int main() {  
    int n;
    n = -5; 

    if (n > 10) {                                // Nested if-else blocks to check the grammer 
        n = 10;
    } else {
        if (n < 0) {                            
            n = 0;
        } else {
            n = 5;
        }
    }
    int fact_n = fact(n); 
    return 0;  
}