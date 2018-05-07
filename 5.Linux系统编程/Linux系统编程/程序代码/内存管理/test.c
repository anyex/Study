#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main()
{
  srand(time(NULL));//保证每次获取的随机数相同
unsigned int cn =0;
for(unsigned int i = 0;i<10;++i)
{
   int x = rand()%100;
   int y = rand()%100;
printf("%d,%d\n",x,y);
   if(x*x+y*y <= 10000);
   ++cn;

}




printf("cn = %d,cn/10000 = %g\n",cn,cn/10000.);

return 0;
  	
}
