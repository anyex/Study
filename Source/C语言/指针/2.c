#include "stdio.h"

typedef struct MyStruct
{
   int a;
   int b;
   int c;
   char d;
}A;



int main()
{
		A ss = {20,30,40,'A'};
		A *ptr = &ss;
		int *pstr = (int*)&ss;
        
		printf("ss.a = %d,pstr获取a = %d\n",ptr->a,*pstr);
        printf("ss.b = %d,pstr获取b = %d\n",ptr->b,*(pstr+1));

		return 0;
      
}

/*
 *
 *
 *
 * */
