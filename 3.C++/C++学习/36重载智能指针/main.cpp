#include <iostream>
#include <iostream>
#include <memory>//����ָ���ͷ�ļ�
#include <string>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A()������" << endl;
	}
	A(int a)
	{
		this->a = a;
		cout << "A()������" << endl;

	}
	void func()
	{
		cout << "a = " << this->a << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int a;
};

//�Զ�������ָ��
class MyAutoPtr
{
public:
	MyAutoPtr(A* ptr)
	{
		this->m_p = ptr;
	}

	~MyAutoPtr()
	{
		if (this->m_p != NULL)
		{
			delete m_p;
		}
	}
	A* operator->()
	{
		return m_p;
	}

	A &  operator*()
	{
		return *m_p; //A temp = *m_p; 
	}

private:
	A* m_p;
};

void test()
{
	auto_ptr<A>  ap(new A(10));

	
	ap->func();
	(*ap).func();

	//delete ap;

}
int main()
{
	//test();
	MyAutoPtr auto_p(new A);
	
	return 0;
}

/*
 ����ָ�룺��Ҫ�ֶ���delete���գ����Զ�����
    auto_ptr������ָ��
	auto_ptr<int>  ptr(new int)  ����һ��ָ��new int������ָ��
	ָ����������Զ��ͷ�
*/