#include <iostream>
using namespace std;

int getA1()
{
	int a = 10;
	return a;
}

int &getA2()
{
	int a = 10;
	return a;
}

int &getBB()
{
	static int b = 100;

	return b;
}



int main()
{
	int value_a = 0;
	value_a = getA1();

	cout << "value_a = " << value_a << endl;

	value_a = getA2();//int value_a = *temp,这是一个值拷贝，可以使用

	cout << "value_a" << value_a << endl;
	cout << "value_a" << value_a << endl;

	int &r_a = getA2();//当函数返回值是一个局部变量的引用时，不能再用引用来接受

	cout << "r_a " << r_a << endl;
	cout << "r_a " << r_a << endl;//此时将会成为乱值

	int &r_b = getBB();//r_b就是getBB中的static int b
					   //当函数返回值，不是子函数内部局部变量，就可以使用引用进行接收

	cout << "r_b " << r_b << endl;
	cout << "r_b " << r_b << endl;

	r_b = 2000;//r_b就是getBB中的static int b，所以修改的也是getBB中的值

	int value_b = getBB();

	cout << "value_b " << value_b << endl;

	getBB() = 3000;//当引用作为函数的返回值的时候，只要这个引用合法，就可以当左值
	value_b = getBB();
	cout << "value_b " << value_b << endl;
	//三目运算符
	int a = 10;
	int b = 20;

	(a < b ? a : b) = 30;//这里也相当于让a,b都称为了引用，能够被赋值

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;

}