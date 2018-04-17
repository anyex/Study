#include <iostream>

using namespace std;
class Test {
public:
	Test(int k)
	{
		this->m_k = k;
		this->m_q = 0;
	}

	Test(int k, int q)
	{
		this->m_k = k;
		this->m_q = q;
	}

	/*
	int getK(Test *this)
	{

	}//在类的内部不能定义this指针

	Test* this;
	*/
	
	int getK() const//相当于int getK(const Test *const this),this是一个常指针
	{
		//this->m_k = 0;在成员函数后面加const修饰的不是函数，而是隐藏的this指针，所以this指向常量，即this指向的值不能被改变

		return this->m_k;
	}

private:
	int m_k;
	int m_q;
};

int main(void)
{
	Test t1(10);  //  Test t1(&t1, 10)
	Test t2(20);

	t1.getK();

	t2.getK(); // t2.getK(&t2)

	return 0;
}