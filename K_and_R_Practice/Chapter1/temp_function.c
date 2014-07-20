#include<stdio.h>
#include<unistd.h>

/*
Converts the temperature from celsius to fahrenheit 
*/

int celsius_to_fahren(int cel_temp)
{
	int result;
	result = (cel_temp*9/5.0) + 32;
	return result;
}


int main(int argc,char* argv)
{
	printf("%d\n",celsius_to_fahren((int)argv));
}
