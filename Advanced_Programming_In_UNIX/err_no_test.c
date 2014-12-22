/*
	Program to check the errno value when an error occurs */
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd = open("akfasf",O_RDONLY);

	if( fd == -1 )
	{
		printf("%s\n",strerror(errno));
		printf("Err no value is %i\n",errno);
		if( errno == ENOENT )
		{
			printf("Its ENOENTerror\n");
		}
		perror("Error ");
	}
}
