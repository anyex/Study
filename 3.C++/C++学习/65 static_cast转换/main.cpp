#define _CRT_SCEURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	double PI = 3.14159265357489;
	int num2 = (int)PI;//C���Ե�ת����ʽ
	int num3 = static_cast<int>(PI);//���ӿɶ��ԣ�������ͨ���͵�ǿ��ת��

	//static_cast ʵ���ϱ������ڱ����ʱ����Ѿ���PI����Ϊint����

	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;

	return 0;
}
/*
static_cast<> �������õ��������ͣ����м̳й�ϵ��ָ�������֮��Ļ���ת��
*/