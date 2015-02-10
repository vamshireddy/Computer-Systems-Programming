#include<stdio.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
	int a = access("a.out",R_OK|W_OK|X_OK);
	if( a == -1 )
	{
		perror("R_OK");
	}
	else
	{
		printf("Read, write, execute OK\n");
	}
}
