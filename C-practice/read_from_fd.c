#include<stdio.h>
#include<unistd.h>
#define BUFFSIZE 5

/*
Read from the file descriptor 0 and also write it to the file descriptor 1*/

int main()
{
	int n;
	char buf[BUFFSIZE];

	while( (n=read(0,buf,BUFFSIZE)) > 0 )
	{
		if( write(1,buf,n)!=n ) 
		{
			printf("Error\n");
		}
	}
}
