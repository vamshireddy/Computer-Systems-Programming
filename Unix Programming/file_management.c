#include <sys/types.h>
 #include <fcntl.h>
 #include<stdio.h>

int main()
{
	int src_file = open("use.txt",O_RDWR,0600);
	if(src_file==-1)
	{
		printf("Error opening src file\n");
		return;
	}
	int dst_file = open("t.txt",O_RDWR|O_CREAT,0600);
	if(dst_file==-1)
	{
		printf("Error opening dst file\n");
		return;
	}

		char c[10];
		read(src_file,c,10);
		write(dst_file,c,10);

	close(src_file);
	close(dst_file);
}
