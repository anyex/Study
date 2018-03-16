#include "stdio.h"
#include "09.h"
extern int m;
extern int n;

void swap(int a,int b)
{
   printf("&a = %p,&b = %p\n",&a,&b);
   printf("交换前 m = %d,n = %d\n ",m,n);

   int t = a;
   a = b;
   b = t;

   printf("m = %d,n = %d\n",m,n);

}

int main()
{
 //  m = 10,n = 20;
   printf("&m = %p,&n = %p\n",&m,&n);
   swap(m,n);
   printf("交换后 m = %d, n = %d\n",m,n);

   return 0;

}
/*
 *
 *&m = 0x804a01c,&n = 0x804a020
 &a = 0xbfbdf760,&b = 0xbfbdf764
 交换前 m = 10,n = 5
  m = 10,n = 5
  交换后 m = 10, n = 5
  说明不能完成交换，因为a,b的值与m,n的值不同，所以这里只传值，相当于执行了int a =m,int b = n

 *
 * */
