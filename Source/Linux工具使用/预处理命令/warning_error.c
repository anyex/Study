#include <stdio.h>



#if (VERSION<3)//如果VERSION<3
   #error "版本太低" //产生错误
#elif(VERSION>3)//如果VERSION>3
   #warning "版本太高" //产生警告

#endif

int main()
{
  printf("版本：%d\n",VERSION);

  return 0;

}

/*
 使用gcc wraning_error.c -o main -DVERSION=2编译，即传入VERSION的值为2候会产生错误，并提示版本太低并终止编译
 使用gcc wraning_error.c -o main -DVERSION=4编译，即传入VERSION的值为4候会产生警告，并提示版本太高
 
 使用gcc wraning_error.c -o main -DVERSION=3编译，输出版本:3

 
*/
