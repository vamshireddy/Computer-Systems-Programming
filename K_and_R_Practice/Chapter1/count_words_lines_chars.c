#include<stdio.h>
#define OUT 0
#define IN 1

/*
Program to count lines, chars , words in an input stream 
*/
int main()
{
	char c;
	int words,chars,lines;
	words = chars = lines = 0;
	int state = OUT;
	while( ( c = getchar() )!=EOF )
	{
		if( c=='\n' )
		{
			lines++;
		}
		if( c == ' ' || c == '\t' || c == '\n' )
		{
			state = OUT;
		}
		else if( state == OUT )
		{
			state = IN;
			words++;
		}
		chars++;
	}
	printf("There are %d words, %d chars, %d lines\n",words,chars,lines);
}
