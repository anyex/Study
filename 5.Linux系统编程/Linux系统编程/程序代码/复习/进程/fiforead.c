#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
		int fd = 0;
		char buf[10] = {0};
		fd = open("fifo",O_RDONLY);
		if(fd > 0)
		{
			read(fd,buf,5);
			printf("从管道文件获取的数据：%s",buf);
		}
		else
		{
			printf("打开fifo失败\n");
		}
	
	
	return 0;
	
	
}