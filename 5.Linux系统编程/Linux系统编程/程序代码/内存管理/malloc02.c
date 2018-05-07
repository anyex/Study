#include "stdio.h"
#include "stdlib.h"
int main(void)
{
   int* p1 = malloc(sizeof(int));
   int* p2= malloc(sizeof(int));
   
   printf("%p ,%p\n",p1,p2);
   free(p2);
   p1[0]=0;//p1[3] = 0;//因为p1[3]是未分配的内存，即未映射，所以也不能正常使用
   free(p1);

   return 0;

}
