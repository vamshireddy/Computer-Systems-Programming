#include<stdio.h>
#include<time.h>


/*
Design a random function which takes in the probabilities of the numbers and return the numbers according the probabilities when called.
*/

int rand3(int a)
{
	if( a <= 10 )
	{
		return 3;
	}
	else if( a <=20 ) 
	{
		return 4;
	}
	else
	{
		return 9;
	}
}

int main()
{
	time_t t = time(NULL);
	srand(&t);
	printf("Time is : %d\n",t); 
	int a = rand();
	printf("%d\n",a%100);
	// Assuming 3 - 10%, 4 - 10% , 9 - 80%
	printf("%d is the random according to the probability given \n",rand3(a%100));
}
