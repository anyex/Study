#include "stdio.h"
extern int m;
extern int n;

void swap(int a,int b)
{
   printf("&a = %p,&b = %p\n",&a,&b);
   printf(" m = %d,n = %d\n ",m,n);

   int t = a;
   a = b;
   b = t;

   printf("m = %d,n = %d\n",m,n);

}

int main()
{
   m = 10,n = 20;
   printf("&m = %p,&n = %p\n",&m,&n);
   swap(m,n);
   printf("m = %d, n = %d\n",m,n);

   return 0;

}

