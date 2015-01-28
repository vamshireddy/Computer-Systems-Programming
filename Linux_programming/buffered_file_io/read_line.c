#include<stdio.h>


int main()
{
	FILE* stream = fopen("hello.txt","r");
	
	char buffer[1000];

	fgets(buffer,10,stream);

	printf("Buffer is %s\n",buffer);
}

