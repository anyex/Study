#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void main()
{
	
	
	int count = 0;
	
	pid_t pid =  fork();
	count++;
	printf("count = %d\n",count);
    exit(0);
}