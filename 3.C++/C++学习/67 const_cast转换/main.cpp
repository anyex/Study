#include <iostream>

using namespace std;

void func(const char* p)
{
	char *pp = const_cast<char *>(p);//将p的const属性去掉
	pp[0] = 'A';
}

int main()
{
	const char *p = "12343545";
	char buf[] = "123432524314";

	func(buf);//字符数组对常量字符串进行了拷贝，所以能修改
	//func(p);//p指向的字符串存储在常量去，所以不可以修改

	//cout << "p:" << p << endl;
	cout << "buf:" << buf << endl;

	const int a = 10;
	const int *a_p = &a;

	int *a_p1 = const_cast<int *>(a_p);//把a_p的属性去掉

	*a_p1 = 100;

	int *p2 = const_cast<int *>(&a);
	cout << "*a_p = " << *a_p << endl;
	cout << "a= " << a << endl;
	cout << "*p2 " << *p2 << endl;



	//const_cast 的作用就是 将一个有只读属性的指针，把只读属性去掉，但是前提是当前的内存空间是可以修改。
	return 0;

}


