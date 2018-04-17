#pragma once
#include <iostream>
using namespace std;

class MyString
{
public:
	MyString();
	~MyString();

	MyString(int len);//����len�����ȵ��ַ�����ȫ������Ϊ0
	MyString(const MyString &another);//�������캯��
	MyString &operator= (const MyString &another);//���� =
	MyString(const char*str);//����str�ַ�����ʼ��mystring

	char &operator[](int index);//����[]������

	bool operator ==(const MyString &another);//���� ==
	bool operator !=(const MyString &another);//���� !=
	bool operator >(const MyString &myString);//���� >
	bool operator <(const MyString &myString);//���� <

	friend ostream &operator <<(ostream &os, MyString &s);
	friend istream &operator >> (istream &is, MyString &s);

	int getLen();
private:
	char *str;
	int len;
};