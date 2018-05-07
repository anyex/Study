/*************************************************************************
    > File Name: 非读写函数.c
    > Author: jth
    > Mail: 1174932183@qq.com 
    > Created Time: Wed 02 May 2018 12:08:56 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("a.txt",O_RDWR);
	if(fd == -1)
		perror("open"),exit(-1);
	int fd2 = dup(fd);

	printf("fd = %d,fd2 = %d\n",fd,fd2);

	int fd3 = dup2(fd,5);
	printf("fd3=%d\n",fd3);

	int fd4=open("b.txt",O_RDWR|O_CREAT,0666);
	int fd5 = dup2(fd,6);
	write(fd5,"HEHE",4);
    close(fd);

	return 0;

}



