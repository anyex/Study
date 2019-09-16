#include <stdio.h>

int main()
{
	FILE* file = fopen("t.txt","r+");
	char buf[100] = "_end";
	int ret = 0;
	if(file != NULL)
	{
		printf("打开文件成功");
	}
	
	fseek(file,5,SEEK_SET);
	ret = fwrite(buf,1,4,file);
	fseek(file,0,SEEK_END);
	ret = fwrite(buf,1,4,file);
	/*if(ret>0)
	{
		printf("读取的内容：%s",buf);
	}*/
	
	
	ret = fclose(file);
	
	printf("关闭文件：%d\n",ret);
	
	return 0;
	
}