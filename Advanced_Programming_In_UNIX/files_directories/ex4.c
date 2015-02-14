#include<stdio.h>
#include<sys/stat.h>

int main(int argc,char* argv[])
{
	int a = creat("vamshi",S_IRUSR|S_IWUSR);
	if( a < 0 )
	{
		perror("creat");	
	}
}

