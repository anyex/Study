#include "stdio.h"

typedef struct Goods{
    char name[18];//[0 -  17]
	double price;//[ 20 - 27]
	char special;//[ 28]
	int num;//[32-35]
	short saled;//[36-37]
      //最后double最大，超过4字节按照4字节计算，所以补齐为40
}gs;

int main()
{
   gs a[10];
   printf("%d\n",sizeof(gs));
   return 0;
}











