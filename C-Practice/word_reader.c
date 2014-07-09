#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	time_t t;
	char* strings[1000];
	int i;
	for(i=0;i<1000;i++)
	{
		strings[i] = (char*)malloc(sizeof(char)*100);
	}

	int file = open("Words",O_RDONLY);
	
	if( file == -1 )
	{
		perror("Please check the file");
		return;
	}

	int pointer = 0;
	int index = 0;
	char c;
	while( read(file,1,&c) != -1 )
	{
		if( c == '\n' )
		{
			strings[pointer][index++] = '\0';
			pointer++;
			index = 0;
		}
		else
		{
			strings[pointer][index++] = c;
		}
	}
	srand((unsigned) time(&t));
	/*
		Generate the random number 
	*/
	int no = rand()%pointer;
	printf("%s",strings[no]);
}
