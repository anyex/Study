#include "stdio.h"
#include "stdbool.h"
#include "unistd.h"
//内存控制模块
typedef struct mem_control_block
{
  bool        				free;//自由标志
  struct mem_control_block* prev;//前块指针
  size_t                    size;//本块大小
}MCB;

//栈顶指针
MCB* g_top = NULL;

void* mymalloc(size_t size)
{
   MCB* mcb;
   for(mcb = g_top;mcb;mcb = mcb->prev)
	
	   if(mcb->free&&mcb->size>=size)
	    {
		    break;
		}
	   if(!mcb)
	   {
	      mcb = sbrk(sizeof(MCB)+size);
		  if(mcb == (void*)-1)
		  {
		     return NULL;
		  }
          mcb->prev = g_top;
		  mcb->size = size;
		  g_top = mcb;
	   }
	   
	mcb->free=false;
	return mcb+1;
}
//释放内存
void myfree(void* ptr)
{
    if(!ptr)
	{
	   return ;
	}
    MCB* mcb = (MCB*)ptr-1;
	mcb->free = true;
	for(mcb=g_top;mcb->prev; mcb=mcb->prev)
	{
	    if(!mcb->free)
			break;
		if(mcb->free)
		{
		   g_top = mcb->prev;
		   brk(mcb);
		}
		else if(mcb!=g_top)
		{
		   g_top = mcb;
		   brk((void*)mcb+sizeof(MCB)+mcb->size);
		}
	
	}
}


