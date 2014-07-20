#include<stdio.h>

/*
	Program to print a table consisting of the temperatures in both celcius and fahrenheit
*/

int main()
{
	int start;
	scanf("%d",&start); /* Starting temperature */
	int end;
	scanf("%d",&end);   /* Ending temperature */
	int step;
	scanf("%d",&step);  /* Step increment value */

	float res = 0;
	int i;
	for(i=end;i>=start;i=i-step)
	{
		res = (5.0/9.0)*(i-32.0);
		printf("%3d\t%.1f\n",i,res);
	}
}
