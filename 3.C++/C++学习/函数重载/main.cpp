#include <iostream>

using namespace std;

void func(int a)//void ()(int),��������
{
	cout << "func1" << endl;
	cout << a << endl;
}

void func(int a, int b)// void ()(int ,int ),��������
{

}

//����ֵ���Ͳ�ͬ�����ܹ�������
/*
char func()
{

}
*/
void print(double a)
{
	cout << "print double " << endl;
	cout << a << endl;
}

void print(float a)
{
	cout << "print float" << endl;
	cout << a << endl;
}
void func(int a, int b, char *str)
{
	cout << "func3" << endl;
	cout << a << ", " << b << ", " << str << endl;
}

#if 0
void print(int a)
{
	cout << "print int" << endl;
	cout << a << endl;
}

void print(char a)
{
	cout << "print char" << endl;
	cout << a << endl;
}
#endif




int main(void)
{
	//����һ�� ָ��void func(int a)�ĺ���ָ��
	//void(*fp)(int) = func;//fp ����ִ�� void()(int) ���ֺ������͵�ָ��

	//fp(10);


	func(10); //������ ������û����ݵĲ������ͺ͸��� �������غ�����ƥ��
			  //���˵�������� ������Ĭ�ϲ����� �ص��µ��ú�����ʱ����ֶ����ԣ�
			  //��ס��  �������� ��ò�Ҫ��Ĭ�ϲ�����
	func(10, 20);
	func(10, 20, "abc");


	//print(10); //void print(int a)
	//print(1.1);//void print(double a)

	//print(1.1f); // ������ʽת�� �����void print(double a)
	//print('a'); //������ʽת���� 'a' ->int   void print(int a)

	//print("asbdasd");

	//1 �ϸ���в����б�ƥ��
	//2 �����ʽת�������ҵ�ƥ�� ��ô��Ȼ���Ե���
	//3 ���ƥ�䲻���� ֱ�ӱ���




	return 0;
}
/*
����������һ�ֶԺ�������Ӷ��ֲ�ͬ��ʵ��
   �������ؾ��ǶԲ����б�ı任�����Ǻ�������ֵ�ı仯������ֵ����һ��
   �����б�ͬ���Һ�������ͬ�ĺ����������غ���

   ���������ȫ��ͬҲ����һ����������

*/