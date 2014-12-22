#include<stdio.h>
#include<fcntl.h>

int main()
{
	int seek = lseek(0,0,SEEK_CUR);
	if( seek == -1 )
	{
		perror("");
	}
}
