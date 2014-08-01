#include<stdio.h>

int get_val(char c)
{
	switch( c )
	{
		case 'a':
		case 'A':	return 10;
		case 'b':
		case 'B':	return 11;
		case 'c':
		case 'C':	return 12;
		case 'd':
		case 'D':	return 13;
		case 'e':
		case 'E':	return 14;
		case 'f':
		case 'F':	return 15;

		default:	return c-'0';
	}
}

int get_hexa_value(char* str)
{
	int i = 0;
	int len = strlen(str);
	if( str[0] == '0' && str[1]=='x')
	{
		// its prefixed by 0x
		i = i+2;
	}
	

	int value = 0;
	for(;i<len;i++)
	{
		int k = get_val(str[i]);
		printf(" k is %d\n",k);
		value = value * 16 + k;
	}
	return value;
}

int main()
{
	char hexa[10];
	printf("Enter the Hexa decimal number with 0x: ");
	scanf("%s",hexa);
	printf("value is %d\n",get_hexa_value(hexa));
}
