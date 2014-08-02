#include<stdio.h>

int main()
{
	int a[2][2] = {{1,2},{3,4}};
	int* p = a+1;
	printf("%d\n",*p);
}
