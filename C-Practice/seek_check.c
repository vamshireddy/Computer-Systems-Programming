#include<stdio.h>
#include<fcntl.h>


/*
	This will check whether a file can be seeked or not 
*/

int main()
{
	int file = open("hex.c",O_RDWR,0777);
	int a = lseek(file, 0, SEEK_CUR);
	if( a == -1 )
	{
		printf("Seek error\n");
	}
	else
	{
		printf("No error\n");
	}
}
