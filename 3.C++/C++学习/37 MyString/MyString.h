#pragma once
#include <iostream>
using namespace std;

class MyString
{
public:
	MyString();
	~MyString();

	MyString(int len);//开辟len个长度的字符串，全部设置为0
	MyString(const MyString &another);//拷贝构造函数
	MyString &operator= (const MyString &another);//重载 =
	MyString(const char*str);//根据str字符串初始化mystring

	char &operator[](int index);//重载[]操作符

	bool operator ==(const MyString &another);//重载 ==
	bool operator !=(const MyString &another);//重载 !=
	bool operator >(const MyString &myString);//重载 >
	bool operator <(const MyString &myString);//重载 <

	friend ostream &operator <<(ostream &os, MyString &s);
	friend istream &operator >> (istream &is, MyString &s);

	int getLen();
private:
	char *str;
	int len;
};