#define _CRT_SCEURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	double PI = 3.14159265357489;
	int num2 = (int)PI;//C语言的转换方式
	int num3 = static_cast<int>(PI);//增加可读性，代表普通类型的强制转换

	//static_cast 实际上编译器在编译的时候就已经将PI解释为int类型

	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;

	return 0;
}
/*
static_cast<> 用于内置的数据类型，具有继承关系的指针或引用之间的互相转换
*/