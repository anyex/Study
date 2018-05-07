#include "stdio.h"
#include "unistd.h"

int main()
{
  //void* p1 = sbrk(0);//会导致后面的段错误，因为未映射内存页
  void* p1 = sbrk(4);

 int* pn = (int*)p1;
 //pn[0] = 0;
 //pn[1] = 1;
 //pn[2] = 2;
 //pn[3] = 3;

 

 for(int i=0;i<2048;i++)
 {
    pn[i]=i;
	
	if(i<6)
	{
	  printf("p[i] = %d,&p[i]=%p\t",pn[i],&pn[i]);
	}else
	{
	  printf("%d\t",pn[i]);
	}

	if(i%10==0&&(i!=0))
	{
	   printf("\n");
	}

}

  return 0;
}
