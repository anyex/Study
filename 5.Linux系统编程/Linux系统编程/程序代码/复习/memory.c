#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
int a = 0;
int b;
static int  c = 0;
static int  d ;
const int e = 0;
const int f;
int main()
{
   printf("&a = %p\n",&a);
char* g = (char*)malloc(1);
   printf("&b = %p\n",&b);
   
   printf("&c = %p\n",&c);
   printf("&d = %p\n",&d);
   printf("&e = %p\n",&e);
   printf("&f = %p\n",&f);
   printf("&g = %p\n",&g);
   printf("%d\n",getpid());
   while(1)
   {
           
   }

   
}
