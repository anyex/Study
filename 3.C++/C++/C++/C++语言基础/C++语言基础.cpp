// C++语言基础.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

/*****
C++数据类型

*****/



void print99()
{
	for (int i = 9; i >= 1; i--)
	{
		for (int j = i; j >=1; j--)
		{
			std::cout << i << " * "<< j <<"="<< i*j <<"  \t" ;
		}
		std::cout << std::endl;
	}
}


int main()
{
	print99();

	return 0;
}

