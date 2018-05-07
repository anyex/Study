/*************************************************************************
    > File Name: fcntl.c
    > Author: jth
    > Mail: 1174932183@qq.com 
    > Created Time: Wed 02 May 2018 01:06:25 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd = open("a.txt",O_RDWR|O_CREAT|O_APPEND,0666);

	if(fd == -1)
		perror("open"),exit(-1);
	int flags = fcntl(fd,F_GETFL);
	printf("flags = %d\n",flags);

	if(flags & O_APPEND)
		printf("APPEND\n");
	if(flags & O_CREAT)
		printf("CREAT\n");
	if(flags & O_RDWR)
		printf("RDWR1\n");
	if(flags & O_RDONLY)
		printf("RDONLY1\n");
    if((flags&3)==O_RDWR)//权限由后两位决定所以要和3相与
		printf("RDWR2\n");
	if((flags&3)==O_RDONLY)
		printf("RDONLY2\n");
	close(fd);
	return 0;

}
