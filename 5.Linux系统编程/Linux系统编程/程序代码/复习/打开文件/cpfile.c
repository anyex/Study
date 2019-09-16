#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argv,char** args)
{
	int fd_s;
	int fd_t;
	
	int count ;
	char buf[512];
	printf("args[0]:%s\n",args[0]);
	printf("args[1]:%s\n",args[1]);
	printf("args[2]:%s\n",args[2]);
	fd_s = open(args[1],O_RDONLY);
	fd_t = open(args[2],O_RDWR|O_CREAT,0666);
	
	while((count = read(fd_s,buf,512))>0)
	{
		write(fd_t,buf,count);
	}
	
	close(fd_s);
	close(fd_t);
	return 0;
	
}