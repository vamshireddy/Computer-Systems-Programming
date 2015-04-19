#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int foo(int n){
	if (n < 2) {
		exit(n);
	} else {
		int v1;
		int v2;
		int pid = fork();
		if (pid == 0)
			foo(n - 1);
		int pid2 = fork();
		if (pid2 == 0)
			foo(n - 2);
		waitpid(pid,&v1,0);
		waitpid(pid2,&v2,0);
		exit(WEXITSTATUS(v1) + WEXITSTATUS(v2));
	}
}
int main(int argc,char* argv[]) {
	foo(atoi(argv[1]));
}
