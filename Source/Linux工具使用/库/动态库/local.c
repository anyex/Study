#include <stdio.h>
#include "dlfcn.h"
/*
 这个函数文件示范了如何动态加载共享库

编译的时候要使用 gcc local.c -o main -ldl
因为以下使用的一系列函数需要使用libdl.so动态库中的内容
同时可以使用ldd main查看动态库的加载情况
 ldd main
	linux-gate.so.1 =>  (0xb7f1c000)
	libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xb7efb000)
	libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xb7d45000)
	/lib/ld-linux.so.2 (0xb7f1e000)


*/
typedef int (*PFUNC_CALC)(int,int);
typedef void (*PFUNC_SHOW)(int,char,int,int);
int main()
{
   void* handle = dlopen("libmath.so",RTLD_NOW);//加载共享库
   if(!handle)
    {
      
        printf("dlopen失败：%s\n",dlerror());
        return -1;
     }

  PFUNC_CALC add = (PFUNC_CALC)dlsym(handle,"add");//获取函数地址

  if(!add)
	
  {
    printf("dlsym失败:%s\n",dlerror());
    
    return -1;
  }
   
  PFUNC_CALC sub = (PFUNC_CALC)dlsym(handle,"sub");//获取动态库中的sub函数

  if(!sub)
	
  {
    printf("dlsym失败:%s\n",dlerror());
    
    return -1;
  }

  PFUNC_SHOW show = (PFUNC_SHOW)dlsym(handle,"show");


  if(!show)
	
  {
    printf("dlsym失败:%s\n",dlerror());
    
    return -1;
  }

  show(30,'+',20,add(30,20));
  show(30,'-',20,sub(30,20));

  dlclose(handle);//关闭共享库
   


}
