#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(int id, char *name)
	{
		this->name = name;
	}

	void printS()
	{
		cout << "id = " << id << "name = " << name << endl;
	}

private:
	string name;
	int id;
};

//C++继承

class Student3:public Student
{
public:
	Student3(int id, char*name, int score):Student(id,name)//子类继承过来的成员变量通过父类的构造器来构造
	{
		this->score = score;
		
	}
	void printS()
	{
		Student::printS();//调用父类中的方法
		cout << "score = " << this->score<<endl;
	}

private:
	int score;//添加的一个成员变量
};



/*
C++ 继承
   继承后，就能使用父类的成员变量和函数

*/