#include <iostream>
using namespace std;

class Test {
public:
	Test()
	{
		m_a = 0;
		m_b = 0;
		cout << "0,0构造" << endl;
	}

	Test(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "a = " << m_a << ",b = " << m_b <<"构造"<< endl;
	}

	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}

	void printT()
	{
		cout << "a = " << m_a << ", b = " << m_b << endl;
	}

	~Test()
	{
		cout << "a = " << m_a << ", b = " << m_b << "析构 " << endl;
	}
private:
	int m_a;
	int m_b;
};

class A
{
public:
	A()
	{
		a = 0;
	}
	~A()
	{
		cout << "析构函数被调用" << endl;
	}
private:
	int a;
};
//C语言中
void test1()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	cout << *p << endl;
	if (p != NULL) {
		free(p);
		//delete p; //delete 可以释放malloc的开辟的内存
	}

	int *array_p = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++) {
		array_p[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << array_p[i] << endl;
	}

	if (array_p != NULL) {
		free(array_p);
	}


	cout << " --------  " << endl;

	Test *tp = (Test*)malloc(sizeof(Test)); //不会调用对象的构造函数
											//p(10, 20);
	tp->setA(10);
	tp->setB(20); //malloc出来的对象指针，只能够通过成员函数来进行初始化
	tp->printT();

	if (tp != NULL) {
		free(tp); //不会调用对象的析构
	}
}

//C++中的new delete
void test2()
{
	//new 能够完成所有malloc的需求
	int *p = new int; //在堆上动态开辟4个字节
	*p = 10;
	cout << *p << endl;

	if (p != NULL) {
		//delete p; //delete 一个变量
		free(p); //用new开辟的内存， free也能够释放。
	}

	cout << "-----" << endl;

	int *array_p = new int[10];
	for (int i = 0; i < 10; i++) {
		array_p[i] = i + 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << array_p[i] << endl;
	}

	if (array_p != NULL) {
		delete[]   array_p; //delete 一个数组
	}


	cout << "-------" << endl;
	//Test *tp = new Test(10, 20);//调用了有参数的构造函数 
	//new 在创建一个对象的时候，会调用对象的构造函数
	Test *tp = new Test;//调用了无参构造函数
	tp->printT();
	if (tp != NULL) {
		delete tp; //delete在释放一个对象指针的时候，会调用对象析构函数
	}
}

int main(void)
{
	//test1();
	//test2();
	A *a = new A[10];
	delete[] a;
	return 0;
}

/*
new 也是用来分配堆内存，它是一个运算符，不是一个函数，因此效率相对于malloc得到了提高
    new一个对象会调用构造函数，new也是返回一个指针变量，无法正常分配空间时也返回一个空指针NULL

delete   释放new出来的指针，也可释放malloc的内存指针，它会调用对象的析构函数
   delete [] 和delete作用相当，但如果是
      class A{.....}； A *a  = new A[10]
			delete a 只调用a[0]的析构函数
			delete [] a，会调用a[0]到a[9]的析构函数
*/