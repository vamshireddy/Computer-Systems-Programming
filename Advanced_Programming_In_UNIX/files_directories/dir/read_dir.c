#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>

int main()
{
	DIR* d = opendir("/");
	if( d == NULL )
	{
		perror("opendir");
		exit(0);
	}
	struct dirent* pointer = readdir(d);
	int i;
	for( i=0; pointer!=NULL; i++)
	{
		printf("%s -> %d\n",pointer->d_name,(int)pointer->d_ino);
		pointer = readdir(d);
	}
}
