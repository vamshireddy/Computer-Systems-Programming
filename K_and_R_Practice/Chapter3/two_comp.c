#include<stdio.h>

int main()
{
	int i = 0x80000000;
	int j = -i;
	printf("%d\n",j);
	printf("%d\n",i);
	printf("%d\n",i%2);
}
