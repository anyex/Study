#pragma warning(error:4996)
#include <iostream>
using namespace std;

void myPrint(int a, int b)
{
	cout << "��ͨ����" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "ģ�庯��" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}
int main(void)
{
	int aInt = 10;
	int bInt = 20;

	char aChar = 'a';
	char bChar = 'b';

	myPrint(aInt, bInt);

	cout << " ----- " << endl;
	myPrint(aChar, bChar);

	cout << " ------  " << endl;
	myPrint(aChar, bInt);

	cout << " ------ " << endl;
	myPrint(aInt, bChar);

	return 0;
}

//1  ���û����ͨ���� �������������ģ�庯��������ʽ��ƥ�䡣���ƥ�䵽ģ�庯�����Ե��ã�����ģ��
//2  ������ƥ����ͨ���������ȼ� ���� ģ�庯��
//3 ����ͨ������Ҫ��ʽת����ʱ�����ģ�庯���ܹ�ƥ�䣬��ô������ʹ��ģ�庯����
//4 ģ�庯�� �����͵��ϸ�ƥ�� ��������������ͽ�����ʽת����