#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		this->a = 0;
		cout << "构造函数调用" << endl;
	}

	A(int a)
	{
		this->a = a;
		cout << "有参数的A(int a)函数调用" << endl;
	}
	~A()
	{
		cout << "析构函数调用" << endl;
	}

	//重载一new操作符
	void *operator new[](size_t size)
	{
		cout << "重载了一个new[] 操作符" << endl;

		return malloc(size);
	}
		void operator delete(void *p)
	{
		cout << "重载了一个delete操作符" << endl;
		if (p != NULL)
		{
			free(p);
		}
	}

	void operator delete[](void *p)
	{
		cout << "重载了一个delete[] 操作符" << endl;
		if (p != NULL)
		{
			free(p);
		}
	}

private:
	int a;
};

int main(void)
{
	int *p = new int; //在堆上开辟一个int
	*p = 20;
	cout << *p << endl;
	delete p;

	A *ap = new A; //调用我们重载的new

	delete ap;


	int *array_p = new int[10];// 开辟一个数组  new[]
	delete[] array_p;

	A *array_ap = new A[10]; //开辟了10 个A对象。数组首地址 array_ap
	delete[] array_ap;

	return 0;
}