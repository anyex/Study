#include "stdio.h"

int main()
{
   int n;
   double d;
   char str[100];
   fprintf(stderr,"请输入姓名，年龄，体重：");//使用stderr没有缓冲操作
   fscanf(stdin,"%s%d%lf",str,&n,&d);//stdin从标准输入中(键盘，把键盘当作文件读取)
   //sleep(2000);
   fprintf(stdout,"%s:%d岁，%g公斤",str,n,d);//stdout(显示到屏幕上,把屏幕当作文件，操作系统把设备都时当中文件来处理)从标准输出中读取

   return 0;


}
