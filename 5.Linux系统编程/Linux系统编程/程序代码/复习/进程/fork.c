#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	pid_t pid =  fork();
	
	if(pid == 0)
	{
		printf("子进程\n");
	}
		
		printf("父进程\n");
	
	exit(0);
	
}