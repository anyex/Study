#include <iostream>

using namespace std;


#define MY_MAX(a,b) ((a)<(b)?(a):(b))

//inline ��һ���ؼ��֣�����˺������������������ں�������ֵ��ǰ��
inline int my_func(int a, int b)
{
	return (a < b ? a : b);
}

inline void printAB(int a, int b);

int main()
{
	int a = 10;
	int b = 20;

	MY_MAX(a++, b);
	printAB(a, b);
	(a++) < (b) ? (a++) : (b);
	my_func(a++, b);

	return 0;
}

//�������������inline�ؼ��֣�����������û��дinline,��������Ȼ���ᵱinline��������
void printAB(int a, int b)
{
	cout << "a = " << a << ", b = " << b << endl;
}

/*
���������ڵ��õ�ʱ�򣬲�����ͨ������ѹջ�ͳ�ջ�Ŀ���
�������������ǰ���ͨ������ѹջ�ͳ�ջ����ʡȥ�ˣ����еı������ʷ�������У�鶼�У������ɱ����������
 �꺯����Ԥ����������û�к���һ����У��


*/