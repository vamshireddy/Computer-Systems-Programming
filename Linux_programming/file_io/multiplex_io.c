#include<stdio.h>
#include<sys/select.h>
#include<sys/time.h>
#include<sys/types.h>

#define TIMEOUT 10
#define BUF_LEN 1024

int main()
{
	struct timeval tv;
	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 10;

	fd_set set;

	FD_ZERO(&set);

	FD_SET(1,&set);

	int f = select(1,&set,NULL,NULL,&tv);
	printf("Waited for 10 seconds with 1 ");
}
