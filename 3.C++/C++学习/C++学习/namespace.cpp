#include "iostream"

using std::cout;//���������ռ��еı���
using std::endl;

using namespace std;//�������������ռ�

int aa;//Ĭ�ϵ�ȫ�������������ռ�

//�Զ��������ռ�

namespace namespaceA 
{
	int a = 10;
	int b = 20;
}

//�����ռ����Ƕ��
namespace namespaceB
{
	int a = 20;
	namespace namespaceC 
	{
		struct teacher 
		{
			int id;
			char name[64];

		};

	}

	namespace namespaceD {
		struct  teacher
		{

		};
	}
}

//ʹ���Զ���������ռ�
void test()
{
	using namespaceA::a;//�����ԱӦ��a��Ĭ��ʱnamespaceA�е�ֵ
	using namespace namespaceA;//��������namespaceA�ռ�

	//int a = 5;����ʾ�ض���
	cout << "A::a = " << namespaceA::a << endl;
	cout << "B::a=" << namespaceB::a << endl;
	cout << "a=" << a << endl;
	using namespace namespaceB::namespaceC;

}

int main()
{
	test();
	return 0;
}