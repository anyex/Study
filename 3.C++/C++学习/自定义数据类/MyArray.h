#pragma once
class MyArray
{
public:
	MyArray();
	MyArray(int len);
	virtual ~MyArray();
	void setData(int index, int data);//��ֵ
	int getData(int index);//
	int getLen();//��ȡ����
private:
	int len;
	int* space;//���ٵĶѿռ�
};

