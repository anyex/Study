#include <stdio.h>
#pragma GCC dependency "dep.c"
#pragma GCC poison abc

int main()
{
  int abc = 0;
  printf("%d\n",abc);
  return 0;

}

/*

 当创建两次dep.c文件后，编译后提示：
 warning: current file is older than dep.c
 #pragma GCC dependency "dep.c"

这个也就是比较两个文件的最后保存时间
如果后面文件的最后修改时间比当前文件的晚，就会产生一个警告。当前文件依赖于 dependency后面文件，dependency后面文件的最后修改时间比当前文件的晚，就会产生一个警告。


另外 #pragma GCC posion 单词
把后面的单词声明为毒药，不能被使用，否则产生错误,如这个程序将报错

.c:7:7: error: attempt to use poisoned "abc"
   int abc = 0;

#pragma pack n 指定对齐补齐字节数



*/
