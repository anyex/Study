#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
class Test
{
public:
	//无参构造函数
	Test()
	{
		m_x = 0;
		m_y = 0;

		p = (char*)malloc(100);

		strcpy(p, "123");
	}

	//带参数的构造函数
	Test(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	//一个参数的构造函数
	Test(int x)
	{
		m_x = x;
		m_y = 0;
	}

	//析构函数,没有任何参数
	~Test()
	{
		cout << "Test 的析构函数~Test()被调用了" << endl;
		if (p != NULL)
		{
			cout << "p的堆空间被释放了" << endl;
			free(p);
			p = NULL;
		}
	}

	void printT()
	{
		cout << "x: " << m_x << ",y: " << m_y << endl;
	}

	void init(int x, int y)
	{
		m_x = x;
		m_y = y;
	}



private:
	int m_x;
	int m_y;
	char *p;

};


void test1()
{
	Test t1;//调用无参数的构造函数
			//t1是一个局部变量，生命周期与test1()一样，在test1()函数执行完毕需要先销毁t1变量
	t1.printT();
	return;//当对象被销毁的时候会调用析构函数
	        
}
int main()
{
	Test t1;//创建一个对象，这个对象会直接调用无参构造函数
	t1.init(10, 20);//显式调用一个初始化的函数
	test1();

	Test t2(10, 20);//会调用带两个参数的构造函数

	return 0;
}


/*
 构造函数是为了给对象提供初始化而出现的
 函数名字跟类型一样，没有返回值，且可以重载
*/

/*

运行结果：

x: 0,y: 0
Test 的析构函数~Test()被调用了
p的堆空间被释放了


*/