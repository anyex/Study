#include <iostream>

using namespace std;

class B
{
public:
	/*
	Ĭ�ϵĹ��캯��
	B(){}

	Ĭ�ϵĿ������캯��
	B(const B&b)
	{
	  m_b = b.m_b;
	  p = b.p;
	}

	Ĭ�ϵ���������
	~B(){}


	//�����ʾ��д��һ����ͨ���캯���� ������Ĭ�ϵ��޲ҹ��캯��
	//�����ʾ��д��һ���������캯�� ��������Ĭ�ϵ��޲ι��캯����Ĭ�ϵĿ������캯��
	//�����ʾ��д��һ������������ ������Ĭ�ϵ���������

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
	//���涼������Ĭ�ϵĿ������캯��
	B b2(b1);
	B b3 = b2;

	b1.prinT();
	b2.prinT();
	b3.prinT();
	
	return 0;
	
}