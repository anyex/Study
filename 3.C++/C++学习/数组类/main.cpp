#include "MyArray.h"
#include <iostream>
using namespace std;


int main(void)
{
	MyArray array1(10); //����MyArray �в������캯��

						//����һ�����������Ԫ��
	for (int i = 0; i< array1.getLen(); i++) {
		array1.setData(i, i + 10);
	}

	cout << " -------- " << endl;

	//����һ�����������Ԫ��
	for (int i = 0; i < array1.getLen(); i++) {
		cout << array1.getData(i) << endl;
	}

	cout << " ---һ���ǿ������캯������----" << endl;
	MyArray array2 = array1; //������array2�Ŀ������캯��

	for (int i = 0; i < array2.getLen(); i++) {
		cout << array2.getData(i) << endl;
	}

	cout << "array1[5]" << array1[5];

	return 0;
}