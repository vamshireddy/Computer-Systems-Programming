#include<stdio.h>

int* y;

int a()
{
	int a;
	return &a;
}

int b()
{
	int c;
	printf("Addresses are %x %x \n",y,&c);
	*y = 1024;
	printf("Its %d\n",c);
}

int main()
{
	y = a();
	printf("%x\n",y);
	b();	
	return 0;
}
