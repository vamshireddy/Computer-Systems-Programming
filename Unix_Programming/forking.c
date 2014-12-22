#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	fork();
	printf("Hello\n");
	fork();
	printf("Hello\n");
	fork();
	printf("Hello\n");
}
