#include <iostream>

using namespace std;

void func(int a, int b)
{
	cout << a << b << endl;
}

void func(int a, int b, int c)
{
	cout << a << b << c << endl;
}

void func(int a,int b,int c,int d)
{
	cout << a << b << c << d << endl;

}

typedef void(myfunctype)(int, int);//����һ���������ͷ���ֵvoid,�����б�int,int
typedef void(*myfunctype_pointer)(int, int);//������һ������ָ������

int main()
{
	myfunctype_pointer fp1 = NULL;
	fp1 = func;

	fp1(10, 20);

	myfunctype_pointer fp2 = NULL;
	fp2 = func;

	fp2(10, 20);

	void(*fp3)(int, int) = NULL;

	fp3 = func;
	fp3(10, 20);
	//fp3(10, 20, 30, 40);����ͨ������ָ�뷢�����أ�fp3�㶨ָ��һ��������ڣ�void func(int,int)��

	return 0;
}