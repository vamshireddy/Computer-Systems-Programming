#include<stdio.h>

int bitcount_one(unsigned int x)
{
	int count = 0;
	for(;x!=0;count++)
	{
		x &= ( x-1 );
	}
	return count;
}

int main()
{
	printf("the count of 1's are %d\n",bitcount_one(0xF1FF));
}
