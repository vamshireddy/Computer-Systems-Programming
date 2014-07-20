#include<stdio.h>

/*
Count the characters in the input stream 
*/

int main()
{
	long nc;
	while( getchar()!=EOF )
	{
		nc++;
	}
	printf("There are %d characters \n",nc);
}
