#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	int i;
	
	struct stat status;

	char* str;

	for( i=1;i<argc;i++ )
	{
		printf("%s - ",argv[i]);
		
		if( stat(argv[i],&status) == -1 )
		{
			perror("");
			exit(0);
		}

		if( S_ISREG(status.st_mode) )
		{
			str = "regular";
		}
		if( S_ISDIR(status.st_mode) )
		{
			str = "directory";
		}
		if( S_ISCHR(status.st_mode) )
		{
			str = "char special";
		}
		if( S_ISBLK(status.st_mode) )
		{
			str = "block special";
		}
		if( S_ISFIFO(status.st_mode) )
		{
			str = "fifo";
		}
		if( S_ISLNK(status.st_mode) )
		{
			str = "link";
		}
		if( S_ISSOCK(status.st_mode) )
		{
			str = "socket";
		}
		printf("%s\n",str);
	}
	


}
