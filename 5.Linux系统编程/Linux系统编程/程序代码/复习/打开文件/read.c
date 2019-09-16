#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd = -1;
	char buf[100] = {0};
	int ret = 0;
	fd = open("test2.txt",O_RDWR|O_CREAT,0666);
	if(fd == -1)
	{
		printf("打开文件失败");
	}
	 
	ret = read(fd,buf,5);
	if(ret>0)
		printf("读取的内容：%s\n",buf);
	
	ret = write(fd,"abcdefg",7);
	
	if(ret>0)
		printf("写入的数据：abcdefg\n");
	close(fd);
	
	return 0;
}