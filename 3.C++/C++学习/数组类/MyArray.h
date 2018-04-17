#pragma once
#ifndef _MYARRAY_H_
#define _MYARRAY_H_

class MyArray
{
public:
	//无参构造函数
	MyArray();

	//在给数组初始化时，开辟空间
	MyArray(int len);

	//拷贝构造函数
	MyArray(const MyArray& another);

	//返回数组长度
	int getLen();

	//设置数组的相应下标的值
	void setData(int index, int data);

	//获取数组相应下标的值
	int getData(int index);

	~MyArray();
	int operator[](int i);

private:
	int length;
	int *space;//分配空间
};


#endif // !_MYARRAY_H_

//一般不要在文件中包含头文件

