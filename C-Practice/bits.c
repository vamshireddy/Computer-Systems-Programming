#include<stdio.h>

struct helo
{
	int a:3;
	int b:3;
	int c:2;
};

int main()
{
	struct helo h = {2,-6,3};
	printf("%d %d %d\n",h.a,h.b,h.c);
}
