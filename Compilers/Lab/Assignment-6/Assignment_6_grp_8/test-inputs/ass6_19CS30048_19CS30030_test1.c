//Average

int main()
{
	int x[100];
	int n, m, i;
	int sum = 0;
	int err = 1;
	printStr("\n************************ Average *********************\n");
	printStr("\nEnter the number of elements in array\n");
	n = readInt(&err);
	printStr("\nEnter the elements of the array one by one i.e. enter a new line after every element: \n");
	for(i=0;i<n;i++)
	{
		x[i]=readInt(&err);
		sum = sum + x[i];
	}
	int len;
	len = sum/n;
	printStr("\nThe Average of all elements in the array is: \n");
	printInt(len);
	printStr("\n\n*******************************************************\n");
	return 0;
}
