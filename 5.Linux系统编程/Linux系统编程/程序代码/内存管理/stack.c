#include "stdio.h"
#include "unistd.h"

void* g_begin = NULL;
//初始化
void init()
{
  g_begin = sbrk(0);
}

void deinit()
{
   brk(g_begin);
}
//入栈
void push(int data)
{ 
   *(int*)sbrk(sizeof(int))= data;
}
//出栈
void pop()
{
   sbrk(-sizeof(int));
}
//栈顶
int top()
{
   return *((int*)sbrk(0) - 1);
}
//判断是否为空
int empty()
{
  return sbrk(0) == g_begin;

}
//任意进制打印
void printb(unsigned int data,int base)
{
  init();

  do{
	  	  push( data % base); 
  } while(data/=base);

  int i =0;
  for(i=0;!empty()&&i<5;pop(),i++)
   
      if(top()<10)
		{
		   printf("%d",top());
		}
	  else
	  {
	     printf("%c",top()-10+'A');
	  }
  printf("\n");
  deinit();
}

int main()
{
   //printb(28,9);
//   init();
int data=28,base=9;

   g_begin = sbrk(4);
   int *item = (int *)g_begin;

  do{
	  	*item = data % base;
	   item = (int*)sbrk(4);	
  } while(data/=base);
  int i=0;
  //while(sbrk(0)!=g_begin)
  for(i=0;i<5;i++)
  {  
	 sbrk(-4);
     printf("%d\t ",*((int*)sbrk(0)-1));
	 printf("%p,%p",g_begin,sbrk(0));
  }

   return  0;

}


