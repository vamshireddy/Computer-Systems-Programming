#include<stdio.h>
#include<fcntl.h>


int main()
{
	int file = creat("hello_world",0777);
	if( file == -1 )
	{
		printf("Error in file creation\n");
		exit(0);
	}

	char* c = "hello";
	char* b = "world";

	write(file, c, 6);
	lseek(file, 16394, SEEK_CUR);
	write(file, b, 6);
	close(file);
}
