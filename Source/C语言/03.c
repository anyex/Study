#include "stdio.h"
int main()
{
   int a,b,c,d;
   a=b=c=d=0;//连续的赋值从右向坐进行计算
   a++;
   ++b;

   printf("%d,%d\n",a,b);
   printf("%d,%d\n",c++,++d);

   return 0;

}
