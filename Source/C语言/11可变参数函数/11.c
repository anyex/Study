#include "stdio.h"
#include "stdarg.h"
typedef struct test{
   int a;
   char name[10];

}test;




void prin(int b,...)
{
   va_list v;
   va_start(v,b);
   test a = va_arg(v,test);
   va_end(v);
   printf("test:\t%s,\t%d\n",a.name,a.a);


}

int main()
{
   test a = {2,"测试"};    
   prin(1,a);

   return 0;
}

/*
 *   结果：
 *   test:test测试,测试2
 *   此处用结构体实现了可变参数函数，其他类型也类似
 *
 *
 * */


