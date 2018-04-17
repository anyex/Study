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
	void print()
	{
		cout << "(" << a << "+" << b << "i)" << endl;
	}

	//friend Complex operator+(Complex &c1, Complex &c2);
	//friend Complex &operator +=(Complex&c1, Complex &c2);
	//friend Complex &operator -=(Complex&c1, Complex &c2);
	//friend Complex &operator++(Complex &c); 前++
	//friend Complex &operator++(Complex &c, int);
	friend ostream& operator<<(ostream& os, Complex &c);
	friend istream& operator >> (istream& is, Complex &c);
	Complex operator+(Complex &another)
	{
		Complex temp(another.a + this->a, another.b + this->b);
		return temp;
	}
	Complex operator-(Complex &another)
	{
		Complex temp(-another.a+this->a, -another.b + this->b);
		return temp;
	}

	Complex &operator+=(Complex &another)
	{
		this->a += another.a;
		this->b += another.b;

		return *this;
	}
	Complex &operator++()
	{
		this->a ++;
		this->b ++;
		return *this;
	}

	//后++,int为占位符，为了和前++区别，使其能重载
	Complex &operator++(int)
	{
		Complex a(this->a, this->b);
		this->a++;
		this->b++;
		return a;
	}
	/*
	ostream &operator<<(ostream &os)
	{
	}
	*/
	
	//左移操作符只能写在全局，不能写在成员函数中，否则调用的顺序会变反，变成c1<<cout
private:
	int a;//实数部分
	int b;//虚数部分
};

#if 0
//全局函数
//+
Complex operator+(Complex &c1, Complex &c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);

	return temp;
}
 
//+=
Complex &operator +=(Complex&c1, Complex &c2)
{
	c1.a -= c2.a;
	c1.b -= c2.b;

	return c1;
}
//-=
Complex &operator -=(Complex&c1, Complex &c2)
{
	c1.a += c2.a;
	c1.b += c2.b;

	return c1;
}

//后++
Complex &operator++(Complex &c)
{
	c.a++;
	c.b++;
	return c;
}

//前++
Complex &operator++(Complex &c, int)
{
	Complex temp(c.a, c.b);
	c.a++;
	c.b++;
	return temp;
}

#endif
ostream& operator<<(ostream& os, Complex &c)
{
	os<< "(" << c.a << "+" << c.b << "i)" << endl;
	return os;
	//os为传入的cout，c为传入的Complex
}

istream& operator >> (istream& is, Complex &c)
{
	cout << "a:";
	is >> c.a;
	cout << "b:";
	is >> c.b;
	return is;
}

int main()
{
	Complex c1(1, 2);
	Complex c2(1, 3);

	//Complex c3 = c1 + c2+c2+c1;//对于全局函数相当于 operator+(c1,c2)
						   //对于类的内部函数相当于 c1.operator+(c2)
						   //这两个都会被匹配，导致产生二义性
	//c3.print();
	//c3 = c3 - c2 - c1;
	
	cout << c1 << c2 << endl;
	return 0;
}