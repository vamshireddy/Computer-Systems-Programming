#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>


struct msg_q
{
	long priority;
	int temp;
	int pid;
	int stable;
};

int main()
{
	printf("Enter the Initial Temperature : \n");
	int temp;
	scanf("%d",&temp);
	printf("Enter the process number : \n");
	int no;
	scanf("%d",&no);
	struct msg_q mq;
	mq.priority = 2;
	mq.temp = temp;
	mq.pid = no;
	mq.stable = 0;
	int msg_src = msgget(no,0600|IPC_CREAT);
	int msg_dst = msgget(1234,0600|IPC_CREAT);
	msgsnd(msg_dst,&mq,sizeof(struct msg_q)-sizeof(long),0);
	struct msg_q rcv;

	while(1)
	{
		msgrcv(msg_src,&rcv,sizeof(struct msg_q)-sizeof(long),2,0);
		printf("The message is recieved\ncentral temp is %d\nstable=%d\n",rcv.temp,rcv.stable);
		if(rcv.stable==1)
		{
			printf("Process %d is stable now\n Everything is fine\n",no);
			break;
		}

		temp = (temp*3 + 2*rcv.temp)/5;
		mq.temp = temp;
		msgsnd(msg_dst,&mq,sizeof(struct msg_q)-sizeof(long),0);
	}
}
