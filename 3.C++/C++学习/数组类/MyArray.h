#pragma once
#ifndef _MYARRAY_H_
#define _MYARRAY_H_

class MyArray
{
public:
	//�޲ι��캯��
	MyArray();

	//�ڸ������ʼ��ʱ�����ٿռ�
	MyArray(int len);

	//�������캯��
	MyArray(const MyArray& another);

	//�������鳤��
	int getLen();

	//�����������Ӧ�±��ֵ
	void setData(int index, int data);

	//��ȡ������Ӧ�±��ֵ
	int getData(int index);

	~MyArray();
	int operator[](int i);

private:
	int length;
	int *space;//����ռ�
};


#endif // !_MYARRAY_H_

//һ�㲻Ҫ���ļ��а���ͷ�ļ�

