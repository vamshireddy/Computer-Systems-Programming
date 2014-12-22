#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t p;

	p = fork();

	if(p==0)
	{
		printf("Enter the Number : \n");
		int a;
		scanf("%d",&a);
		int i;
		int temp1=0,temp2=1;
		if(a==1)
		{
			printf("%d\n",temp1);
		}
		else if(a==2)
		{
			printf("%d\n",temp1);
			printf("%d\n",temp2);
		}
		else if(a>=2)
		{
		
			printf("%d\n",temp1);
			printf("%d\n",temp2);
			for(i=0;i<a;i++)
			{
				int temp = temp1+temp2;
				printf("%d\n",temp);
				temp1 = temp2;
				temp2 = temp;
			}
			printf("Done\n");
		}
		return 0;
	}
	else if(p>0)
	{
		wait(NULL);
		return 0;
	}
}
