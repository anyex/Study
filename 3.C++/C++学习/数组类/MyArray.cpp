#include "MyArray.h"
#include <iostream>
using namespace std;
MyArray::MyArray()
{
	space = NULL;
	length = 0;
}

MyArray::MyArray(int len)
{
	if (len < 0)
	{
		length = 0;
		space = NULL;
	}
	else
	{
		length = len;
		space = new int[this->length];
	}

}

MyArray::MyArray(const MyArray& another)
{
	if (another.length >= 0)
	{
		this->length = another.length;
		this->space = new int[this->length];

		for (int i = 0; i<this->length; i++)
		{
			this->space[i] = another.space[i];
		}
	}
}

MyArray::~MyArray()
{
	if (this->space != NULL)
	{
		delete[] this->space;
		this->length = 0;
		this->space = NULL;
		cout << "MyArray::~MyArray()  ±»µ÷ÓÃ" << endl;

	}
}


int MyArray::getLen()
{
	return this->length;
}

void MyArray::setData(int index, int data)
{
	if (this->space != NULL)
	{
		this->space[index] = data;
	}
}

int MyArray::getData(int index)
{
	return this->space[index];
}
int MyArray::operator[](int i)
{
	return this->space[i];
}