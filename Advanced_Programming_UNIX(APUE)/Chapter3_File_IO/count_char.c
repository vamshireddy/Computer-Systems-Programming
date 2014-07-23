#include<stdio.h>
#include<fcntl.h>

int main()
{
	int a = open("hello",O_RDWR|O_CREAT|O_APPEND);
	if( write( a , "hello ",6) == -1 )
	{
		perror("error");
	}
	int s = lseek(a,0,SEEK_END);
	printf("The size of the file is %d\n",s);
}
