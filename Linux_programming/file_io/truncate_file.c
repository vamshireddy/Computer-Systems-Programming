#include<stdio.h>

int main()
{
	int new_len = truncate("hello.txt",2);
	if( new_len == -1 )
	{
		perror("trncate:");
	}
	else
	{
		printf("file successfully truncated\n");
	}
}
