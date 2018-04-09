#include "iostream"
using namespace std;

class Test
{
public:
	//Test(){};Ĭ�ϵĹ��캯�������ֶ��ṩһ�����캯����Ĭ�ϵĹ��캯���ͱ�����

	Test(int x, int y)//���ṩ������캯����Ĭ�ϵĹ��캯���Ͳ�������
	{
		m_x = x;
		m_y = y;
	}

	//�޲����Ĺ��캯��
	Test() {
		m_x = 0;
		m_y = 0;
		cout << "�������޲����Ĺ��캯��" << endl;
	}

	//�������캯����ͨ������һ��Test����another����ʼ���Լ�
	Test(const Test& another)
	{
		cout << "�����˿�����������" << endl;
		m_x = another.m_x;
		m_y = another.m_y;
	}

	//�ȺŲ�����
	void operator = (const Test &t)
	{
		cout << "������=�Ų�����" << endl;
		m_x = t.m_x;
		m_y = t.m_y;
	}

	void printT()
	{
		cout << "x: " << m_x << " y: " << m_y << endl;
	}

	//�ṩһ����������
	~Test()
	{
		cout << " ~Test() ����������ִ����" << endl;
		cout << "(" << m_x << "," << m_y << ")" << "��������" << endl;
	}




private:
	int m_x;
	int m_y;
};

//�������캯��1
void test1()
{
	Test t1(1, 2);
	Test t2(t1);

	//ͨ��t1��t2���и�ֵ
	t2.printT();
}
//�������캯��2

void test2()
{
	Test t1(1, 2);
	Test t2;
	t2 = t1;//���õĲ��ǿ������캯�������õ���"="�Ų�������Ҳ�ܹ���ɽ�
			//t1��ֵ��t2�����ǵ���t2�Ŀ������캯��

}

void func(Test t)
{
	cout << "func begin..." << endl;
	t.printT();
	cout << "func end..." << endl;
}

//�������캯��3
void test3()
{
	cout << "test3 begin..." << endl;
	Test t1(10, 20);//������һ��t1�Ķ���ͨ��t1���в����Ĺ��캯����ʼ��
	func(t1);//һ��������ֵ�ķ�ʽ���뺯������ÿ������캯��

	cout << "test3 end..." << endl;
}

int func(void)
{
	int a = 10;
	return a;
}

//�������캯��4
Test func2()
{
	cout << "func2 begin..." << endl;
	Test temp(10, 20);
	cout << "func2 end..." << endl;
	return temp;//��һ����ʱ����������temp����temp�����ݸ�����ʱ����������
				//����һ������Ҳ����ÿ������캯��
}

void test4()
{
	cout << "test4 begin...." << endl;
	func2();

	cout << "test4 end" << endl;
}

void test5()
{
	cout << "test5 begin...";
	Test t1 = func2();
	cout << "test5 end...";

}

void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;
	t1 = func2();

	cout << "test6 end..." << endl;
}

int main()
{
	test3();
	return 0;
}