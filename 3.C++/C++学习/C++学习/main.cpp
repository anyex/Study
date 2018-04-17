//c语言
#if 0
#include "stdio.h"

int main()
{
	int a = 0;
	printf("Hello World!\n");

	printf("请输入一个数字");
	scanf("%d", &a);
}
#endif

//c++
#include <iostream>

using namespace std;//命名空间

/*
  iostream中有个一个命名空间std，即标准命名空间
  其中包括cout,cin,endl等关键字
  
*/

int main()
{
	int a = 0;
	cout << "Hello world" << endl;//cout即一个标准输出，endl即换行

	cout << "请输入一个数字" << endl;
	cin >> a;

	cout << "a = " << a << endl;
	return 0;
}