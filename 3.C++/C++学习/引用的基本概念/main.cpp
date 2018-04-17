#include <iostream>

using namespace std;

/*
 1 引用没有定义，是一种关系型声明，声明它和原有某一变量的关系，类型和原有关系保持一致，且不分配内存
 2 声明的时候必须初始化，一经声明，便不可变更
 3 可对引用再次引用，多次引用的结果，是某一变量具有多少个别名
 4 &符号前有数据类型时是引用，其他都是取地址

*/

int printA(int &a)//引用作为函数参数的时候，不需要初始化，因为形参一定会被赋值
{
	cout << "a = " << a << endl;
	return 0;
}

int main(void)
{
	int a = 10;   //在内存上开辟4个字节，a就代表这4个字节内存
	int *p = &a;  //让一个指针指向这四个字节的空间
	*p = 20;
	cout << "a = " << a << endl;

	//除了指针，c++提供了一种对变量间接操作的另一种方式，即引用

	int &b = a;
	b = 40;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "&a = " << &a << endl;
	cout << "&b =" << &b << endl;
	/*
			a = 20
			a = 40
            b = 40
            &a = 00D8F834
            &b = 00D8F834
		说明a,b其实是一个变量，只是名字不同
	
	*/

	int &bb = b; //对b引用再次 引用， 实际上是b的别名

	cout << "bb = " << bb << endl;
	cout << "&bb =" << &bb << endl;

	return 0;

	return 0;

}