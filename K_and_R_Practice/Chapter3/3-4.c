#include<stdio.h>

void itoa(int n, char s[])
{
	int i,sign;

	if( (sign = n) < 0 )
	{
		n = -n;
		if( n == -n )
		{
			// its -ve large number
			strcpy(s,"-2147483648");
		}
	}
	return;
}

int main()
{
	char s[20];
	itoa(0x80000001,s);
	printf("%s\n",s);
}
