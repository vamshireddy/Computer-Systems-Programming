#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("hello.txt",O_RDONLY);

	if( fd!=-1 )
	{
		// File descriptor present

		FILE* fstream = fdopen(fd,"r");
		if( fstream==NULL )
		{
			perror("");
		}
		else
		{
			printf("opened succesful;y\n");
			int f = fclose(fstream);
			if( f == 0 )
			{
				printf("file stream closed succesfully\n");
			}
		}
	}
}
