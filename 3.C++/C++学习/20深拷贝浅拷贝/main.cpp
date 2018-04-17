#include <iostream>
using namespace std;

class Teacher {
public:
	//有参数的构造函数

	Teacher(int id, char* name)
	{
		cout << "调用了Teacher的构造函数" << endl;
		m_id = id;

		//给姓名赋值
		int len = strlen(name);
		m_name = (char*)malloc(len + 1);
		strcpy(m_name, name);
	}
	//拷贝构造函数
	//通过显式拷贝构造函数提供了深拷贝的动作
	Teacher(const Teacher &another)
	{
		m_id = another.m_id;

		//对引用指针的外部内容也进行了就是深拷贝
		int len = strlen(another.m_name);
		m_name = (char*)malloc(len + 1);
		strcpy(m_name, another.m_name);

		/*
		  浅拷贝，两个对象的name指向同一个地址，即二者共用m_name的内容
		  m_id = another.m_id;
		  m_name = another.m_name;
		*/
	}

	//在构造函数中， 已经开辟了内存 所以为了防止泄露
	//在析构函数中，在对象销毁之前，把m_name的内存释放掉
	~Teacher() {
		if (m_name != NULL) {
			free(m_name);
			m_name = NULL;
			cout << "释放掉了m_name" << endl;
		}
	}
private:
	int m_id;
	char*m_name;
};

int main(void)
{
	Teacher t1(1, "zhang3");

	//如果不提供一个显示的拷贝构造函数， 通过系统自带的默认拷贝构造函数
	Teacher t2(t1); //会调用t2的拷贝构造函数，将t1的值拷贝给t2

	return 0;
}

/*
深拷贝：如果复制这个对象的时候为新对象制作了外部对象的独立复制，就是深拷贝

浅拷贝：如果复制的对象引用了一个外部内容(如分配在堆上的数据)，那么复制这个对象的时候，
	   让新旧对象指向同一个外部内容（指针虽然复制，但指向的空间内容没有复制，而是两个对象共用）
*/