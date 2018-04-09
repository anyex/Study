#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
void func(int a = 666)
{
	cout << "a = " << a << endl;
}
int main()
{
	func();
	func(10);
	return 0;
}