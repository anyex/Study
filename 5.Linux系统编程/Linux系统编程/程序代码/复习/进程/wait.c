#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
void main()
{
	pid_t pid;
	
	pid = fork();
	
	if(pid > 0)
	{
		wait(NULL);
		printf("父进程\n");
		exit(0);
	}else{
		printf("子进程\n");
		exit(0);
	}
	
}