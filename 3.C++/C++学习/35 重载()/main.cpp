#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Sqr {
public:
	Sqr(int a)
	{
		this->a = a;
	}
	int operator()(int a)
	{
		return a*a;
	}
private:
	int a;
};

void func(int a, int(*fp)(int))
{
	cout << a << "ƽ���Ľ����:" << endl;
	cout << fp(a) << endl;
}

int sqr(int a)
{
	return a*a;
}

class Print {
public:
	void operator()(int value)
	{
		cout << value << endl;
	}


};

void print(int value)
{
	cout << value << endl;
}

int main()
{
	Sqr s(10);
	int b = 20;

	int aa = s(b);//��һ����������ͨ�������ã���Ϊ�º�����α����
	//s.operator()(a),��һ�����󵱳�һ���ص���������ȥ�����Ƿº���������

	cout << aa << endl;
	func(b, sqr);
	
	return 0;
}
