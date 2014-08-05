#include<stdio.h>

void escape(char* dst,const char* src)
{
	int i;
	int index = 0;
	for(i=0;src[i]!=0;i++)
	{
		switch(src[i])
		{
			case '\n' :	dst[index++] = '\\';
					dst[index++] = 'n';
					break;
			case '\t' :	dst[index++] = '\\';
					printf("tab is here\n");
					dst[index++] = 't';
					break;
			default:	dst[index++] = src[i];
					break;
		}
	}
}

int main()
{
	char src[100];
	char dst[200];

	printf("Enter the string\n");
	gets(src);
	printf("the orig string %s\n",src);
	escape(dst,src);
	printf("String is %s\n",dst);
}
