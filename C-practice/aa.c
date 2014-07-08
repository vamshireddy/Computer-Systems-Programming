#define HELLO while(1)

int main()
{
	//int a[10][10][10];
	//printf("p = %d\n",sizeof(a[1]));
	//printf("i = %d\n",sizeof(a[1][1]));
	int (*p)[100];
	HELLO
	printf("%d %d\n",sizeof(p[0]),100%90);
}
