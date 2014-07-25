#include<stdio.h>
#include<fcntl.h>
#define MAX_LENGTH 1000


int dup2(int fd1,int fd2)
{
	int array[MAX_LENGTH];
	// This will return the new file descriptor with its value equal to fd2
	if( fd1 == fd2 )
	{
		return fd1;
	}
	else
	{
		int new_fd,pointer=0;
		while( 1 )
		{
			new_fd = dup(fd1);
			
			if( new_fd == fd2 )
			{
				break;
			}
			else
			{
				array[pointer++] = new_fd;
			}
		}
		// Now close all the outstanding fd's

		int i;
		for(i=0;i<pointer;i++)
		{
			// Close the descriptor stored in the array
			printf("%d ",array[i]);
			close(array[i]);
		}
		return new_fd;
	}
}

int main()
{
	int a;
	int fd = open("hello",O_RDWR);
	printf("Opened file\nEnter the new file desciptor\n");
	scanf("%d",&a);
	int newfd = dup2(fd,a);
	printf("\nThe new file descriptor obtained is %d and the old one is %d\n",newfd,fd);
	write(newfd,"Helloi",6);
}
