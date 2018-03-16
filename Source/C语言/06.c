#include "string.h"
#include "stdio.h"
   
int main()
{
   char a[100] = "Hello world!";               //定义一个保存字符串的字符数组a
   printf("%d\n",sizeof("hello world!"));      //输出字符串占用内存大小
   printf("%c\n","csd1007"[2]);                //输出字符串“csd1007”的第三个字符
   printf("%s\n","csd1007"+3);                 //输出字符串“csd1007”从第4位到末尾
   strcpy(a,"googd");                          //复制“googd”到字符数组a,即重新被赋值为“googd”
   puts(a);                                    //输出被赋值后的a
   strcpy(a,"der fan ");                       
   puts(a);                   
   sizeof(a);                                  //求a的占用内存大小
   strlen(a);                                  //求a的长度，即有多少个字符，不包括字符串末尾的'\0'
   strchr(a,'f');                              //在字符串中找一个字符,返回那个字符的地址没有找到带回来的是一个空地址(从左向右找)
   printf("%s\n",strchr(a,'f'));              
   printf("%s\n",strchr(a,'k'));             //不能找到，返回空地址，出现段错误.就是非法内存访问
   
   printf("%s\n",strchr(a,'f'));              
   
   //puts(strstr(a,"no"));                       //查找字符串中的字符串，不能找到，返回空地址，出现段错误（非法内存访问）
   char b[] = "hello";
   if(b == "hello")                            //结果不相等.两个字符数组(使用==)比较的是他们的地址
   {
        printf("xiang deng");
   
   }
   else
   {
       printf("bu deng");
   }
     strcmp(b,"hello");
   if(strcmp(b,"hello")==0)                   //比较两个字符串，相等0,不相等非0.第一个比第二大整数,反之负数.比ascll码.
   {
      printf("xiang deng\n");
   }
   else
   {
      printf("bu deng\n");
   }
  return 0;
}

/*
 *13
 d
 1007
 googd
 der fan 
 fan 
 段错误 (核心已转储)

 */
