#include <iostream>
using namespace std;

class A {
public:
	void funcA()
	{
		cout << "func A。。。" << endl;
	}
};

//A类对于B类，是B的一个成员变量，包含关系A属于B
class B
{
public:
	void funcB()
	{
		a.funcA();
	}
	A a;
};

//类C中的某一个成员函数依赖于A类形参，将A类当一个形参传递进来
class C
{
public:
	void funcC(A*a)
	{
		a->funcA();
	}
};

//类D继承于A，说明D是A
class D :public A
{
public:
	void funcD()
	{
		funcA();//直接使用A类的方法
	}
};

int main()
{
	D d;
	d.funcA();

	return 0;
}