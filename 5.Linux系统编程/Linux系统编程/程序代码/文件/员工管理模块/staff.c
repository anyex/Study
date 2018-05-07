#include "staff.h"
int add_staff(char* filename)
{
	staff buf;	
	printf("请输入新员工的信息\n");
	printf("姓名:");
	scanf("%s",buf.name);

	printf("工资:");
	scanf("%d",&buf.salay);
	printf("编号:");
	scanf("%d",&buf.id);
	printf("\n");
    int fd = open(filename,O_RDWR|O_APPEND);
	int ret = -1;
	if(fd == -1)
	{
	   return ret;
	}

  ret =	write(fd,&buf,sizeof(buf));
  close(fd);
  return ret;
}
int read_staffFile(char* filename)
{
    int fd = open(filename,O_RDONLY);
	int ret = -1;
	if(fd == -1)
	{
	   return ret;
	}
      staff buf;
    do
	{
	   ret = read(fd,&buf,sizeof(staff));
	   if(ret >0)
	   {
	     printf("姓名:%s\t\t工资:%d\t\t编号:%d\n",buf.name,buf.salay,buf.id);
	   }
	}while(ret>0);
	close(fd);
   return ret;
}

int main()
{
		char filename[] = "staff.txt";
   
		int a = add_staff(filename);
   add_staff("staff.txt");

   //add_staff("staff.txt");
   //add_staff("staff.txt");
   //add_staff("staff.txt");
   //add_staff("staff.txt");
   int b = read_staffFile(filename);
   return 0;
}
