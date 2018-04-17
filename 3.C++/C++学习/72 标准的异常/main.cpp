#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class MyException :public exception
{
public:
	MyException(char *str) {
		this->m_s = str;

	}
	//��дwhat���������᷵���쳣���ַ���Ϣ
	virtual const char *what()const {
		cout << "MyException ���쳣" << endl;
		return this->m_s;
	}

private:
	char* m_s;
};
class Teacher
{
public:
	Teacher(string name, int id)
	{
		this->name = name;
		if (id > 100)
		{
			string str = "id ������Χ";
			throw out_of_range(str);
		}
		this->id = id;
	}
private:
	int id;
	string name;

};


int main()
{
	try {
		Teacher t1("����", 10001);

	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	try {
		throw MyException("AAAA");
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}