#include<stdio.h>

int main()
{
	int a = 240;
	char* p;
	p = (char*)&a;
	printf("%0.2x ",*p);
	p++;
	printf("%0.2x ",*p);
	p++;
	printf("%0.2x ",*p);
	p++;
	printf("%0.2x",*p);
}
