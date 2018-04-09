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

	int c = my_func(++a, b);//在编译时会将my_func(++a,b)展开为(a<b?a:b),从而消除了写成函数的开销
							//内联函数在调试模式中，不会被内联，会像普通函数一样生成含有调试信息的可执行代码
	                        
	printAB(++a, b);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	system("pause");

	return 0;
	
}

//printAB不能被内联
void printAB(int a, int b)
{
	cout << "a = " << a << ", b = " << b << endl;
}