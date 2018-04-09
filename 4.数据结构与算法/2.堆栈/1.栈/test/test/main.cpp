#include "stdio.h"
int& f()
{
	static int a = 0;
	return a;
}
int& g()
{
	int a = 0;
	return a;
}
int main()
{
	int a = 0;
	int& b = g();
	f() = 10;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("f()=%d\n", f());
	return 0;
}

