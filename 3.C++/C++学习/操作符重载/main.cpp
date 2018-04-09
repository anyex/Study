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
	//��ӡ����
	void print()
	{
		cout << "(" << a << "+" << b << "i)" << endl;

	}

	friend Complex addComplex(Complex &c1, Complex &c2);
	//�����ⲿ��ȫ�ֺ���Ϊ��Ԫ

#if 0
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex& operator+=(Complex &c1, Complex &c2);
	friend Complex & operator-=(Complex &c1, Complex &c2);
	//ȫ��ǰ++��д��
	friend Complex &operator++(Complex &c1);
	friend Complex &operator--(Complex &c1);
	friend const Complex operator++(Complex &c1, int);

	//��++��Ա����
	const Complex operator++(int)
	{
		Complex temp(this->a, this->b);
		a++;
		b++;

		return temp;
	}

	//ǰ--�ĳ�Ա����
	Complex &operator--()
	{
		this->a--;
		this->b--;

		return *this;
	}

	//ǰ++�ĳ�Ա����
	Complex &operator++()
	{
		this->a++;
		this->b++;

		return *this;
	}


#endif

	friend ostream& operator<<(ostream&os, Complex &c);
	friend istream& operator >> (istream&is, Complex& c);
	// <<���������ֻ��д��ȫ���У����д���Լ���Complex�У�����˳��ͷ���


private:
	int a;//ʵ��
	int b;//����
};