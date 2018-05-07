#include <stdio.h>
//#define VERSION 
#if(VERSION<2)
#error "版本低"
#else
#warning "版本高"
#endif

int main(void)
{
  printf("版本%d, 启用!\n",VERSION);
  return 0;

}
