#include <iostream>

using namespace std;

void mySwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(int &a, int &b)
{
	cout << "a = " << a << ",b = " << endl;
}

void mySwap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void print(char &x, char &y)
{
	cout << "x = " << x << ",y = " << y << endl;
}

int main()
{
	int a = 10;
	int b = 20;

	cout << "交换之前" << endl;
	print(a, b);
	mySwap(a, b);
	cout << "交换之后" << endl;
	print(a, b);

	char x = 'x';
	char y = 'y';
	cout << "交换之前" << endl;
	print(x, y);
	mySwap(x, y);
	cout << "交换之后" << endl;
	print(x, y);

	return 0;
}
/*
利用函数重载的参数的类型可以不同，参数个数相同，可以实现多种数据类型调用一个函数
*/