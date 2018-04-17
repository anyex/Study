#include <iostream>
using namespace std;

class Test {
public:
	Test()
	{
		m_a = 0;
		m_b = 0;
		cout << "0,0����" << endl;
	}

	Test(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "a = " << m_a << ",b = " << m_b <<"����"<< endl;
	}

	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}

	void printT()
	{
		cout << "a = " << m_a << ", b = " << m_b << endl;
	}

	~Test()
	{
		cout << "a = " << m_a << ", b = " << m_b << "���� " << endl;
	}
private:
	int m_a;
	int m_b;
};

class A
{
public:
	A()
	{
		a = 0;
	}
	~A()
	{
		cout << "��������������" << endl;
	}
private:
	int a;
};
//C������
void test1()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	cout << *p << endl;
	if (p != NULL) {
		free(p);
		//delete p; //delete �����ͷ�malloc�Ŀ��ٵ��ڴ�
	}

	int *array_p = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++) {
		array_p[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << array_p[i] << endl;
	}

	if (array_p != NULL) {
		free(array_p);
	}


	cout << " --------  " << endl;

	Test *tp = (Test*)malloc(sizeof(Test)); //������ö���Ĺ��캯��
											//p(10, 20);
	tp->setA(10);
	tp->setB(20); //malloc�����Ķ���ָ�룬ֻ�ܹ�ͨ����Ա���������г�ʼ��
	tp->printT();

	if (tp != NULL) {
		free(tp); //������ö��������
	}
}

//C++�е�new delete
void test2()
{
	//new �ܹ��������malloc������
	int *p = new int; //�ڶ��϶�̬����4���ֽ�
	*p = 10;
	cout << *p << endl;

	if (p != NULL) {
		//delete p; //delete һ������
		free(p); //��new���ٵ��ڴ棬 freeҲ�ܹ��ͷš�
	}

	cout << "-----" << endl;

	int *array_p = new int[10];
	for (int i = 0; i < 10; i++) {
		array_p[i] = i + 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << array_p[i] << endl;
	}

	if (array_p != NULL) {
		delete[]   array_p; //delete һ������
	}


	cout << "-------" << endl;
	//Test *tp = new Test(10, 20);//�������в����Ĺ��캯�� 
	//new �ڴ���һ�������ʱ�򣬻���ö���Ĺ��캯��
	Test *tp = new Test;//�������޲ι��캯��
	tp->printT();
	if (tp != NULL) {
		delete tp; //delete���ͷ�һ������ָ���ʱ�򣬻���ö�����������
	}
}

int main(void)
{
	//test1();
	//test2();
	A *a = new A[10];
	delete[] a;
	return 0;
}

/*
new Ҳ������������ڴ棬����һ�������������һ�����������Ч�������malloc�õ������
    newһ���������ù��캯����newҲ�Ƿ���һ��ָ��������޷���������ռ�ʱҲ����һ����ָ��NULL

delete   �ͷ�new������ָ�룬Ҳ���ͷ�malloc���ڴ�ָ�룬������ö������������
   delete [] ��delete�����൱���������
      class A{.....}�� A *a  = new A[10]
			delete a ֻ����a[0]����������
			delete [] a�������a[0]��a[9]����������
*/