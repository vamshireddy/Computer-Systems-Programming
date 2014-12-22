#include<stdio.h>
#define SIZE 4096


int main()
{
	char buffer[SIZE];

	int n;

	while( ( n = read(0,buffer,SIZE) ) > 0 )
	{
		if( write(1,buffer,n) != n )
		{
			printf("Error in write\n");
			exit(0);
		}
	}

	if( n < 0 )
	{
		printf("Error in read\n");
	}
}
