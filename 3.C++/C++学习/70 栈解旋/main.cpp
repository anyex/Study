#include <iostream>

using namespace std;

class Test {
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Test(int , int)..." << a<<","<<endl;
	}
	~Test()
	{
		cout << "a = " << a << ", b = " << b << ",~Test()..." << endl;
	}



private:
	int a;
	int b;
};

void func2()
{

}

void func() throw()//代表此函数不会抛出异常
{
	throw 1;
}

void divide(int x, int y) throw(int, char, char*)
{
	Test t1(1, 2);
	Test t2(10, 20);

	if (y == 0)
	{
		throw x;//所有在throw之前在栈上开辟的空间，如t1,,t2都会被析构掉
	}


	
}
int main(void)
{
	try {
		divide(10, 0);
	}
	catch (int e)
	{
		cout << "捕获到了异常 e= " << e << endl;
	}


	try {
		func();
	}
	catch (...) {

	}
	return 0;
}