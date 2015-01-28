#include<stdio.h>



int main()
{
	// opened files are called streams
	FILE* file = fopen("hello.txt","r+");
	if( file != NULL)
	{
		printf("File opened succesfully\n");
	}
	else
	{
		perror("");
	}
}
