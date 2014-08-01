#include<stdio.h>


int main()
{
	printf("Range of signed char is %d to %d\n",(char)0x80,(char)0x7F);
	printf("Range of unsigned char is %u to %d\n",0x00,0xFF);
	printf("Range of signed short is %d to %d\n",(short)0x8000,(short)0x7FFF);
	printf("Range of unsigned short is %u to %u\n",(short)0x0000,(short)0xFFFF);
	printf("Range of signed int is %d to %d\n",(int)0x80000000,(int)0x7FFFFFFF);
	printf("Range of unsigned int is %u to %u\n",(int)0x0,(int)0xFFFFFFFF);
}
