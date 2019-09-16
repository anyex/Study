#include <stdio.h>

int main()
{
	FILE* file = fopen("t.txt","r+");
	char buf[100] = "fdafdsafda";
	int ret = 0;
	if(file != NULL)
	{
		printf("打开文件成功");
	}
	
	ret = fwrite(buf,1,10,file);
	
	/*if(ret>0)
	{
		printf("读取的内容：%s",buf);
	}*/
	
	
	ret = fclose(file);
	
	printf("关闭文件：%d\n",ret);
	
	return 0;
	
}