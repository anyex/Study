#include "stdio.h"
union var{
   long j;
   int i;
};
int main()
{
  union var v;
  v.j = 5;
  printf("v.i = %d,v.j = %ld\n",v.i,v.j);
  v.i = 6;

  printf("v.j =%ld ,内存地址:%p\n",v.j,&v.j);
  
  printf("v.i =%d ,内存地址:%p\n",v.i,&v.i);
  return 0;
}


/**************
 *
 *
 *v.i = 5,v.j = 5
 v.j =6 ,内存地址:0xbff2bba8
 v.i =6 ,内存地址:0xbff2bba8
 *说明每次赋值都会进行覆盖，二者的值相同
 * ***************/
