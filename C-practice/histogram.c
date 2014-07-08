#include<stdio.h>
#include<fcntl.h>


int main()
{
	int file = open("hello",O_RDONLY|O_CREAT,0777);

	char c,a;

	int i,j;

	int alpha_count[24];

	for(i=0;i<26;i++)
		alpha_count[i] = 0;

	while( ( a = read(file,&c,1) )!=0 ) 
	{
		if( c>='a' && c<='z' )
		{
			alpha_count[c-'a']++;
		}
	}

	for(i=0;i<26;i++)
	{
		printf("%c : ",(97+i));
		for(j=0;j<alpha_count[i];j++)
		{
			printf("= ");
		}
		printf("\n");
	}
}
