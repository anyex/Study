#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
class Test
{
public:
	//�޲ι��캯��
	Test()
	{
		m_x = 0;
		m_y = 0;

		p = (char*)malloc(100);

		strcpy(p, "123");
	}

	//�������Ĺ��캯��
	Test(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	//һ�������Ĺ��캯��
	Test(int x)
	{
		m_x = x;
		m_y = 0;
	}

	//��������,û���κβ���
	~Test()
	{
		cout << "Test ����������~Test()��������" << endl;
		if (p != NULL)
		{
			cout << "p�Ķѿռ䱻�ͷ���" << endl;
			free(p);
			p = NULL;
		}
	}

	void printT()
	{
		cout << "x: " << m_x << ",y: " << m_y << endl;
	}

	void init(int x, int y)
	{
		m_x = x;
		m_y = y;
	}



private:
	int m_x;
	int m_y;
	char *p;

};


void test1()
{
	Test t1;//�����޲����Ĺ��캯��
			//t1��һ���ֲ�����������������test1()һ������test1()����ִ�������Ҫ������t1����
	t1.printT();
	return;//���������ٵ�ʱ��������������
	        
}
int main()
{
	Test t1;//����һ��������������ֱ�ӵ����޲ι��캯��
	t1.init(10, 20);//��ʽ����һ����ʼ���ĺ���
	test1();

	Test t2(10, 20);//����ô����������Ĺ��캯��

	return 0;
}


/*
 ���캯����Ϊ�˸������ṩ��ʼ�������ֵ�
 �������ָ�����һ����û�з���ֵ���ҿ�������
*/

/*

���н����

x: 0,y: 0
Test ����������~Test()��������
p�Ķѿռ䱻�ͷ���


*/