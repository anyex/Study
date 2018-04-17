#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Sqr {
public:
	Sqr(int a)
	{
		this->a = a;
	}
	int operator()(int a)
	{
		return a*a;
	}
private:
	int a;
};

void func(int a, int(*fp)(int))
{
	cout << a << "平方的结果是:" << endl;
	cout << fp(a) << endl;
}

int sqr(int a)
{
	return a*a;
}

class Print {
public:
	void operator()(int value)
	{
		cout << value << endl;
	}


};

void print(int value)
{
	cout << value << endl;
}

int main()
{
	Sqr s(10);
	int b = 20;

	int aa = s(b);//将一个对象当做普通函数调用，称为仿函数，伪函数
	//s.operator()(a),把一个对象当成一个回调函数传进去，就是仿函数的作用

	cout << aa << endl;
	func(b, sqr);
	
	return 0;
}
