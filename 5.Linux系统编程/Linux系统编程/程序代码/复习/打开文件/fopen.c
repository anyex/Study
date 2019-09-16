#include <stdio.h>

int main()
{
	FILE* file = fopen("t.txt","w+");
	
	if(file != NULL)
	{
		printf("打开文件成功");
	}
	
}