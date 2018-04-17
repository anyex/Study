#include <iostream>

using namespace std;

//const 引用一般用在形参上，来保证被引用的变量不能被修改
void printX(const int &re)
{
	cout << "re " << re << endl;

}


int main()
{
	const int a = 10;//a必须被初始化

	const int &b = a;

	//如果是一个const常量，必须用const引用来接收它
	int x = 3.14;

	const int &re1 = x;

	cout << "re1 " << re1 << endl;
	x = 20;
	cout << "re1 " << re1 << ",x: " << endl;

	const int &re2 = 10;//非常量引用，必须是左值，左值就是可以被赋值，有内存空间
	                    //对字面量引用，必须用const
	cout << "re2 = " << re2 << endl;
	cout << "sizeof(re2)" << sizeof(re2) << endl;

	return 0;




}

/*
  常量主要包括由define和const定义的符号常量和字面常量
  字面常量只能引用，不能修改，所以一般保存在符号表（如：x=-100,char c = 'a'主要是各种字符和数字）			

*/