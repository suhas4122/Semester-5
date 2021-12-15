// Fibonacci Triangle

int main()
{
    int a = 0, b = 1, i, c, n, j;

    printStr("\n*************************** Fibonacci Triangle ***************************\n");
    printStr("\nEnter the upper limit: \n");
    int err;
    n = readInt(&err);
    printStr("\nThe required Fibonacci Triangle: \n");
    a = 0;
    b = 1;
    n = n + 1;
    for(i = 1 ; i <= n ; i++)
    {
        // printInt(b);
        printStr("\t");

        for(j = 1 ; j < i ; j++)
        {
            c = a+b;
            printInt(b);
            printStr("\t");

            a = b;
            b = c;
        }

        printStr("\n");
    }

    
    printStr("\n*******************************************************************************\n");
    
    return 0;
}
