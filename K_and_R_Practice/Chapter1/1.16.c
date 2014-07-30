#include<stdio.h>
#define MAX_LENGTH 10

// buffer_flag indicates whether the buffer is full and the newlne char hasn't been encountered yet!
int readline(char* string)
{
	int i=0;
	char c;
	while( ( (c = getchar()) != EOF ) && (c!='\n') )
	{
		if( i >= MAX_LENGTH-1 )
		{
			// increment for the current char
			i++;
			// To handle arbitrary lengths
			char p;
			int last_index = i;
			printf("The index is %d \n",i);
			while ( ( (p = getchar()) != EOF ) &&  ( p != '\n' ) )
			{
				i++;
			}
			string[last_index] = '\0';
			return i;
		}
		string[i++] = c;
	}
	string[i] = '\0';
	return i;
}

void copy_strings(char* dest,char* src)
{
	int i=0;
	while( (dest[i] = src[i]) != '\0' )
	{
		i++;
	}
}

int main()
{
	int len;
	int max_len = 0 ;
	char line[MAX_LENGTH];
	char long_line[MAX_LENGTH];
	int flag = 0;
		
	while( ( len = readline(line) ) != 0 )
	{
		if( len > max_len )
		{
			max_len = len;
			copy_strings(long_line,line);
		}
	}
	printf("The line was %s and its length was %d\n",long_line,max_len);
}
