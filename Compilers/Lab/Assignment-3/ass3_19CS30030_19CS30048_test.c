//  PLEASE NOTE : The following C code is syntactically INCORRECT. The given arrangement is done to make testing of flex specifictions easy

#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
	//Testing Keywords
 	break  case char continue default do double else extern float for goto 
	if int long return short sizeof static struct switch typedef union void while

	// Testing Punctuators
	  -> ~ ! % << >> < > <= >= : ; ...
	*= /= %= += -= <<= # -- ) & >>= != &= ^ | ^= && || |=

	//Testing Identifiers and Constants
	int i = 89;	
	float f1 = 3425.896 ;
	float f2 = 12E-2 ; 	
 	double f3 = 55e+92 ; 	
 	int array[] = {4,6,7,84,3,5,7,3,66,67};
	char c = 'y';
 	string s = "This is a test for string literal \n \t";

	/* Test for multi line comment */
	// Test for single line comment 

	int pos = binarySearch(array, 0, 9, 66);
	int val = (5 > 3) ? 3 : 2;
	int j = 0;
	int val = 12.5;
	while(val < 5 && val > 0){
		val++;
		val--;
		val /= 2;
		val *= 4;
		val = val * 10;
		val = val + 10;
		val = val - 10;
		val = val / 10;
		val = val % 10;
		int x = sizeof(char);
		if(val == 0) break;
	}

	return 0;
}

