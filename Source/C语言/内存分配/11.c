#include "stdio.h"
#include "stdlib.h"

int main()
{
   int b = sizeof(double);
   double* p = (double*)malloc(b);
   int cnt;
   printf("请输入元素的个数");
   scanf("%d",&cnt);
   int *a = calloc(cnt,sizeof(int));
   
   if(a == NULL)
	{
	   printf("申请空间失败\n");
	   return 1;
	}

   *p = 123.45;
   int i;
   for(i = 0;i < cnt; i++)
	{
	   a[i] = i+10;
	}
   printf("%g\n",*p);
   
   for(i = 0; i<cnt;i++)
     printf("%d\t",a[i]);
   printf("\n");

   free(p);
   a = realloc(a,sizeof(int)*10);
   for(i=0;i<10;i++)
		 printf("%d\t",a[i]);
   printf("\n");
   
   a = realloc(a,0);
   printf("a=%p\n",a);
   return 0;







}




/*
 *
 *请输入元素的个数5
 123.45
 10  11  12   13  14
 10  11  12   13  14    133065   0  0  0  0
 a=(nil)
 *
 *
 * */
