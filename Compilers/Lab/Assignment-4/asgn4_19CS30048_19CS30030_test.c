/****************************
 * Suhas Jain   | 19CS30048
 * Monal Prasad | 19CS30030                  
 * Testing code for tinyC parser
 * **************************/

extern int var;

// Testing enum keyword
enum weekends {Saturday, Sunday};

// Function to perform termary search of a key in array ar
signed int ternarySearch(int l, int r, int key, int ar[]){
    if (r >= l){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (ar[mid1] == key){
            return mid1;
        }
        if (ar[mid2] == key){
            return mid2;
        }
        
        if (key < ar[mid1]){
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]){
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else{
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
    return -1;
}

// Brute force to compute Nth fibonacci number
unsigned int Fibonacci(int n){
    if (n <= 1) 
        return n; 
    return Fibonacci(n - 1) + Fibonacci(n - 2); 
}


/* Main function of C code 
   Also testing multi-line comments */
void main(void){

    // Test few special keywords / datatypes 
  	_Bool data1 = 1;
    double _Complex data2 = 1 + 2*I;
    double _Imaginary data3 = 3*I;

    // Testing all the arithmetic operations 
    int a, b, c;
    a = b + c;
    a = b - c;
    a = b * c;
    a = b / c;
    a += b;
    a -= b;
    a *= b;
    a /= b;
    a = b << c; a = b >> c; a = b >> (30); a = (30) << a + b ;
    a =! b;
    a =~ b;
    a %= b;
    a = b ^ c;
    a = b & c;
    a = b && c;
    --a ;
    ++a;
    a = (b) ? b : c;
    a &= b;
    a |= b;

    var = 10;

    // Testing differect keywords 
    const float f1 = 2.3E5;
    static float f2 = -0.3e-1;
    if(f1 < f2){
        printf("First floating point number is smaller\n\n");
    }

    // Testing declarations and function calls 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("Enter the element to search : ");
    int n;
    scanf("%d", &n);
    int ans = ternarySearch(0, 9, n, arr);

    if(ans != -1){
        printf("Number found in array\n");
        char* s = "Computing Nth fibonacchi number :";
        printf("%s", s);
        int fib = Fibonacci(n);
        printf("%d\n", fib);
    }else{
        printf("Number is too large to be computed by brute force approach");
    }

    return;
}