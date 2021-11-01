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
	printStr("\nEnter the elements of the array one by one\n");
	for(i=0;i<n;i++)
	{
		x[i]=readInt(&err);
		sum = sum + x[i];
	}
	int len;
	len = sum/n;
	printStr("\nAverage is (in integer) : \n");
	printInt(len);
	printStr("\n******************************\n");
	return 0;
}
