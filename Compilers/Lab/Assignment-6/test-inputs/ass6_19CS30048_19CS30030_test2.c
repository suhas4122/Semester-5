//Bubble Sort

void BubbleSort(int arr[], int n)
{
	int i, j, tmp;

	for(i = 0 ; i < n - 1 ; i++)
	{
		for(j = 0 ; j < n - i - 1 ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}


void PrintArray(int arr[], int size)
{
	int i;

	for(i = 0 ; i < size ; i++)
	{
		printInt(arr[i]);
		printStr("\n");
	}
}

int main()
{
    int arr[100],i,n;
	int err=1;
	
	printStr("\n********************* Bubble Sort ***********************\n");
    printStr("\nEnter the number of elements\n");
    
    n = readInt(&err);
	
	printStr("\nEnter the elements of the array one by one i.e. enter a new line after every element: \n"); 
    
    for(i=0;i<n;i++)
    {
        arr[i]=readInt(&err);
    }
	
	BubbleSort(arr,n);

	printStr("\nThe elements of the array in ascending order are : \n");

	PrintArray(arr, n);
	
	printStr("\n**********************************************************\n");
	
	return 0;
}

