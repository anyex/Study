#include <iostream>

using namespace std;

struct teacher {
	int id;
	char name[64];
};

//1.��ȫ�ֱ����ļ��������ǿ,һ������ֻ�ܳ���һ�Σ���.c�ļ��п��Զ�γ��֣������鲢��ͬһ����ַ

int g_val;
//int g_val = 10;//������ͬʱ���ֻᱨ��,�ض���

//2.ʵ���Ե���ǿ�����ڱ����Ķ���λ�ã��������⣬û��Ҫ��
int test1()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{

	}

	for (int i = 0; i < 10; i++)//��.c�ļ��н����ܱ���ͨ����ʹ�ñ��������ȶ���
	{

	}

	return 0;
}

//3.struct�ļ�ǿ,����ֱ��ʹ�ã���class�������Ѿ�����
void test2()
{
	teacher t1;
	
}
//4.����bool����,bool����ֻ��������ֵ��
//        true�����߼��棬false�����߼���


void test3()
{
	bool flag = true;//�����߼���
	flag = false;//�߼���

	cout << "bool:sizeof() " << sizeof(flag) << endl;//boolռһ���ֽ�

	flag = true;//Ϊ��
	cout << "flag = " << flag << endl;//��bool����Ϊtrue����ֵΪ1

	flag = false;//Ϊ��
	cout << "flag = " << flag << endl;//��bool����Ϊfalse����ֵΪ0

	flag = 100;
	cout << "flag = "<< flag << endl;//���ܸ�bool��ֵʲô���ķ�0����ֵ������ֵ����1


	cout << "flag = " << flag << endl;

	if (flag == true)
	{
		//Ĭ���ж�flag�Ƿ�Ϊtrue
	}

}


//5.�� ?: ��Ŀ������ļ�ǿ
void test4()
{
	int a = 10;
	int b = 20;

	(a < b ? a : b) = 30;//������a�����ı���

	cout << "a = " << a << endl;//���30

	(a < b ? 10 : b);//��Ŀ�������Ϊ��ֵ����ô���صĽ���������г���
}

//6.const �ļ�ǿ
#define A (3)
#define B (4)
void test6()
{
	const int a = 10;//c++��const����ͨ��ָ��ļ�Ӹ�ֵ�ı�a��ֵ

	/*
	  const int,int const�ǵȼ۵�
	*/
	int *p = (int*)&a;//Ϊa��ʱ����һ����ַ�ռ䣬���ڴ��з���һ����ַ����a������ȥ

	*p = 20;//C�����п���ͨ��ָ��ļ�Ӹ�ֵ�ı�const����
	        //*p�Ǹı����ʱ�ı����������ǳ���a����
			//����Ҳֻ�޸���pָ��ĵ�ַ��a����Ĳ�û�б��޸�

	printf("a = %d\n",a);

	const int b = 4;
	const int c = 3;

	int array[a + b] = { 0 };//C++��const�о���һ����������Զ����ı䣬��const����������Ϊ�˳���
	int array_2[A + B] = { 0 };//define��const�����ڱ���Ľ׶β�һ����define��Ԥ��������const�Ǳ�����


	/*
	  ������const����Ļ������������͵ĳ�����������������ŵ����ű��������洢�ռ�
	  ������const�Զ�������ݶ���(��ṹ�壬���)�������������洢�ռ�
	  ��extern��ȡ���ų�����ַ�Ȳ�������ǿ�ȱ�����Ϊ��Щ��������洢�ռ�

	  ��ȡ��ַʱ��������Ҳֻ���������ڴ��д�������һ��������ͨ��������ַ���ʵ��������������
	  ԭʼ�ķ��ų���

	  ���ڹ������͵�const�������Ǳ���ʱ������ı�ı���


	*/
}

//7. ö�ٳ���
enum  season
{
	SPR,
	SUM,
	AUT,
	WIN
};

void test7()
{
	enum season s = SPR;
	season p = SUM;

}

struct  student
{
	int id;
	char name[64];
};
void change_stu(student *s)
{
	s->id = 10;
}

void change_stu2(const student* s)
{
	//s->id = 10;sָ���������һ���������ܱ��޸�
	
}

void change_stu3(student *const s)
{
	s->id = 10;
	student s2;
	//s = &s2;s��һ������ָ�벻�ܱ��޸�
}
void change_stu4(const struct student *const s)
{
	//s->id = 10;//sָ���������һ���������ܱ��޸�
	//struct student s2;
	//s = &s2;  //s��һ������ָ��
}

int g(int a, int b, int c)
{
	return 100;
}

int main()
{
	
	g(1, 2, 3);
	return 0;
}

