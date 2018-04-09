#include "iostream"
using namespace std;

class Test
{
public:
	//Test(){};默认的构造函数，当手动提供一个构造函数，默认的构造函数就被隐藏

	Test(int x, int y)//当提供这个构造函数，默认的构造函数就不复存在
	{
		m_x = x;
		m_y = y;
	}

	//无参数的构造函数
	Test() {
		m_x = 0;
		m_y = 0;
		cout << "调用了无参数的构造函数" << endl;
	}

	//拷贝构造函数，通过另外一个Test对象another来初始化自己
	Test(const Test& another)
	{
		cout << "调用了拷贝操作符号" << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}

	//等号操作符
	void operator = (const Test &t)
	{
		cout << "调用了=号操作符" << endl;
		m_x = t.m_x;
		m_y = t.m_y;
	}

	void printT()
	{
		cout << "x: " << m_x << " y: " << m_y << endl;
	}

	//提供一个析构函数
	~Test()
	{
		cout << " ~Test() 析构函数被执行了" << endl;
		cout << "(" << m_x << "," << m_y << ")" << "被析构了" << endl;
	}




private:
	int m_x;
	int m_y;
};

//拷贝构造函数1
void test1()
{
	Test t1(1, 2);
	Test t2(t1);

	//通过t1给t2进行赋值
	t2.printT();
}
//拷贝构造函数2

void test2()
{
	Test t1(1, 2);
	Test t2;
	t2 = t1;//调用的不是拷贝构造函数，调用的是"="号操作符，也能够完成将
			//t1的值给t2但不是调用t2的拷贝构造函数

}

void func(Test t)
{
	cout << "func begin..." << endl;
	t.printT();
	cout << "func end..." << endl;
}

//拷贝构造函数3
void test3()
{
	cout << "test3 begin..." << endl;
	Test t1(10, 20);//创建了一个t1的对象，通过t1的有参数的构造函数初始化
	func(t1);//一个对象以值的方式传入函数会调用拷贝构造函数

	cout << "test3 end..." << endl;
}

int func(void)
{
	int a = 10;
	return a;
}

//拷贝构造函数4
Test func2()
{
	cout << "func2 begin..." << endl;
	Test temp(10, 20);
	cout << "func2 end..." << endl;
	return temp;//有一个临时的匿名对象temp，把temp的数据给到临时的匿名对象
				//返回一个对象也会调用拷贝构造函数
}

void test4()
{
	cout << "test4 begin...." << endl;
	func2();

	cout << "test4 end" << endl;
}

void test5()
{
	cout << "test5 begin...";
	Test t1 = func2();
	cout << "test5 end...";

}

void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;
	t1 = func2();

	cout << "test6 end..." << endl;
}

int main()
{
	test3();
	return 0;
}