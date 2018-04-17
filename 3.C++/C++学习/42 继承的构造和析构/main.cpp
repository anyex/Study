#include <iostream>
using namespace std;


class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent(int a)....." << endl;
	}
	~Parent()
	{
		cout << "~Parent()。。。。" << endl;
	}
	void printA()
	{
		cout << "a = " <<a <<endl;
	}

private:
	int a;
};

class Son :public Parent
{
public:
	//子类继承于父类，父类中的成员变量 应用父类的构造函数来初始化
	Son(int a,int b):Parent(a)
	{
		this->b = b;
	}
	~Son()
	{
		cout << "~Son()" << endl;
	}

	void printB()
	{
		cout << "b = " << b << endl;
	}

	void printAB()
	{
		//Parent::printA();
		printA();
		this->printB();
	}

private:
	int b;
};

void test1()
{
	Parent p(30);
	Son s(20, 20);
	s.printAB();
}

int main()
{
	test1();
	return 0;
}
/*

子类在进行初始化成员变量的时候， 如果此成员变量是继承过来的， 那么需要调用父类的构造器来初始化。


1. 如果子类没有定义构造方法，则调用父类的无参数的构造方法。

2. 如果子类定义了构造方法，不论是无参数还是带参数，在创建子类的对象的时候,首先执行父类无参数的构造方法，然后执行自己的构造方法。

3. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数，则会调用父类的默认无参构造函数。

4. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。

5. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。

6. 如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式
*/