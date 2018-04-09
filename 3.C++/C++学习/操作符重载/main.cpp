#include <iostream>
using namespace std;

class Complex {
public:
	Complex()
	{
		this->a = 0;
		this->b = 0;
	}
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	//打印虚数
	void print()
	{
		cout << "(" << a << "+" << b << "i)" << endl;

	}

	friend Complex addComplex(Complex &c1, Complex &c2);
	//声明外部的全局函数为友元

#if 0
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex& operator+=(Complex &c1, Complex &c2);
	friend Complex & operator-=(Complex &c1, Complex &c2);
	//全局前++的写法
	friend Complex &operator++(Complex &c1);
	friend Complex &operator--(Complex &c1);
	friend const Complex operator++(Complex &c1, int);

	//后++成员函数
	const Complex operator++(int)
	{
		Complex temp(this->a, this->b);
		a++;
		b++;

		return temp;
	}

	//前--的成员函数
	Complex &operator--()
	{
		this->a--;
		this->b--;

		return *this;
	}

	//前++的成员函数
	Complex &operator++()
	{
		this->a++;
		this->b++;

		return *this;
	}


#endif

	friend ostream& operator<<(ostream&os, Complex &c);
	friend istream& operator >> (istream&is, Complex& c);
	// <<运算符重载只能写在全局中，如果写在自己的Complex中，调用顺序就反了


private:
	int a;//实数
	int b;//虚数
};