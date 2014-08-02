#include<stdio.h>


int main()
{
	// Always try to map a state diagram for these kinds of questions
	int char_flag = 0;
	char c;
	while( ( c = getchar() ) != EOF )
	{
		if( char_flag == 0 )
		{
			// No chars have been encountered till now 
			if( c == ' ' || c == '\n' || c == '\t' )
			{
				continue;
			}
			else
			{
				printf("%c",c);
				char_flag = 1;
			}
		}
		else
		{
			// Line has some char's
			if( c == '\n' )
			{
				char_flag = 0;
			}
			printf("%c",c);
		}
	}
}
