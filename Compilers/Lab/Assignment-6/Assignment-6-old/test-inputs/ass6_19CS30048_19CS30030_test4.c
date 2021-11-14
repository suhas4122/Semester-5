// Calculate Interest

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int main()

{
    int a, b;
    int c, err;
    printStr("\n****************** GCD *****************\n");
    printStr("\nEnter two numbers:\n");
    a = readInt(&err);
    b = readInt(&err);

    c = gcd(a, b);

    printStr("\nGCD :\n");
    printInt(c);
    printStr("\n***********************************\n");
    return 0;

}