#include<stdio.h>


/*
	This shows that we can redirect the input from a file to this process.
	./a.out < hello
	hello contains 
	3
	4
*/
int main()
{
	int a;
	scanf("%d",&a);
	int b;
	scanf("%d",&b);
	printf("hey %d\n",a);
	printf("hey %d\n",b);
}
