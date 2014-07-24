#include<stdio.h>
#include<fcntl.h>

int main()
{
	int a = open("outfile",O_RDWR|O_APPEND);
	lseek(a, 10, SEEK_SET);
	char buffer[10];
	read(a,buffer,10);
	printf("%s\n",buffer);
	read(a,buffer,10);
	printf("%s\n",buffer);
	read(a,buffer,10);
	printf("%s\n",buffer);
	read(a,buffer,10);
	printf("%s\n",buffer);
	read(a,buffer,10);
	printf("%s\n",buffer);
	read(a,buffer,10);
	write(a,buffer,10);
}
