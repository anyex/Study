/*************************************************************************
    > File Name: lseek.c
    > Author: jth
    > Mail: 1174932183@qq.com 
    > Created Time: Thu 03 May 2018 11:51:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int fd = open("a.txt",O_RDWR);
	
	if(fd == -1)
		perror("open"),exit(-1);
	char c;

	read(fd,&c,1);
	printf("1 %c\n",c);//a

    read(fd,&c,1);
	printf("2 %c\n",c);//b
	
	lseek(fd,0,SEEK_SET);//回到文件开头
	read(fd,&c,1);
	printf("3 %c\n",c);//a
    
	lseek(fd,0,SEEK_END);//文件指针移动到文件末尾的前两个字符
	read(fd,&c,1);
//	if(c == '\n')
	printf("4 end = 是换行符''%c\n",c);


	lseek(fd,-1,SEEK_CUR);//此时当前指针为文件末尾，前移一个应该为g
	read(fd,&c,1);
	printf("5 end - 1 = %c\n",c);//g

return 0;

}
