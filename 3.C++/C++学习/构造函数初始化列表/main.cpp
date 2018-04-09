#include "iostream"
using namespace std;

class A {
public:
	A(int a)
	{
		cout << "A()...." << endl;
		m_a = a;
	}
	~A()
	{
		cout << "~A()" << endl;
	}

	void printA()
	{
		cout << "a = " << m_a << endl;
	}
private:
	int m_a;
};

class B
{
public:
	//构造函数初始化列表
	B(A&a1,A&a2,int b) :m_a1(a1), m_a2(a2)
	{
		m_b = b;
	};
	void printB()
	{
		cout << "b = " << m_b << endl;
		m_a1.printA();
		m_a2.printA();
	}
	~B()
	{
		cout << "~B()....." << endl;
	}
private:
	int m_b;
	A m_a1;
	A m_a2;

};

int main()
{
	A a1(10),a2(100);
	B b(a1, a2, 1000);
	b.printB();
	return 0;
}