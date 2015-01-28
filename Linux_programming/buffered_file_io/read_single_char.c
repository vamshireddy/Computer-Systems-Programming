#include<stdio.h>

int main()
{
	
	FILE* fstr = fopen("hello.txt","r");

	if( fstr != NULL )
	{
		int c = fgetc(fstr);
		printf("Character is %c\n",c);
	}
}
