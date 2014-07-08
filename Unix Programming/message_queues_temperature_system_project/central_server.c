#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

struct msgp
{
	long priority;
	int temp;
	int pid;
	int stable;
};

int main()
{
	int temp;
	printf("Enter the Initial Temperature of the server : ");
	scanf("%d",&temp);
	//Message to be send.
	struct msgp new_central_temp;
	new_central_temp.priority = 2;
	new_central_temp.pid = 0;
	//Message which is to be recieved is stored here
	struct msgp mp_recv;
	//Creating the queues for sending and recieving
	// msg_src is the recieving mail box for the central server
	int msg_src = msgget(1234,0600|IPC_CREAT);
	// msg_dst_x is the queue in the process x, for which the central server will send messages
	int msg_dst_1 = msgget(1,0600|IPC_CREAT);	
	int msg_dst_2 = msgget(2,0600|IPC_CREAT);
	int msg_dst_3 = msgget(3,0600|IPC_CREAT);
	int msg_dst_4 = msgget(4,0600|IPC_CREAT);
	//msg is recieved here
	//Process started
	int temp1,temp2,temp3,temp4;
	while(1)
	{
		msgrcv(msg_src,&mp_recv,sizeof(struct msgp)-sizeof(long),2,0);
		temp1 = mp_recv.temp;
		printf("temp1=%d\n",temp1);
	//	memset((void*)mp_recv,0,sizeof(struct msgp));
		msgrcv(msg_src,&mp_recv,sizeof(struct msgp)-sizeof(long),2,0);
		temp2 = mp_recv.temp;
		printf("temp2=%d\n",temp2);
	//	memset((void*)mp_recv,0,sizeof(struct msgp));
		msgrcv(msg_src,&mp_recv,sizeof(struct msgp)-sizeof(long),2,0);
		temp3 = mp_recv.temp;
		printf("temp3=%d\n",temp3);
	//	memset((void*)mp_recv,0,sizeof(struct msgp));
		msgrcv(msg_src,&mp_recv,sizeof(struct msgp)-sizeof(long),2,0);
		temp4 = mp_recv.temp;
		printf("temp4=%d\n",temp4);
	//	memset((void*)mp_recv,0,sizeof(struct msgp));
		printf("All the temps are %d %d %d %d\n",temp1,temp2,temp3,temp4);
		if((temp1^temp2^temp3^temp4)==0)
		{
		//	printf("Hip hip \n");
			new_central_temp.stable = 1;
		}
		else
		{
			new_central_temp.stable = 0;
		//	printf("Hurray\n");
		}
		temp = ((2*temp)+temp1+temp2+temp3+temp4)/6;
		new_central_temp.temp = temp;
		printf("The new central temperature is %d\n",temp);
		msgsnd(msg_dst_1,&new_central_temp,sizeof(struct msgp)-sizeof(long),0);
		msgsnd(msg_dst_2,&new_central_temp,sizeof(struct msgp)-sizeof(long),0);
		msgsnd(msg_dst_3,&new_central_temp,sizeof(struct msgp)-sizeof(long),0);
		msgsnd(msg_dst_4,&new_central_temp,sizeof(struct msgp)-sizeof(long),0);
		printf("Message to processs has been sent \n");
		if((temp1^temp2^temp3^temp4)==0)
		{
			break;
		}
		usleep(2000000);
	}
	printf("\nEvery thing is stable now \n");
}
