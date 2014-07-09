int main()
{
	int a[3][3][3];
	int i,j,k;

	int count = 0;

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
			{
				a[i][j][k] = count;
				count++;
			}
	int *p = a;
	for(i=0;i<27;i++)
	{
		printf("%d\n",*(p+i));
	}
	printf("\n\n%d",*(p+18+8));
	double *ptr;
	printf("\n%d is the size of void \n\n\n",sizeof(ptr));

	int h[2] = {1,12};
	char *ph = &h;

	printf("%d\n",*((int*)ph));
	printf("%d\n",*((int*)(ph+4)));
}
