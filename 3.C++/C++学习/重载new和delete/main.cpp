#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		this->a = 0;
		cout << "���캯������" << endl;
	}

	A(int a)
	{
		this->a = a;
		cout << "�в�����A(int a)��������" << endl;
	}
	~A()
	{
		cout << "������������" << endl;
	}

	//����һnew������
	void *operator new[](size_t size)
	{
		cout << "������һ��new[] ������" << endl;

		return malloc(size);
	}
		void operator delete(void *p)
	{
		cout << "������һ��delete������" << endl;
		if (p != NULL)
		{
			free(p);
		}
	}

	void operator delete[](void *p)
	{
		cout << "������һ��delete[] ������" << endl;
		if (p != NULL)
		{
			free(p);
		}
	}

private:
	int a;
};

int main(void)
{
	int *p = new int; //�ڶ��Ͽ���һ��int
	*p = 20;
	cout << *p << endl;
	delete p;

	A *ap = new A; //�����������ص�new

	delete ap;


	int *array_p = new int[10];// ����һ������  new[]
	delete[] array_p;

	A *array_ap = new A[10]; //������10 ��A���������׵�ַ array_ap
	delete[] array_ap;

	return 0;
}