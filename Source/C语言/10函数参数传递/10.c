#include "stdio.h"

//变量作为函数参数
void swap1(int a,int b)
{   
  
	//值传递
	
   int temp;

   temp = a;
   a = b;
   b = temp;
   
}

//地址传递
void swap(int* a,int * b)
{
  int temp;
 
   printf("传值接收的值: &a = %p,&b = %p\n",&a,&b);
   printf("传值接收的值: a = %p,b = %p\n",a,b);
   


   temp = *a;
   *a = *b;
   *b = temp;
}
//数组传递
void count(int a[],int n)
{
   printf("数组传递\n");
   printf("传值接收的值: &a = %p,a = %p \n",&a,a);

//  int n = sizeof(a)/sizeof(int) ;
  for(int i  = 0;i <n;i++)
  {
     printf("\t%d",a[i]);
  }
		  
}


int main()
{
   int a = 10,b =5;
   printf("交换前: &a = %p,&b = %p\n",&a,&b);
   swap(&a,&b);
   		   
   printf("交换后: &a = %p,&b = %p\n",&a,&b);
//数组传递
   int c[6] = {1,2,3,4,5,6};
   printf("数组传递前&a = %p,a=%p\n",&c,c);
   
   count(c,6);
   return 0;
}

/*

   交换前: &a = 0xbffc3f5c,&b = 0xbffc3f60
   传值接收的值: &a = 0xbffc3f40,&b = 0xbffc3f44
   传值接收的值: a = 0xbffc3f5c,b = 0xbffc3f60
   交换后: &a = 0xbffc3f5c,&b = 0xbffc3f60
   数组传递前&a = 0xbffc3f64,a=0xbffc3f64
   数组传递
   传值接收的值: &a = 0xbffc3f40,a = 0xbffc3f64 
   	1     2      3     4      5     6
  
  
   说明不论地址传递，值传递都是复制的值传递
   值传递相当swap1(a,b)  相当于int a = a,int b = b
   地址传递swap(&a,&b)   相当于int* a = &a,int* b = &b
   
 *
 *
 * */
