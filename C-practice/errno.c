#include<stdio.h>
#include<errno.h>

int main()
{
	int a = 1;
	int b = -a;
	printf("%s",strerror(EACCES));
	printf("The errno is : %d\n",errno);
	perror("");
}
