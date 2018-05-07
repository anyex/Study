/*
 *用uc函数实现文件的拷贝
 读a.txt，然后把读到内荣写入b.txt
 * */
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <fcntl.h>

int main()
{
  int fdr = open("a.txt",O_RDWR);
  if(fdr == -1)
		perror("open a"),exit(-1);
  int fdw = open("b.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
  if(fdw==-1)
		 perror("open a"),exit(-1);
  char buf[100] = {};
  while(1)
	{
	   int res = read(fdr,buf,sizeof(buf));
       if(res == -1)
	   {perror("read");break;}
	   if(res==0)
			   break;
	   write(fdw,buf,res);
	}
  return 0;
}
