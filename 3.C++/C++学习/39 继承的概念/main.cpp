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

//C++�̳�

class Student3:public Student
{
public:
	Student3(int id, char*name, int score):Student(id,name)//����̳й����ĳ�Ա����ͨ������Ĺ�����������
	{
		this->score = score;
		
	}
	void printS()
	{
		Student::printS();//���ø����еķ���
		cout << "score = " << this->score<<endl;
	}

private:
	int score;//��ӵ�һ����Ա����
};



/*
C++ �̳�
   �̳к󣬾���ʹ�ø���ĳ�Ա�����ͺ���

*/