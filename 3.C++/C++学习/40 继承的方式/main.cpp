#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//����
class Parent
{
public: //���ʿ���Ȩ��
	int pub; //������ڲ��ⲿ�����Է��ʣ�������Ҫͨ����Ա�����Ϳ��������ʵ������
protected:
	int pro;// protected ���ʿ���Ȩ���µ� ���ں��������ֱ�ӷ���
private:
	int pri;//������ ��������  //���׵�����  //private ���ʿ���Ȩ���µĳ�Ա ���Ӳ��ɼ�
};

class Child :public Parent //Child ���м̳� Parent
{
	void func()
	{
		pro; //ok//������˽�еĺͱ����ġ�
			 //pri; //���ʲ��˸��׵�˽�г�Ա
	}
};

//����ԭ��:
//1  ����ǰ�ĳ�Ա������������ⲿ ����������ڲ�
//2 �����ӵļ̳з�ʽ�� �ǹ��м̳л��� ˽�м̳�
//3 ����ǰ�ĳ�Ա�����ڸ����еķ��ʿ���Ȩ��

class Child2 : protected Parent
{
	void func()
	{
		pub; //�ڲ�  //��ʱpub ���� �ڴ������� protectedȨ��
			 //pri;
	}
};

class Child3 : private Parent
{
	void func()
	{
		pub; //�����е�public ��� ������˽��
		pro;//�����е�pro  ��ɱ����˽��
	}
};

class SubChild3 : public Child3
{

	void func()
	{
		//pub;�丸��Child3�У�pub��pro����Ϊ˽��
		//pro;
	}
};

//1 �����е�˽�г�Ա ����������μ̳У� ���඼���ʲ��ˡ�
//2 ����ǹ���(public)�̳У� ��ô�����еķ��ʿ���Ȩ�� ����˽�г�Ա ���������б��ֲ���
//3 ����Ǳ����̳�protected �� ��ô�����г��˻����˽�г�Ա��ȫ����protectedȨ��
//4 �����˽�м̳� private  �� �����г���˽�г�Ա�� �����඼�� ˽�г�Ա��

int main(void)
{
	Parent p;
	p.pub;

	Child c;
	c.pub; // 
	Child c;
	//	c.pro; //
	//c.pro; //��ʱpro ������˽�е� Ҳ�����Ǳ����ġ�

	Child2 c2;
	//c2.pub;
	//c2.pro; //��ʱpro ��Child2����һ������Ȩ�ޣ� ������ⲿ���ʲ��ˡ�
	Child3 c3;
	

	return 0;
}