#include <iostream>
using namespace std;

int getA1()
{
	int a = 10;
	return a;
}

int &getA2()
{
	int a = 10;
	return a;
}

int &getBB()
{
	static int b = 100;

	return b;
}



int main()
{
	int value_a = 0;
	value_a = getA1();

	cout << "value_a = " << value_a << endl;

	value_a = getA2();//int value_a = *temp,����һ��ֵ����������ʹ��

	cout << "value_a" << value_a << endl;
	cout << "value_a" << value_a << endl;

	int &r_a = getA2();//����������ֵ��һ���ֲ�����������ʱ��������������������

	cout << "r_a " << r_a << endl;
	cout << "r_a " << r_a << endl;//��ʱ�����Ϊ��ֵ

	int &r_b = getBB();//r_b����getBB�е�static int b
					   //����������ֵ�������Ӻ����ڲ��ֲ��������Ϳ���ʹ�����ý��н���

	cout << "r_b " << r_b << endl;
	cout << "r_b " << r_b << endl;

	r_b = 2000;//r_b����getBB�е�static int b�������޸ĵ�Ҳ��getBB�е�ֵ

	int value_b = getBB();

	cout << "value_b " << value_b << endl;

	getBB() = 3000;//��������Ϊ�����ķ���ֵ��ʱ��ֻҪ������úϷ����Ϳ��Ե���ֵ
	value_b = getBB();
	cout << "value_b " << value_b << endl;
	//��Ŀ�����
	int a = 10;
	int b = 20;

	(a < b ? a : b) = 30;//����Ҳ�൱����a,b����Ϊ�����ã��ܹ�����ֵ

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;

}