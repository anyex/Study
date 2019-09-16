#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void myfunc(int a)
{
	printf("获取到一个信号");
}

int main(int argc,char *argv[])
{
	pid_t pid;
	
	pid = atoi(argv[1]);
	
	kill(pid,SIGUSR2);
	
	return 0;
	
}