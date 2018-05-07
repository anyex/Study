#include "stdio.h"
#include "stdlib.h"

int main()
{
  int* p1 = malloc(sizeof(int));
  int* p2 = malloc(sizeof(int));

  printf("p1 = %p,p2 = %p\n",p1,p2);
  free(p2);

  return 0;
}


