#include<stdio.h>
#include<sys/stat.h>

int main(int argc,char* argv[])
{
	// If we use stat instead of lstat for a symbolic link, then it shows the stat details of the actual file which is pointed by the sym link
	struct stat s;

	int a = stat(argv[1],&s);
	if( a < 0 )
	{
		perror("Stat");
	}

	if( S_ISLNK(s.st_mode) )
	{
		// You will never come here!!
		// stat will always take to the file pointed by the link
		printf("its a link\n");
	}
	else
	{
		printf("its not a link\n");
	}
}

