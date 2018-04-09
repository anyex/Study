#include "iostream"

using namespace std;
struct student {
	int id;
	char name[64];
};

void change_stu(student* s)
{
	s->id = 10;
}
void printStudent(student s)
{
	cout << "s.id=" << s.id << "\t" << "s.name = " << s.name << endl;

}
void change_stu2(const student*s)
{
	//s->id = 10; //此时s所指向的区域是一个常量 不能够被修改
	int* p = (int*)&(s->id);
	*p = 24;
	printStudent(*s);
}
void change_stu3(struct student *const s)
{
	s->id = 10;
	//struct student s2;
	//s = &s2;  //s是一个常量指针

	//结构体的值都能被间接改变
	int* p = (int*)&(s->id);
	*p = 24;
	printStudent(*s);
}

void change_stu4(const struct student *const s)
{
	//s->id = 10;
	//struct student s2;
	//s = &s2;  //s是一个常量指针
	
}

int main()
{
	
	student s1 = { 1,"23" };
	struct student *const s = &s1;
	change_stu3(s);//结构体的值都能被指针间接修改，但被const限定的类型都不能直接修改
	
	return 0;
}