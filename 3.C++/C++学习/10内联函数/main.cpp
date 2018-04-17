#include <iostream>

using namespace std;


#define MY_MAX(a,b) ((a)<(b)?(a):(b))

//inline 是一个关键字，代表此函数是内联函数，放在函数返回值的前面
inline int my_func(int a, int b)
{
	return (a < b ? a : b);
}

inline void printAB(int a, int b);

int main()
{
	int a = 10;
	int b = 20;

	MY_MAX(a++, b);
	printAB(a, b);
	(a++) < (b) ? (a++) : (b);
	my_func(a++, b);

	return 0;
}

//如果函数声明了inline关键字，但函数定义没有写inline,编译器仍然不会当inline函数处理
void printAB(int a, int b)
{
	cout << "a = " << a << ", b = " << b << endl;
}

/*
内联函数在调用的时候，不像普通函数有压栈和出栈的开销
内联函数仅仅是把普通函数的压栈和出栈开销省去了，所有的编译器词法分析和校验都有，它是由编译器处理的
 宏函数由预处理器处理，没有函数一样的校验


*/