#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = -1;
	
	fd = open("test.txt",O_RDWR|O_CREAT,0666);
	if(fd == -1)
		printf("打开文件失败");
	
	return 0;
}