#include<stdio.h>
#include<string.h>
int main()
{
  char buf[100];
  //sprintf(buf,"hello,I'm %s,today is %d-%d-%d","利好"，2018,3,15);
  sprintf(buf,"hello ,I'm %s,today is %d-%d-%d","C",2018,3,15);//组合字符串
  puts(buf);
  int age;
  char name[20];
  double salary;
  const char* str="2018 C 2.567";
 // sscanf(str,"%d%s%lf",&age,&name,&salary);
  sscanf(str,"%d%s%lf",&age,&name,&salary);//将字符串中的值分别赋值给age,name,salary
  printf("我是%s,今年%d,月薪%g\n", name, age, salary);
  return 0;


}
/*
 *hello ,I'm C,today is 2018-3-15
 我是C,今年2018,月薪2.567
 
 *
 * */
