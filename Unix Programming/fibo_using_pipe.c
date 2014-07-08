#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
	int fd[2];
	pid_t pid;

	int pipe_id = pipe(fd);

	if( pipe_id == -1 )
	{
		printf("Error in creating pipe\n");
	}

	pid = fork();

	if ( pid < 0 )
	{
		printf("Error in fork() \n");
	}
	else if( pid==0 )
	{
		close(fd[1]);
		char readmsg[10];
		read(fd[0],readmsg,10);
		int no = atoi(readmsg);
		if(no<0)
		{
			printf("Retryu using positive number \n");
			return;
		}
		int temp1=0,temp2=1;
		if(no==0)
		{
			printf("0\n");
		}
		else if(no==1)
		{
			printf("0\n1\n");
		}
		else 
		{

			printf("0\n1\n");
			int i;
			for(i=0;i<no;i++)
			{
				int temp = temp1+temp2;
				printf("%d\n",temp);
				temp1 = temp2;
				temp2 = temp;
			}
		}
		close(fd[1]);
	}
	else if( pid>0 )
	{
		close(fd[0]);
		char p[10];
		printf("Enter the Number : ");
		scanf("%s",p);
		write(fd[1],p,10);
		close(fd[1]);
		wait(NULL);
	}
}
