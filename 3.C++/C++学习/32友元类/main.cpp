#include <iostream>
using namespace std;

//class B;如果只是前置说明，也只能让编译器知道它是一个类，但类中有什么内容也不知道，也不能在下面的的class A中操作内部数据
class B
{
public:
	B(int b);
	void Test();
	friend class A;
private:
	int m_b;
};

class A
{
	friend class B;//声明为友类，就可以访问所有成员
public:
	A(int a)
	{
		this->m_a = a;
	}

	void printA()
	{
		cout << m_a << endl;
	}

	int getA()
	{

		B bb(10) ;
		cout << bb.m_b << endl;
	}
	//让类B可以访问A类中的私有成员

	
private:
	int m_a;
};




B::B(int b)
{
	this->m_b = b;
	A aa(10);
	aa.m_a = 10;
}
void B::Test()
{
	A aa(10);
	cout << aa.m_a << endl;
}
int main()
{
	B b(200);
	b.Test();
	return 0;
}