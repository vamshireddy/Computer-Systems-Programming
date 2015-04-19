int main(void)
{
	int* stuff = malloc(sizeof(int)*1);
	*stuff = 7;
	int pid = fork();
	printf("Stuff is %d", *stuff);
	if (pid == 0)
		*stuff = 6;
}
