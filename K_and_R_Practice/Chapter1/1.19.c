#include<stdio.h>


void reverse(char* str,int len)
{
	int i;
	for(i=0;i<len/2;i++)
	{
		int temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
}

int getLine(char* str)
{
	int i=0;
	char c;
	while(( ( c = getchar() )!=EOF ) && c!='\n')
	{
		str[i++] = c;
	}
	str[i] = '\0';
	return i;
}

int main()
{
	char str[100];
	int a;
	while( ( a = getLine(str) )!=0 )
	{
		printf("Original string is %s\n",str);
		reverse(str,strlen(str));
		printf("Reversed string is %s\n",str);
	}
}
