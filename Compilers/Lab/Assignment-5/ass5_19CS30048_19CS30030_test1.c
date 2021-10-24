int mult(int a,int b)
{
    int product = a*b;
    return product;
}

int sum(double a, double b)
{
    int c;
    c = a+b;
    return c;
}

char sumchar(int a, int b)
{
    char c;
    c = a+b;
    return c;
}

void main(){
    int a = 10;
    int ep;
    int b = 20;
    int c;
    double x = 2.5;
    x = mult(a, b);
    c = sum(x, b);
    char p = sumchar(a,c);
    return;
}