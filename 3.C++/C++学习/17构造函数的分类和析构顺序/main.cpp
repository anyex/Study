#include <iostream>

using namespace std;
#pragma warning(disable:4996)
class Test {
public:
	/*
	������ṩ���캯����ϵͳ�͵���Ĭ�ϵĹ��캯��

	Test(){} Ĭ�ϵĹ��캯��������Ѿ��ֶ��ṩ��Ĭ�Ͼͱ�����

	���캯��һ���ֶ��ṩ��Ĭ�ϾͲ�������

	*/
	Test(int x, int y)
	{
		m_x = x;
		m_y = y;

		cout << "�������в����Ĺ��캯��" << endl;
	}

	//�޲����Ĺ��캬
	Test() {
		m_x = 0;
		m_y = 0;
		cout << "�������޲����Ĺ��캯��" << endl;
	}

	//�������캯����ͨ������һ��Test���󽫱�������п���
	Test(const Test &another)
	{
		m_x = another.m_x;
		m_y = another.m_y;

		cout << "�����˿������캯��" << endl;
	}
	//�ȺŲ�����
	void operator = (const Test &t)
	{
		m_x = t.m_x;
		m_y = t.m_y;
		cout << "�����˵ȺŲ�����" << endl;
	}

	void printT()
	{
		cout << "x: " << m_x << ",y:" << m_y << endl;
	}

	//��������
	~Test()
	{
		cout << "~Test()������ִ����" << endl;
		//cout << "(" << m_x << ", " << m_y << ")" << "��������" << endl;
		cout << s << "��������" << endl;
	}
	char s[20];
private:
	int m_x;
	int m_y;
	
};


void test()
{
	Test t1;//�����޲ι��캯��
	strcpy(t1.s ,"t1");
	Test t2(10, 20);
	t2.printT();
	Test t3(t2);//����t3�Ŀ������캯��
	t3.printT();

	Test t4(100, 200);
	Test t5;
	t5 = t2;//����=�����ز���������ֵ����
	strcpy(t2.s, "t2");
	strcpy(t3.s, "t3");
	strcpy(t4.s, "t4");
	strcpy(t5.s, "t5");
			//������˳�򣬸�����Ĺ���˳���෴��˭�ȹ��죬˭�������
	Test t6 = t4;

}
int main()
{
	test();

	return 0;

}

/*
���н����

�������޲����Ĺ��캯��
�������в����Ĺ��캯��
x: 10,y:20
�����˿������캯��
x: 10,y:20
�������в����Ĺ��캯��
�������޲����Ĺ��캯��
�����˵ȺŲ�����
~Test()������ִ����
t5��������
~Test()������ִ����
t4��������
~Test()������ִ����
t3��������
~Test()������ִ����
t2��������
~Test()������ִ����
t1��������
*/