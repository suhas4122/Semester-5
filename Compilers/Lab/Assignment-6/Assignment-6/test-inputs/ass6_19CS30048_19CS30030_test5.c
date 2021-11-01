// Fibonacci Triangle

int main()
{
    int a = 0, b = 1, i, c, n, j;

    printStr("\n*************************** Fibonacci Triangle ***************************\n");
    printStr("\nEnter the limit: \n");
    int err;
    n = readInt(&err);

    for(i = 1 ; i <= n ; i++)
    {
        a = 0;
        b = 1;
        printInt(b);
        printStr("\t");

        for(j = 1 ; j < i ; j++)
        {
            c = a+b;
            printInt(c);
            printStr("\t");

            a = b;
            b = c;
        }

        printStr("\n");
    }

    
    printStr("\n*******************************************************************\n");
    
    return 0;
}