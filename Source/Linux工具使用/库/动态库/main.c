#include "calc.h"
#include "show.h"

int main()
{
  show(30,'+',20,add(30,20));
  show(30,'-',20,sub(30,20));

  return 0;
 
}

/*
 
  生成动态库
     1.编译
	gcc -c -fpic calc.c
        gcc -c -fpic show.c
     2.生成动态库
	gcc -shared calc.o show.o -o libmath.so
  加载动态库
	1.静态加载
		gcc main.c -lmath -L.
          运行时要保证LD_LIBRARY_PATH环境变量中包含共享库所在的路径
*/
