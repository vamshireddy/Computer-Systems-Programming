#include<stdio.h>
#include<sys/stat.h>

int main()
{
	struct stat file_stat;
	if( stat("hello",&file_stat) == -1 )
	{
		perror("");
		exit(0);
	}
	int mode = file_stat.st_mode;
	if( S_ISDIR(mode) )
	{
		printf("Its a dir\n");
	}
	else
	{
		printf("its a file\n");
	}
}	
