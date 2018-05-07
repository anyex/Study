#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main()
{
   printf("%d\n",getpid());//获取当前进程的id
   char* p1 = malloc(1);//分配1字节
   printf("%p\n",p1);
   //getchar();
   char* p2 = malloc(2);
   printf("每页%d字节",getpagesize());
   //getchar();
   free(p2);
   free(p1);

   getchar();

   return 0;

}
