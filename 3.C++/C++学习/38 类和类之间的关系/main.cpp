#include <iostream>
using namespace std;

class A {
public:
	void funcA()
	{
		cout << "func A������" << endl;
	}
};

//A�����B�࣬��B��һ����Ա������������ϵA����B
class B
{
public:
	void funcB()
	{
		a.funcA();
	}
	A a;
};

//��C�е�ĳһ����Ա����������A���βΣ���A�൱һ���βδ��ݽ���
class C
{
public:
	void funcC(A*a)
	{
		a->funcA();
	}
};

//��D�̳���A��˵��D��A
class D :public A
{
public:
	void funcD()
	{
		funcA();//ֱ��ʹ��A��ķ���
	}
};

int main()
{
	D d;
	d.funcA();

	return 0;
}