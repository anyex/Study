#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define MY_MAX(a, b) ((a) < (b)? (a):(b))

inline int my_func(int a, int b)
{
	return (a < b ? a : b);
}

inline void printAB(int a, int b);


int main()
{
	int a = 1;
	int b = 3;

	int c = my_func(++a, b);//�ڱ���ʱ�Ὣmy_func(++a,b)չ��Ϊ(a<b?a:b),�Ӷ�������д�ɺ����Ŀ���
							//���������ڵ���ģʽ�У����ᱻ������������ͨ����һ�����ɺ��е�����Ϣ�Ŀ�ִ�д���
	                        
	printAB(++a, b);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	system("pause");

	return 0;
	
}

//printAB���ܱ�����
void printAB(int a, int b)
{
	cout << "a = " << a << ", b = " << b << endl;
}