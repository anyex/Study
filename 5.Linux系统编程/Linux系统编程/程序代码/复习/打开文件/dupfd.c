#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd = -1;
	int newfd = -1;
	int ret = 0;
	fd = open("test.txt",O_RDWR|O_CREAT,0666);
	if(fd == -1)
		printf("打开文件失败");
	
	newfd = dup(fd);
	close(fd);
	lseek(newfd,0,SEEK_END);
	ret = write(newfd,"123456",5);
	
	
	
	return 0;
}