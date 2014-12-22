#include<stdio.h>
#include<fcntl.h>

// Simple program to test the file descriptors


int main()
{
	//close(1);
	int a = open("hello",O_RDWR);
	if( a==-1 )
	{
		perror("");
		exit(0);
	}
	printf("File desc is %d\n",a);
	printf("Saffsa");
	int p;
	scanf("%d",&p);
}
