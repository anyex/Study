#include <iostream>

using namespace std;

void func(const char* p)
{
	char *pp = const_cast<char *>(p);//��p��const����ȥ��
	pp[0] = 'A';
}

int main()
{
	const char *p = "12343545";
	char buf[] = "123432524314";

	func(buf);//�ַ�����Գ����ַ��������˿������������޸�
	//func(p);//pָ����ַ����洢�ڳ���ȥ�����Բ������޸�

	//cout << "p:" << p << endl;
	cout << "buf:" << buf << endl;

	const int a = 10;
	const int *a_p = &a;

	int *a_p1 = const_cast<int *>(a_p);//��a_p������ȥ��

	*a_p1 = 100;

	int *p2 = const_cast<int *>(&a);
	cout << "*a_p = " << *a_p << endl;
	cout << "a= " << a << endl;
	cout << "*p2 " << *p2 << endl;



	//const_cast �����þ��� ��һ����ֻ�����Ե�ָ�룬��ֻ������ȥ��������ǰ���ǵ�ǰ���ڴ�ռ��ǿ����޸ġ�
	return 0;

}


