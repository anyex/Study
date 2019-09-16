#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pipefd[2];
	char buf[64] = {0};
	pipe(pipefd);
	
	pid_t pid =  fork();
	
	if(pid == 0)
	{
		read(pipefd[0],buf,6);
		printf("子进程接收到%s\n",buf);
		exit(0);
	}
	else
	{
		write(pipefd[1],"hello",6);
		exit(0);
	}	
		
	
	return 0;
	
}