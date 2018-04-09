#pragma once
class MyArray
{
public:
	MyArray();
	MyArray(int len);
	virtual ~MyArray();
	void setData(int index, int data);//赋值
	int getData(int index);//
	int getLen();//获取长度
private:
	int len;
	int* space;//开辟的堆空间
};

