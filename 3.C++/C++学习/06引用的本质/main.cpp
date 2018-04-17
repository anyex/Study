

#include <iostream>
using namespace std;

struct TypeA
{
	int *a;
};

struct  TypeB
{
	double &a;
};

struct Teacher {
	int id;
	char name[64];
};

void motifyTeacher(Teacher &t)
{
	t.id = 100;//t可以视作一个常指针，*t就是指针指向内存空间;
			   //当试图修改或者获取已经初始化的引用的时候，编译器会有一个隐藏的*的操作，即(*t).id = 100


}

void motifyA(int* const a)//常指针也是一个常量，也必须被初始化，也不能被修改
{
	*a = 100;
}

void motifyB(int &a)
{
	a = 1000;//a实际上是一个常量指针，但是如果给a赋值，编译器会有一个隐形的操作，*


}


//引用可以理解为一个常指针，当使用的时候，可以说视作变量的别名

void test()
{
	int value = 20;
	Teacher t1 = { 1,"张三" };
	motifyA(&value);
	cout << "value = " << value << endl;
	motifyB(value);//int value --> int &a,
	cout << "value = " << value << endl;
	motifyTeacher(t1);//当编译器发现Teacher &t的形参是一个引用，给引用赋初值的时候，会有一个&的隐形操作


}

void motifyAA(int *a)
{
	*a = 100;
}

void motifyBB(int &a)
{
	a = 200;
}

void test2()
{
	int a = 10;

	motifyAA(&a);//建立了关联

	motifyBB(a);//
}

int main()
{
	int a = 10;
	int b = 20;

	const int c_a = 10;//常量初始化之后，不能再修改

	int &re = a;       //引用必须初始化，引用在初始化之后，也不能够被改变
	re = b;            //a=b，而不是让re引用指向b，相当于是将b的值赋值给re即a罢了

	//
	cout << "re = " << re << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	re = 100;//此时修改的是a的值，

	cout << "re = " << re << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "sizeof(TypeA): " << sizeof(TypeA) << endl;
	cout << "sizeof(TypeB):" << sizeof(TypeB) << endl;

	//通过对引用求大小， 发现不管引用是什么类型 都是4个字节，都跟指针的大小一样。

	


	test();

	return 0;

}