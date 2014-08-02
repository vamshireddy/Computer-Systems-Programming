#include<stdio.h>
#define MAX_LINE 200
#define END 1

char* getline_greater_80()
{
	char* arr = (char*)malloc(sizeof(char)*MAX_LINE);
	int i=0;
	int extra=0;
	char c;
	while( ((c = getchar()) != EOF ) && c!='\n')
	{
		if( i < MAX_LINE-1 )
		{
			arr[i++] = c;		
		}
		else
		{
			extra++;
		}
	}

	arr[i] = '\0';

	if( (i+extra) == 0 )
	{
		return (char*)END;
	}
	else if( (i+extra) > 80 )
	{
		return arr;	
	}
	else
	{
		return NULL;
	}
}


int main()
{
	char* str;
	while( ( str = getline_greater_80() ) != END )
	{
		if( str!=NULL )
			printf("Line greater than 80 is %s\n",str);
	}
}
