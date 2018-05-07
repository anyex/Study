#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    //标准c文件函数
	FILE* file = fopen("a.txt","w");//获取文件指针
    if(file == NULL)
        perror("open"),exit(-1);
     int i;

	 for(i=0;i<10000;i++)
	 {
		 fwrite(&i,4,1,file);

	 }

	 fclose(file);
	//UC 文件函数
	
	 int arr[10000];//数组做缓冲
	 int fd = open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
	 if(fd == -1)
		 perror("open"),exit(-1);
	 int i ;
	 
	 for(i=0;i<10000;i++)
	 {
	     arr[i%10000]=i;
		 if(i%10000 == 9999)
			 write(fd,arr,sizeof(arr));
	 }

	 close(fd);

	 return 0;
  
}
