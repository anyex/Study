#include <iostream>

using namespace std;

class B
{
public:
	/*
	默认的构造函数
	B(){}

	默认的拷贝构造函数
	B(const B&b)
	{
	  m_b = b.m_b;
	  p = b.p;
	}

	默认的析构函数
	~B(){}


	//如果显示的写了一个普通构造函数， 会隐藏默认的无惨构造函数
	//如果显示的写了一个拷贝构造函数 ，会隐藏默认的无参构造函数和默认的拷贝构造函数
	//如果显示的写了一个析构函数， 会隐藏默认的析构函数

	*/
	B(int b)
	{
		m_b = b;
	}
	
	void prinT()
	{
		cout << m_b << endl;
	}
private:
	int m_b;

};

class A
{
public:

};

int main()
{
	B b1(2);
	//下面都调用了默认的拷贝构造函数
	B b2(b1);
	B b3 = b2;

	b1.prinT();
	b2.prinT();
	b3.prinT();
	
	return 0;
	
}