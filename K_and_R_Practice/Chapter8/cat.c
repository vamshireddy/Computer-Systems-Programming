#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int file = open("hello",O_RDONLY);
	if( file == -1 )
	{
		printf("Error\n");
		exit(0);
	}

	char buffer[1024];

	int r;

	while( ( r = read(file,buffer,1024) ) > 0 )
	{
		write(1,buffer,r);
	}
	close(file);
}
