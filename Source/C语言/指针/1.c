#include "stdio.h"

int main()
{
   char a[20];
   printf("a = %p\n",a);
   int *ptr = (int *)a;
   printf("ptr = %p\n",ptr);
   ptr++;
   printf("ptr++ = %p\n",ptr);

   return 0;


}

/*
 *
 *a = 0xbf803248
 ptr = 0xbf803248
 ptr++ = 0xbf80324c

 * */
