#include <iostream>

using namespace std;
class Test {
public:
	Test(int k)
	{
		this->m_k = k;
		this->m_q = 0;
	}

	Test(int k, int q)
	{
		this->m_k = k;
		this->m_q = q;
	}

	/*
	int getK(Test *this)
	{

	}//������ڲ����ܶ���thisָ��

	Test* this;
	*/
	
	int getK() const//�൱��int getK(const Test *const this),this��һ����ָ��
	{
		//this->m_k = 0;�ڳ�Ա���������const���εĲ��Ǻ������������ص�thisָ�룬����thisָ��������thisָ���ֵ���ܱ��ı�

		return this->m_k;
	}

private:
	int m_k;
	int m_q;
};

int main(void)
{
	Test t1(10);  //  Test t1(&t1, 10)
	Test t2(20);

	t1.getK();

	t2.getK(); // t2.getK(&t2)

	return 0;
}