#include<stdio.h>


int main(int argc,char* argv[])
{
	char buff[1024];
	getcwd(buff,1024);
	printf("Current working directory: %s\n",buff);
	chdir("/");
	printf("After changing the directory\n");	
	getcwd(buff,1024);
	printf("Current working directory: %s\n",buff);
}
