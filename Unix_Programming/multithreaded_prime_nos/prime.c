#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

void* prime_no(void* num)
{
	int* n = (int*)num;
	int number = *n;
	int array[number];
	int i,j;
	for(i=1;i<number;i++)
	{
		array[i] = i;
	}
	for(i=2;i<number;i++)
	{
		if(array[i]!=-1)
		{
			//printf("%d     ",array[i]);
			for(j=i+i;j<number;j = j + i)
			{
				array[j] = -1;
			}
		}
	}
	for(i=1;i<number;i++)
	{
		if(array[i]!=-1)
		printf("%d  ",array[i]);
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,prime_no,(void *)&a);
	//char num2[5];
	//scanf("%s",num2);
	//pthread_create(&t2,NULL,prime_no,(void *)num2);
	pthread_join(t1,NULL);
	//pthread_join(t2,NULL);
	printf("Thread finished executing. I am main\n");
}
