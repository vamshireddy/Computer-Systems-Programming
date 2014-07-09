#include<stdio.h>
#include<fcntl.h>


int main()
{
	int a = open("~/hello.c",O_CREAT|O_RDWR|O_TRUNC, 777);
}
