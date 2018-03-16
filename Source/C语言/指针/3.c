#include "stdio.h"

int (*pfun)(char*);
int fun(char*);

int fun(char* s)
{
   int num = 0;
   for(int i = 0;*s!='\0';)
	{
	  num+=*s;s++;
	}
   return num;
}

int main()
{

char s[] = "afasdfadsgdasf";		
  pfun = fun;
  int a = (*pfun)(s);
  printf("%d",a);

  return 0;
}
