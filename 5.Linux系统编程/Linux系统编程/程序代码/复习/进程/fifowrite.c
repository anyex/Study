#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int ret = -1,fd = 0;
	ret = mkfifo("fifo",0666);
	
	if(ret !=-1 )
	{
		fd = open("fifo",O_WRONLY);
		if(fd !=-1 )
		{
			write(fd,"hello",5);
		}
		else
		{
		   printf("打开管道文件失败\n");	
		}
	}
	else
	{
		printf("创建管道文件失败\n");
		return 0;
	}
	
	return 0;
	
	
}