#include<stdio.h>
#include<fcntl.h>


int main(int argc, char* argv[])
{
	if( argc < 2 )
	{
		printf("Not suff args \n");
		exit(0);
	}
	
	int fd = open(argv[1],O_RDONLY);

	if( fd == -1 )
	{
		perror("Cannot open this file");
		exit(0);
	}

	if( lseek(fd,0,SEEK_CUR) == -1 )
	{
		printf("Cannot seek this file\n");
		exit(0);
	}
	
	printf("File can be seeked\n");
	
}
