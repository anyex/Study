#include <stdio.h>

int main()
{
	FILE* file = fopen("t.txt","w+");
	
	if(file != NULL)
	{
		printf("打开文件成功");
	}
	
	int ret = fclose(file);
	
	printf("关闭文件：%d\n",ret);
	
	return 0;
	
}