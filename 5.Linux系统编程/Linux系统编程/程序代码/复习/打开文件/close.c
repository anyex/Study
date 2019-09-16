#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd = -1;
	int ret = -1;
	fd = creat("test2.txt",666);
	if(fd != -1)
	{
		printf("创建文件成功，描述符为：%d",fd);
	}
	else
		printf("创建文件描述符失败");
     
	ret = close(fd);
	 
	if(ret == 0)
		printf("关闭文件成功");
	if(ret == -1)
		printf("关闭文件失败");
	 
	return 0;
}