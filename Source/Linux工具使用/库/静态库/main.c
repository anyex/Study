#include "calc.h"
#include "show.h"

int main()
{
  show(30,'+',20,add(30,20));
  show(30,'-',20,sub(30,20));

  return 0;
 
}

/*
首先得到编译得到calc.o show.o两个文件
然后用ar -r libmath.a calc.o show.o将两个文件打包成静态库
最后gcc main.c libmath.a编译链接静态库

调用静态库的方法还可以是：
	gcc main.c -lmath -L.(-L.指定优先寻找当前文件夹)

      或gcc main.c -lmath (静态库必须包含在可寻找的目录下)

  

*/
