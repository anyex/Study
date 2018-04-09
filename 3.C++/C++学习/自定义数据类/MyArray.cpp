#include "MyArray.h"
#include<iostream>

using namespace std;

MyArray::MyArray()
{
	cout << "MyArray()....." << endl;
	len = 0;
	space = nullptr;
}

MyArray::MyArray(int len) {
	if (len <= 0)
	{
		this->len = 0;
		return ;
	}
	else
	{
		this->len = len;
	}
};
MyArray:: ~MyArray()
{
	if(this->space!=NULL)
	{
		delete[]this->space;
		this->space = NULL;
		len = 0;
		cout << "MyArray::~MyArray()...." << endl;
	}
};
void MyArray::setData(int index, int data) 
{
	if (this->space != NULL)
	{
		this->space[index] = data;
	}
};//赋值
int MyArray::getData(int index)
{
	if ((this->space != NULL) &&(index<this->len))
	{
		return space[index];
	}
	
};//
int MyArray:: getLen()
{

	return this->len;
};//获取长度

int main()
{
	MyArray array1(10);
} 
