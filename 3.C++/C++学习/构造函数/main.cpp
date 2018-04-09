#include "iostream"
#include "string.h"
using namespace std;

class test
{
public:
	//无参构造函数
	test()
	{
		m_x = 0;
		m_y = 0;
		name = (char*)malloc(100);
		
		cout << "m_x = " << m_x << "\t" << "m_y = " << m_y << endl;
	}
	test(int x)
	{
		m_x = x;
		m_y = 0;
		cout << "m_x = " << m_x << "\t" << "m_y = " << m_y << endl;
	}
	test(int x, int y)
	{
		m_x = x;
		m_y = y;
		cout << "m_x = " << m_x << "\t" << "m_y = " << m_y << endl;
	}
	~test() {
		if (name != NULL)
			free(name);
		cout << "析构函数被运行" << endl;
	};
private:
	int m_x;
	int m_y;
	char* name;
};


void tes()
{
	test s;

}
int main()
{


	test test1(5);//调用一个参数的构造函数
	test test2;//调用无参构造函数
	test test3(5, 10);//调用两个参数的构造函数
	tes();


	return 0;

}