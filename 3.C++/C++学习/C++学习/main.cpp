//c����
#if 0
#include "stdio.h"

int main()
{
	int a = 0;
	printf("Hello World!\n");

	printf("������һ������");
	scanf("%d", &a);
}
#endif

//c++
#include <iostream>

using namespace std;//�����ռ�

/*
  iostream���и�һ�������ռ�std������׼�����ռ�
  ���а���cout,cin,endl�ȹؼ���
  
*/

int main()
{
	int a = 0;
	cout << "Hello world" << endl;//cout��һ����׼�����endl������

	cout << "������һ������" << endl;
	cin >> a;

	cout << "a = " << a << endl;
	return 0;
}