#include <iostream>

using namespace std;

//C++�������һ���β�Ĭ������Ϊһ��ֵ�����ⲿ���ú�����ʱ����������ݲ�������ôx����100
//�������ʵ�Σ���ôx��ֵ����ʵ�ε�ֵ
int func1(int x =100, int = 0)
{
	cout << "func1:x = " << x << endl;

	return 0;
}

//��һ�����������
//Ĭ�ϲ����������Ǵ����������ã�ֻҪ��һ�������Ǵ���Ĭ�ϲ����ģ���ô���ұߵ����в�����������Ĭ��ֵ
int volume(int len, int width, int high = 30)
{
	return len*width*high;
}

int v1(int len = 1, int wid =2, int h=3);//int v1(int len = 1, int wid , int h);������
int main()
{
	int x = 10;
	int v = 0;

	func1();
	func1(x);
	int len = 10;
	int w = 20;
	int h = 30;

	v = volume(len, w, h);

	cout << "v = " << v << endl;

	return 0;
}