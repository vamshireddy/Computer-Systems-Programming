#include<stdio.h>

extern int a = ;
int main()
{
	register int b = 0;
	printf("Hello %u\n",&b);
}

