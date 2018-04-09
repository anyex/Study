#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(float x=0,float y=0):_x(x),_y(y){}
	void dis()
	{
		cout << "(" << _x << "," << _y << ")" << endl;

	}
	friend const Complex operator+ (const Complex &c1, const Complex &c2);//��Ԫ����
	const Complex operator+(const Complex &another);//��Ա����
private:
	float _x;
	float _y;

};
const Complex operator+(const Complex&c1, const Complex &c2)
{
	cout << "��Ԫ��������" << endl;
	return Complex(c1._x + c2._x, c1._y + c2._y);

}

const Complex Complex::operator+(const Complex& another)
{
	cout << "��Ա��������" << endl;
	return Complex(this->_x + another._x, this->_y + another._y);//����һ��Complex��ʵ������
}

void test()//��Ԫ����
{
	Complex c1(2, 3);
	Complex c2(3, 4);

	c1.dis();
	c2.dis();

	
	
}
//��Ա��������
void test1()
{
	Complex c1(2, 3);
	Complex c2(3, 4);

	c1.dis();
	c2.dis();

	Complex c3 = c1.operator+ ( c2);
	c3.dis();
}

int main()
{
	
	//test1();
	Complex c1(2, 3);
	Complex c2(3, 4);

	c1.dis();
	c2.dis();

	
	
	return 0;

}