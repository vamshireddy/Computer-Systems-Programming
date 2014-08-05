#include<stdio.h>

int bin_search(int a[],int size,int key)
{
	int low = 0;
	int high = size-1;
	int answer = -1;
	int mid;

	while( low <= high && (a[(mid = (low+high)/2 )] !=key ) )
	{
		if( key < a[mid] )
			high = mid-1;
		else	
			low = mid+1;
	}

	if( low > high )
	{
		return -1;
	}
	else
	{
		return mid;
	}
}

int main()
{
	int a[] = {1,3,4,6,82,345,2345};
	printf("found at %d\n",bin_search(a,7,1));
}
