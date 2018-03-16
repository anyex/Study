#include "stdio.h"
int main()
{
   FILE* fi = fopen("in.txt","r");
   if(fi == NULL)
    {
	  printf("打开文件失败\n");
	}
   char name[20];
   int age;
   double weight;
   fscanf(fi,"%s",name);
   fscanf(fi,"%d%lf",&age,&weight);
   fclose(fi);
    
   printf("姓名：%s,年龄：%d,体重：%g\n",name,age,weight);
   FILE* fo = fopen("out.txt","w");
   if(fo == NULL)
   {
      printf("打开文件out失败\n");
	  return 2;
   
   }
   
   fprintf(fo,"向文件写内容\n");
   fprintf(fo,"姓名:%s,年龄：%d,体重：%g\n",name,age,weight);
   fclose(fo);
   return 0;


}

