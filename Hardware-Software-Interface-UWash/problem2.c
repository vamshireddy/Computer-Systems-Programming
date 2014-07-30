#include<stdio.h>


int main()
{
	int p1[2];
	int* a = p1;
	int* b = p1+1;

	printf("a=%p, b=%p\n%lu\n",a,b,(unsigned long)b-(unsigned long)a);
}
