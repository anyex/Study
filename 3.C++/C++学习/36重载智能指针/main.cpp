#include <iostream>
#include <iostream>
#include <memory>//智能指针的头文件
#include <string>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A()。。。" << endl;
	}
	A(int a)
	{
		this->a = a;
		cout << "A()。。。" << endl;

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

//自定义智能指针
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
 智能指针：不要手动用delete回收，会自动回收
    auto_ptr：智能指针
	auto_ptr<int>  ptr(new int)  定义一个指向new int的智能指针
	指针变量不能自动释放
*/