#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//常见的字符串操作

int main()
{
   //1.赋值(=改地址，strcpy()改值)
   char *s1 = "abc";
   char s2[10] = "abc";//数组是常指针
   s1 = "123";//修改s1的指向
   strcpy(s1,"123");//修改只读区，导致段错误
   strcpy(s2,"123");//数组可以修改
   //s2 = "123";//常指针不能直接改地址,数组名是一个地址，不是指针，是个常量，不是变量
   strcpy(s2,"123");//值可以改
   char* s3 = malloc(10);
   strcpy(s3,"abc");
   s3 = "123";//改地址，指向了只读区
   printf("s3=%s\n",s3);//
   free(s3);//free()失败，内存泄露
//求字符串的长度strlen(),sizeof求buf的内存大小
   char buf[50] = "abc";
   printf("size = %d,length = %d\n",sizeof(buf),strlen(buf));
   
   //字符串的比较,==比较地址，strcmp比较内容
   char* s4 = "abc";
   char* s5 = "abc";
   printf("%d\n",s4==s5);
   printf("%d\n",strcmp(s4,s5));
   

//指针操作字符串
   char* s6 = "zhangfei,123";
   int len = strlen(s6);
   char name[len];
   char passwd[len];
   memset(name,0,len);//清空name
   memset(passwd,0,len);
   
   int i,flag = 0,pos = 0;
   for(i = 0;i < len; i++)
    {

         if(*(s6+1)==',')
          {
            flag = 1;
            pos = i;
            continue;
          }
        if(!flag)
           name[i] = *(s6+i);
        else
           passwd[i-pos-1] = *(s6+1);
 
    }
    

   printf("name = %s,passwd = %s\n",name,passwd);

//字符串的拼接
   char fpath[20] = "/home/";
   char fname[20] = "a.txt";
   char pname[50] = {};






   
   


   
   
   return 0;
}
