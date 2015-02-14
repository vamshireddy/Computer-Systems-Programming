#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	// File name is input to this program
	if( argc != 3 )
	{
		printf("Not enough arguments\nExample usage is cp file_Src file_Dst\n");
		exit(0);
	}

	int file_src = open(argv[1],O_RDONLY);
	if( file_src < 0 )
	{
		perror("open at src");
	}

	int file_dst = open(argv[2],O_WRONLY|O_CREAT,0777);
	if( file_dst < 0 )
	{
		perror("open at dst");
	}

	char buffer[1];
	int c;
	while( ( c = read(file_src,buffer,1) ) != 0 )
	{
		if( c == -1 )
		{
			perror("Read");
			exit(0);
		}
		// Copy the contents to the destination
		if( buffer[0] !='\0' )
		{
			int err = write(file_dst,buffer,c);
			if( err!=c )
			{
				perror("Write");
				exit(0);
			}
		}
	}
	close(file_src);
	close(file_dst);
}
