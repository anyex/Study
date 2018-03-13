#include "stdio.h"
#include "add.h"

int main()
{

  printf("%d\n",add(123,456));
  return 0;

}

/*
在其中因为#include<>只能找系统目录下的头文件，而add.h位于当前文件目录，所以会
         gcc add.c main.c -o main编译出错
应该使用gcc add.c main.c -o main -I.
其中-I.将当前目录指定为优先查找的头文件目录，然后再查找默认的目录
默认的头文件目录由C_INCLUDE_PATH环境变量指定
   #include <>寻找系统目录下的头文件，#include ""优先寻找当前文件目录下的头文件，然后寻找系统目录下的头文件
*/
