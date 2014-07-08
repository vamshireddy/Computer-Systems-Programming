#include<stdio.h>

int main()
{
	unsigned int i,x,y;
	printf("Enter x in x^y : ");
	scanf("%d",&x);
	printf("Enter y in x^y : ");
	scanf("%d",&y);

	unsigned int result = 1;
	if( x == 2 )
	{
		result = 1<<y;
	}
	else
	{
		for(i=0;i<y;i++)
		{
			result*=x;
		}
	}

	printf("Result: %d\n",result);
	return 0;
}


