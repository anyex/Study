

#include <iostream>
using namespace std;

struct TypeA
{
	int *a;
};

struct  TypeB
{
	double &a;
};

struct Teacher {
	int id;
	char name[64];
};

void motifyTeacher(Teacher &t)
{
	t.id = 100;//t��������һ����ָ�룬*t����ָ��ָ���ڴ�ռ�;
			   //����ͼ�޸Ļ��߻�ȡ�Ѿ���ʼ�������õ�ʱ�򣬱���������һ�����ص�*�Ĳ�������(*t).id = 100


}

void motifyA(int* const a)//��ָ��Ҳ��һ��������Ҳ���뱻��ʼ����Ҳ���ܱ��޸�
{
	*a = 100;
}

void motifyB(int &a)
{
	a = 1000;//aʵ������һ������ָ�룬���������a��ֵ������������һ�����εĲ�����*


}


//���ÿ������Ϊһ����ָ�룬��ʹ�õ�ʱ�򣬿���˵���������ı���

void test()
{
	int value = 20;
	Teacher t1 = { 1,"����" };
	motifyA(&value);
	cout << "value = " << value << endl;
	motifyB(value);//int value --> int &a,
	cout << "value = " << value << endl;
	motifyTeacher(t1);//������������Teacher &t���β���һ�����ã������ø���ֵ��ʱ�򣬻���һ��&�����β���


}

void motifyAA(int *a)
{
	*a = 100;
}

void motifyBB(int &a)
{
	a = 200;
}

void test2()
{
	int a = 10;

	motifyAA(&a);//�����˹���

	motifyBB(a);//
}

int main()
{
	int a = 10;
	int b = 20;

	const int c_a = 10;//������ʼ��֮�󣬲������޸�

	int &re = a;       //���ñ����ʼ���������ڳ�ʼ��֮��Ҳ���ܹ����ı�
	re = b;            //a=b����������re����ָ��b���൱���ǽ�b��ֵ��ֵ��re��a����

	//
	cout << "re = " << re << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	re = 100;//��ʱ�޸ĵ���a��ֵ��

	cout << "re = " << re << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "sizeof(TypeA): " << sizeof(TypeA) << endl;
	cout << "sizeof(TypeB):" << sizeof(TypeB) << endl;

	//ͨ�����������С�� ���ֲ���������ʲô���� ����4���ֽڣ�����ָ��Ĵ�Сһ����

	


	test();

	return 0;

}