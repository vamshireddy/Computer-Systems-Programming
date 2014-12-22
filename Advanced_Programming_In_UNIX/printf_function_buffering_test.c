// This is used to test when printf buffers the data, when it outputs the data to the std out.


#include<stdio.h>


int main()
{
	char* s = "Vamshi";
	char* t = "Reddy";

	printf(s);
	sleep(2);
	printf("Sleep finished   ");
	printf(t);
	sleep(2);
	printf("Sleep finished   ");

	printf("\nNow printing the statements with \\n \n");

	printf("%s\n",s);
	sleep(2);
	printf("Sleep finished   ");
	printf("%s\n",t);
	sleep(2);
	printf("Sleep finished   ");
}
