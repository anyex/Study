#include <iostream>

using namespace std;

//const ����һ�������β��ϣ�����֤�����õı������ܱ��޸�
void printX(const int &re)
{
	cout << "re " << re << endl;

}


int main()
{
	const int a = 10;//a���뱻��ʼ��

	const int &b = a;

	//�����һ��const������������const������������
	int x = 3.14;

	const int &re1 = x;

	cout << "re1 " << re1 << endl;
	x = 20;
	cout << "re1 " << re1 << ",x: " << endl;

	const int &re2 = 10;//�ǳ������ã���������ֵ����ֵ���ǿ��Ա���ֵ�����ڴ�ռ�
	                    //�����������ã�������const
	cout << "re2 = " << re2 << endl;
	cout << "sizeof(re2)" << sizeof(re2) << endl;

	return 0;




}

/*
  ������Ҫ������define��const����ķ��ų��������泣��
  ���泣��ֻ�����ã������޸ģ�����һ�㱣���ڷ��ű��磺x=-100,char c = 'a'��Ҫ�Ǹ����ַ������֣�			

*/