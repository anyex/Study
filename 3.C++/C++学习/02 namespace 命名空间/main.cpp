#include <iostream>

using std::cout;//using 关键字,引入命名空间的一个变量
using std::endl;

using namespace std;//引入std整个命名空间
int aa;//默认的全局作用域的命名空间

//定义一个命名空间

namespace A //定义了命名空间A
{
	int a = 10;
	int b = 20;
}

namespace B //命名空间内部也可以定义命名空间
{
	int a = 20;
	namespace C//嵌套定义命名空间C
	{
		struct teacher
		{
			int id;
			char name[64];
		};
	}

	namespace D
	{
		struct teacher
		{

		};
	}
}

//使用自定义的命名空间
void test()
{
	using A::a;//所有的变量a都默认时命名空间A中的a
	using namespace B;//引入整个命名空间B
	
	a = 50;

	cout << "A::a = " <<A::a << endl;
	cout << "B::a =" << B::a << endl;
	cout << "a = " << a << endl;

	//方式1
	using namespace B::C;//把C中的所有定义的遍历都引入
	teacher t1;

	//方式2
	using B::C::teacher;
	teacher t2;

	//方式3
	B::C::teacher t3;
	
	//方式4
	using namespace B;
	C::teacher t;
}

int main()
{
	test();
	return 0;
}

/*
使用命名空间的变量时，不能出现不能识别的情况，即如果两个命名空间都有同名，同类型的变量不能同时引用
如  using namespace A;
    using namespace B;
	a = 20;//将不能识别出a是输入A还是属于B，会报错

	
	命名空间将全局作用域分成不同的部分
	不同命名空间中的标识符可以同名而不会发生冲突
	命名空间也可以嵌套
	全局作用域也叫默认命名空间

*/