#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char** argv = (char**) malloc(3*sizeof(char*));
	argv[0] = "/bin/ls";
	argv[1] = ".";
	argv[2] = NULL;
	for (int i = 0; i < 10; i++){
		printf("%d\n", i);
		if (i == 3)
		{
			int a = fork();

			if( a == 0 )
			{
				execv("/bin/ls", argv);
			}
		}
	}
}
