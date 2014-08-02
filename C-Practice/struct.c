#include<stdio.h>

struct s
{
	char c;
	int i[2];
	double v;
}*p;

int main()
{
	struct s s1;
	printf("%d\n",sizeof(s1));
}
