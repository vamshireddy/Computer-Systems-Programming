int main(void)
{
	int stuff = 7;
	int pid = fork();
	if( pid >0 )
	{
			sleep(10);
	}
	printf("Stuff is %d", stuff);
	if (pid == 0)
		stuff = 6;
}
