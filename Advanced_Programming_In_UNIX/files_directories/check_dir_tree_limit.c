#include<stdio.h>



int main()
{
	int i;
	for(i=0;i<100;i++)
	{
		int r = mkdir("hell",0777);
		if( r == -1 )
		{
			perror("mkdir");
		}
		
		int j = chdir("hell");
		if( j == -1 )
		{
			perror("mkdir");
		}
	}
	system("pwd");
}
