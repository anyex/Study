#include <iostream>
#include <memory>
#include <string>
using namespace std;

class A {
public:
	A(int a)
	{
		cout << "A()" << endl;
		this->a = a;
	}

	void func()
	{
		cout << "a = " << this->a << endl;
	}

private:
	int a;
};

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

	A& operator*()
	{
		return *m_p;
	}

private:
	A* m_p;
};

void test1()
{
	auto_ptr<A>  auto_p(new A);//智能指针,不需要手动delete这个空间
	auto_p->func();


	
}