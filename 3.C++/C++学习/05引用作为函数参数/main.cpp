#include <iostream>
using namespace std;

struct  Teacher
{
	int id;
	char name[64];
};

void printT(Teacher t)//局部临时变量，会发生值拷贝
{
	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	t.id = 10;

}

void printT2(Teacher *t)
{
	cout << "id = " << t->id << endl;
	cout << "name = " << t->name << endl;
	t->id = 1000;
}

void printT3(Teacher &t)//可以当做一个别名来理解
{
	cout << "id  = " << t.id << endl;
	cout << "name = " << t.name << endl;
	t.id = 100;
}

//交换不成功
void my_swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//成功交换
void my_swap02(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//成功交换
void my_swap03(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	Teacher t1 = { 1, "zhang3" };

	printT(t1);

	cout << t1.id << endl;

	printT2(&t1);

	cout << t1.id << endl;


	printT3(t1);
	cout << t1.id << endl;


	int a = 10;
	int b = 20;

	my_swap01(a, b);
	cout << "a = " << a << ", b = " << b << endl;

	my_swap02(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;

	my_swap03(a, b);
	cout << "a = " << a << ", b = " << b << endl;


	return 0;
}
