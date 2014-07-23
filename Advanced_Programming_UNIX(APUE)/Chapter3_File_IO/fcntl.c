#include<stdio.h>
#include<fcntl.h>


int main()
{
	int a = open("hello",O_RDWR);
	int p = fcntl(a, F_GETFD);
	fdatasync(a);
	printf("%d\n",p);
}
