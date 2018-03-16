#include "stdio.h"
int main()
{
   
           //格式化输出.
		  printf("aaa%ibbb%fccc%cddd\n",123,45.6,65);
		  printf("aaa%ibbb%fccc%cddd\n",123,45.6,'s');						
		  printf("%x,%o",763,763);
		  printf("%g\n",45.6);
          return 0;
}

/*
 *
 *
 输出结果
aaa123bbb45.600000cccAddd
aaa123bbb45.600000cccsddd
2fb,137345.6

 
 */
