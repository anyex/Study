#include <iostream>

using namespace std;

void divide(int x, int y)
{
	if (y == 0)
	{
		cout << "����y == 0" << endl;
		throw 0;//throw,divide���˳���
	}
	if (y == 1)
	{
		throw 'a';
	}

	cout << "x/y =" << x / y << endl;
}

void use_divide(int x, int y)
{
	try
	{
		divide(x, y);
	}
	catch (...)
	{
		cout << "use_divide ����δ֪�쳣��������" << endl;
		throw; //�м�㺯���������쳣���������մ���ֱ��������
	}

}

int main(void)
{
	try {

		use_divide(10, 1);
		use_divide(10, 0);

	}
	catch (int e)//�쳣��������ƥ�䣬����ƥ�䷵�ص�int�����쳣
	{
		cout << "�������쳣 e = " << e << endl;
	}
	catch (char e)
	{
		cout << "�������쳣 e = " << e << endl;
		//throw e;//����쳣�׵����㣬������������ͺ����ִֹ��
	}
	catch (...)//�ܹ������������͵��쳣
	{
		cout << "����δ֪�쳣" << endl;
	}

	return 0;
  }

//1 �쳣�Ĳ������ϸ�������ƥ��
//2 �쳣���Բ������� ���������ף��м����Բ���Ҫ������һ��ͳһ�����쳣�ĺ���ͳһ����
//3 ���˵�쳣һֱ�����ף� û�к������� ���ղ���ϵͳ�Ὣ����������
