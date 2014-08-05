#include<stdio.h>
#include<string.h>
void convert_to_any_base(int i,char* s,int base)
{
	int sign;
	if( i < 0 )
	{
		sign = i;
		i = -i;
	}
	int index = 0;
	while( i > 0 )
	{
		int rem = i % base;
		printf("rem is %d\n",rem);
		if( rem > 9 )
		{
			int num = rem;
			while( num > 0 )
			{
				int remmy = num%10;
				printf("remmy is %d\n",remmy);
				s[index++] = remmy + '0';
				num = num/10;
			}
			s[index++] = ' ';
		}
		else
		{
			s[index++] = rem + '0';
		}
		i = i/base;
	}
	if( sign < 0 )
	{
		s[index++] = '-';
	}
	s[index] = '\0';
	printf("i is %d\n",index);
	reverse(s);
}

void reverse(char s[])
{
	int i,j;
	for(i=0,(j=strlen(s)-1);i<j;i++,j--)
	{
		printf("%c\n",s[i]);
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main()
{
	char s[20];
	convert_to_any_base(-250,s,16);
	printf("%s\n",s);
}

