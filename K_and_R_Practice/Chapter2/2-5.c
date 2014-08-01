#include<stdio.h>

int any(char* s1,const char* s2)
{
	int i,j;
	for(i=0;s1[i]!=0;i++)
	{
		int flag = 0;
		for(j=0;s2[j]!=0;j++)
		{
			if( s1[i] == s2[j] )
			{
				return i;
			}
		}
	}
	return -1;
}

int main(int argc,char* argv[])
{
	char str[100];
	strcpy(str,argv[1]);
	printf("%d position\n",any(str,argv[2]));
}
