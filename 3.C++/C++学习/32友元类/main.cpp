#include <iostream>
using namespace std;

//class B;���ֻ��ǰ��˵����Ҳֻ���ñ�����֪������һ���࣬��������ʲô����Ҳ��֪����Ҳ����������ĵ�class A�в����ڲ�����
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
	friend class B;//����Ϊ���࣬�Ϳ��Է������г�Ա
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
	//����B���Է���A���е�˽�г�Ա

	
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