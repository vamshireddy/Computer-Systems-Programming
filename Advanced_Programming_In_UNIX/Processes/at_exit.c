#include <stdio.h>
#include <error.h>

static void my_exit1(void);
static void my_exit2(void);

int main()
{
	if( atexit(my_exit2) !=0 )
	{
		perror("Can't register");
	}
	if( atexit(my_exit1) !=0 )
	{
		perror("Can't register");
	}	
	if( atexit(my_exit1) !=0 )
	{
		perror("Can't register");
	}	
	printf("main is done\n");
	exit(123);
}

static void my_exit1(void)
{
	printf("First exit hanlder\n");
}
static void my_exit2(void)
{
	printf("Second exit hanlder\n");
}
