#include <iostream>

using namespace std;
#pragma warning(disable:4996)
class Test {
public:
	/*
	如果不提供构造函数，系统就调用默认的构造函数

	Test(){} 默认的构造函数，如果已经手动提供，默认就被隐藏

	构造函数一旦手动提供，默认就不复存在

	*/
	Test(int x, int y)
	{
		m_x = x;
		m_y = y;

		cout << "调用了有参数的构造函数" << endl;
	}

	//无参数的构造含
	Test() {
		m_x = 0;
		m_y = 0;
		cout << "调用了无参数的构造函数" << endl;
	}

	//拷贝构造函数，通过另外一个Test对象将本对象进行拷贝
	Test(const Test &another)
	{
		m_x = another.m_x;
		m_y = another.m_y;

		cout << "调用了拷贝构造函数" << endl;
	}
	//等号操作符
	void operator = (const Test &t)
	{
		m_x = t.m_x;
		m_y = t.m_y;
		cout << "调用了等号操作符" << endl;
	}

	void printT()
	{
		cout << "x: " << m_x << ",y:" << m_y << endl;
	}

	//析构函数
	~Test()
	{
		cout << "~Test()函数被执行了" << endl;
		//cout << "(" << m_x << ", " << m_y << ")" << "被析构了" << endl;
		cout << s << "被析构了" << endl;
	}
	char s[20];
private:
	int m_x;
	int m_y;
	
};


void test()
{
	Test t1;//调用无参构造函数
	strcpy(t1.s ,"t1");
	Test t2(10, 20);
	t2.printT();
	Test t3(t2);//调用t3的拷贝构造函数
	t3.printT();

	Test t4(100, 200);
	Test t5;
	t5 = t2;//调用=号重载操作符，赋值操作
	strcpy(t2.s, "t2");
	strcpy(t3.s, "t3");
	strcpy(t4.s, "t4");
	strcpy(t5.s, "t5");
			//析构的顺序，根对象的构造顺序相反，谁先构造，谁最后被析构
	Test t6 = t4;

}
int main()
{
	test();

	return 0;

}

/*
运行结果：

调用了无参数的构造函数
调用了有参数的构造函数
x: 10,y:20
调用了拷贝构造函数
x: 10,y:20
调用了有参数的构造函数
调用了无参数的构造函数
调用了等号操作符
~Test()函数被执行了
t5被析构了
~Test()函数被执行了
t4被析构了
~Test()函数被执行了
t3被析构了
~Test()函数被执行了
t2被析构了
~Test()函数被执行了
t1被析构了
*/