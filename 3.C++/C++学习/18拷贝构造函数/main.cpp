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

//拷贝构造函数的应用场景1
void test1()
{
	Test t1(1, 2);
	Test t2(t1);//通过t1给t2进行赋值

	t2.printT();
}
//拷贝构造函数的应用场景2
void test2()
{
	Test t1(1, 2);
	Test t2;
	t2 = t1;//调用的是=符号的操作符，也实现了将t1的值赋值给t2，因为构造函数只在声明对象需要初始化的时候使用
			//t1,t2都已经调用过构造函数，所以不会调用拷贝构造函数
}



void func(Test t)//相当于 Test t = 实参，会调用局部变量t的拷贝构造函数
{
	cout << "func 函数" << endl;
	t.printT();
	cout << "func 函数" << endl;
}


void test3()
{
	Test t1(10, 20);
	func(t1);//t1会调用拷贝构造函数
}

//场景4
Test func2()
{
	Test temp(10, 20);//调用temp的带参数构造函数
	strcpy_s(temp.s, "temp");
	return temp;//有一个临时匿名对象=temp，把temp的数据给到临时的匿名对象
				//会调用这个临时匿名对象的拷贝构造函数，将temp传进去
}

//场景5
void test5()
{
	Test t1 = func2();//如果有一个变量去接收这个临时的匿名对象，编译器会认为这个匿名对象转正，不会立刻销毁
	//此时不会发生拷贝构造，因此时的t1去接收的临时匿名对象不是重新创建一个t1，而是给这个匿名对象起名为t1

	//这个匿名对象有了自己的名字，编译器就不会立刻给这个匿名对象销毁了，就当普通局部变量处理



}

//场景6
void test6()
{
	cout << "test6 begin..." << endl;
	Test t1; //调用t1的无参数构造函数
	t1 = func2(); //调用的=号操作符 ,,t1 = 匿名对象。 调用了t1的=号操作符。
				  //此时匿名没有被转正，匿名没有自己的名字， 匿名对象这个内存没有自己的别名， 编译器就会立刻销毁。
	cout << "test6 end..." << endl;
}

int main()
{
	test6();
	return 0;
}