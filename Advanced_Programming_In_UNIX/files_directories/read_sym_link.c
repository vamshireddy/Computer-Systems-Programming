#include<stdio.h>


int main()
{
	char buf[100];
	int a = readlink("foo/vamshireddy",buf,100);
	int i;	
	for(i=0;i<a;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n");
}
