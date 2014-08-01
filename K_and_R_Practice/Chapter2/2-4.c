#include<stdio.h>

void squeeze(char*s1, char* s2)
{
	int i,j;
	int flag,p;
	for(i=j=0;s1[j]!=0;j++)
	{
		flag = 0;
		for(p=0;s2[p]!=0;p++)
		{
			if(s2[p] == s1[j])
			{
				flag = 1;
				break;
			}
		}

		if( flag == 0 )
		{
			s1[i++] = s1[j];
		}
	}
	s1[i] = 0;
}

int main(int argc,char* argv[])
{
	char str[100];
	strcpy(str,argv[1]);
	squeeze(str,argv[2]);
	printf("%s\n",str);
}
