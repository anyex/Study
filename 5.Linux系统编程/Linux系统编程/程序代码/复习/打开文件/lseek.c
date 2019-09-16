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
	
	ret = write(fd,"abcdefgfafdas",7);
	lseek(fd,0,SEEK_END);
	ret = write(fd,"_end",4);
	lseek(fd,0,SEEK_SET);
	ret = write(fd,"start_",6);


	close(fd);
	
	return 0;
}