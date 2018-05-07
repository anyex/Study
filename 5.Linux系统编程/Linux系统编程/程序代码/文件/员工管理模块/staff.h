#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"

typedef struct tag_staff{
   int id;
   char name[10];
   unsigned int salay;
}staff;

int add_staff(char* filename);//添加员工信息
int read_staffFile(char* filename);//打印员工信息


