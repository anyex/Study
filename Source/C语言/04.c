#include "stdio.h"
#include "math.h"
int main()
{
  float a = 2.34456;
  float b = 2.34457;
  
 int equal = fabs(a-b) <1e-3?1:0;

 	if(equal)
	{
	  printf("a,b在1e-3的精度内想等\n");  
	}else
		printf("a,b不相等");
 return 0;
 
}

/*
 *a,b在1e-3的精度内想等

 *
 *
 * /
