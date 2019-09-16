#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void myfunc(int a)
{
	printf("获取到一个信号");
}

int main()
{
	
	signal(SIGUSR2,myfunc);
	pause();
	return 0;
	
}