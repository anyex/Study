#include <iostream>

using namespace std;

void func(int a, int b)
{
	cout << a << b << endl;
}

void func(int a, int b, int c)
{
	cout << a << b << c << endl;
}

void func(int a,int b,int c,int d)
{
	cout << a << b << c << d << endl;

}

typedef void(myfunctype)(int, int);//定义一个函数类型返回值void,参数列表：int,int
typedef void(*myfunctype_pointer)(int, int);//定义了一个函数指针类型

int main()
{
	myfunctype_pointer fp1 = NULL;
	fp1 = func;

	fp1(10, 20);

	myfunctype_pointer fp2 = NULL;
	fp2 = func;

	fp2(10, 20);

	void(*fp3)(int, int) = NULL;

	fp3 = func;
	fp3(10, 20);
	//fp3(10, 20, 30, 40);不能通过函数指针发生重载，fp3恒定指向一个函数入口（void func(int,int)）

	return 0;
}