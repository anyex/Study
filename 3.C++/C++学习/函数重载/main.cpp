#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

typedef int(MY_FUNC)(int, int);
typedef int(*MY_FUNC_P)(int, int);




void func(int a)
{
	cout << "fun" << endl;
}

int  func(int a, int b)
{
	cout << "a,b" << endl;
	return 0;
}

int func(int a, int b, int v)
{
	cout << "a,b,v"<<endl;
	return 0;
}
int main(void)
{
	MY_FUNC *fp = NULL;
	fp = func;
	MY_FUNC_P fp1 = func;
	fp(20, 10);
	fp1(20, 40);

	int(*fp3)(int, int,int);

	fp3 = func;
	fp3(2, 3, 5);
	return 0;
}