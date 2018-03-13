#include "stdio.h"

int main()
{
   printf("%d\n",__LINE__);
#line 100
   
   printf("%d\n",__LINE__);

return 0;

}

/**

预编译后，被替换为如下的形式，__LINE__表示在源代码中的行数，因为#line指定当前行为100所以下面的行为101
int main()
{
   printf("%d\n",5);
# 100 "line.c"

   printf("%d\n",101);

return 0;

}

*/
