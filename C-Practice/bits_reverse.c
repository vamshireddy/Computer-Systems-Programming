include<stdio.h>

int main()
{
	unsigned int a = 0xFFFFFFFF;
	printf("%x\n",a);
	unsigned int p = a >> 8;
	printf("%x\n",p);
	p = p << (16);
	printf("%x\n",p);
	p = p >> (32-24);
	printf("ff %x\n",p);

	printf("%x\n",~p&a);
}
