#include <iostream>

using std::cout;//using �ؼ���,���������ռ��һ������
using std::endl;

using namespace std;//����std���������ռ�
int aa;//Ĭ�ϵ�ȫ��������������ռ�

//����һ�������ռ�

namespace A //�����������ռ�A
{
	int a = 10;
	int b = 20;
}

namespace B //�����ռ��ڲ�Ҳ���Զ��������ռ�
{
	int a = 20;
	namespace C//Ƕ�׶��������ռ�C
	{
		struct teacher
		{
			int id;
			char name[64];
		};
	}

	namespace D
	{
		struct teacher
		{

		};
	}
}

//ʹ���Զ���������ռ�
void test()
{
	using A::a;//���еı���a��Ĭ��ʱ�����ռ�A�е�a
	using namespace B;//�������������ռ�B
	
	a = 50;

	cout << "A::a = " <<A::a << endl;
	cout << "B::a =" << B::a << endl;
	cout << "a = " << a << endl;

	//��ʽ1
	using namespace B::C;//��C�е����ж���ı���������
	teacher t1;

	//��ʽ2
	using B::C::teacher;
	teacher t2;

	//��ʽ3
	B::C::teacher t3;
	
	//��ʽ4
	using namespace B;
	C::teacher t;
}

int main()
{
	test();
	return 0;
}

/*
ʹ�������ռ�ı���ʱ�����ܳ��ֲ���ʶ����������������������ռ䶼��ͬ����ͬ���͵ı�������ͬʱ����
��  using namespace A;
    using namespace B;
	a = 20;//������ʶ���a������A��������B���ᱨ��

	
	�����ռ佫ȫ��������ֳɲ�ͬ�Ĳ���
	��ͬ�����ռ��еı�ʶ������ͬ�������ᷢ����ͻ
	�����ռ�Ҳ����Ƕ��
	ȫ��������Ҳ��Ĭ�������ռ�

*/