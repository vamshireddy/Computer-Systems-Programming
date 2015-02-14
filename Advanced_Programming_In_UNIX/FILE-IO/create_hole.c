#include<stdio.h>
#include<fcntl.h>



int main(int argc,char* argv[])
{
	int a = open(argv[1],O_RDWR);
	if( a == -1 )
	{
		perror("Open");
	}
	
	int err = lseek(a,100,SEEK_CUR);

	if( err == -1 )
	{
		perror("lseek");
	}

	write(a,"Vamshi",7);
}
