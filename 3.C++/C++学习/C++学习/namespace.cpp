#include "iostream"

using std::cout;//引用命名空间中的变量
using std::endl;

using namespace std;//引用整个命名空间

int aa;//默认的全局作用域命名空间

//自定义命名空间

namespace namespaceA 
{
	int a = 10;
	int b = 20;
}

//命名空间可以嵌套
namespace namespaceB
{
	int a = 20;
	namespace namespaceC 
	{
		struct teacher 
		{
			int id;
			char name[64];

		};

	}

	namespace namespaceD {
		struct  teacher
		{

		};
	}
}

//使用自定义的命名空间
void test()
{
	using namespaceA::a;//后面成员应用a都默认时namespaceA中的值
	using namespace namespaceA;//引入整个namespaceA空间

	//int a = 5;会提示重定义
	cout << "A::a = " << namespaceA::a << endl;
	cout << "B::a=" << namespaceB::a << endl;
	cout << "a=" << a << endl;
	using namespace namespaceB::namespaceC;

}

int main()
{
	test();
	return 0;
}