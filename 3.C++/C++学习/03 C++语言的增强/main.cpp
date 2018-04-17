#include <iostream>

using namespace std;

struct teacher {
	int id;
	char name[64];
};

//1.对全局变量的检测能力加强,一个变量只能出现一次，在.c文件中可以多次出现，但被归并到同一个地址

int g_val;
//int g_val = 10;//这两个同时出现会报错,重定义

//2.实用性的增强，对于变量的定义位置，可以随意，没有要求
int test1()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{

	}

	for (int i = 0; i < 10; i++)//在.c文件中将不能编译通过，使用变量必须先定义
	{

	}

	return 0;
}

//3.struct的加强,可以直接使用，和class的区别已经不大
void test2()
{
	teacher t1;
	
}
//4.增加bool类型,bool类型只包含两种值，
//        true代表逻辑真，false代表逻辑假


void test3()
{
	bool flag = true;//代表逻辑真
	flag = false;//逻辑假

	cout << "bool:sizeof() " << sizeof(flag) << endl;//bool占一个字节

	flag = true;//为真
	cout << "flag = " << flag << endl;//当bool类型为true，数值为1

	flag = false;//为假
	cout << "flag = " << flag << endl;//当bool类型为false，数值为0

	flag = 100;
	cout << "flag = "<< flag << endl;//不管给bool赋值什么样的非0的数值，它的值都是1


	cout << "flag = " << flag << endl;

	if (flag == true)
	{
		//默认判断flag是否为true
	}

}


//5.对 ?: 三目运算符的加强
void test4()
{
	int a = 10;
	int b = 20;

	(a < b ? a : b) = 30;//返回是a变量的别名

	cout << "a = " << a << endl;//输出30

	(a < b ? 10 : b);//三目运算符作为左值，那么返回的结果不饿能有常量
}

//6.const 的加强
#define A (3)
#define B (4)
void test6()
{
	const int a = 10;//c++的const不能通过指针的间接赋值改变a的值

	/*
	  const int,int const是等价的
	*/
	int *p = (int*)&a;//为a临时分配一个地址空间，在内存中分配一个地址，将a拷贝过去

	*p = 20;//C语言中可以通过指针的间接赋值改变const变量
	        //*p是改变的临时的变量，而不是常量a符号
			//这里也只修改了p指向的地址，a本身的并没有被修改

	printf("a = %d\n",a);

	const int b = 4;
	const int c = 3;

	int array[a + b] = { 0 };//C++中const中就是一个常量，永远不会改变，将const变量真正变为了常量
	int array_2[A + B] = { 0 };//define和const变量在编译的阶段不一样，define是预编译器，const是编译器


	/*
	  对于用const定义的基本的数据类型的常量，编译器会把它放到符号表而不分配存储空间
	  对于用const自定义的数据对象(如结构体，类等)，编译器会分配存储空间
	  用extern或取符号常量地址等操作都会强迫编译器为这些常量分配存储空间

	  当取地址时，编译器也只是重新在内存中创建它的一个拷贝，通过其他地址访问的是这个拷贝而非
	  原始的符号常量

	  对于构造类型的const常量，是编译时不允许改变的变量


	*/
}

//7. 枚举常量
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
	//s->id = 10;s指向的区域是一个常量不能被修改
	
}

void change_stu3(student *const s)
{
	s->id = 10;
	student s2;
	//s = &s2;s是一个常量指针不能被修改
}
void change_stu4(const struct student *const s)
{
	//s->id = 10;//s指向的区域是一个常量不能被修改
	//struct student s2;
	//s = &s2;  //s是一个常量指针
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

