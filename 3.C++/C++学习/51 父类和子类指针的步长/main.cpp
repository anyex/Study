#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}

	virtual void print()
	{
		cout << "Parent::print() " << a << endl;
	}
protected:
	int a;
};

class Child :public Parent {
public:
	Child(int a) :Parent(a)
	{

	}

	virtual void print()
	{
		cout << "Child :: Print() " << a << endl;
	}
private:
	int b;
};

int main(void)
{
	Child array[] = { Child(0), Child(1), Child(2) };
	//						array[0]   array[1] array[2]

	Child *cp = &array[0];
	Parent *pp = &array[0];


	cp->print(); //Child::
	pp->print(); //Child::发生多态

	cout << "------" << endl;

	cp++; //Child::12
	pp++;//8

	//pp->print();
	/*
	  指针运算时是按指针类型的长度进行计算的，父类和子类类型长度不同，在进行'++'操作之后，
	  每个数组元素的长度是子类的长度，父类指针所指的位置并不是下个数组元素的开始位置
	*/
	pp = cp;

	cp->print();
	pp->print();

	cout << " -----  " << endl;


	int i = 0;
	for (i = 0, cp = &array[0], pp = cp; i < 3; i++, cp++, pp = cp) {
		pp->print();
	}

	return 0;
}