#include<stdio.h>

#define paste(f,b) f##b

int main()
{
	printf(paste(hello,world));
}
