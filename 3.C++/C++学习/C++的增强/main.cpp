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
	//s->id = 10; //��ʱs��ָ���������һ������ ���ܹ����޸�
	int* p = (int*)&(s->id);
	*p = 24;
	printStudent(*s);
}
void change_stu3(struct student *const s)
{
	s->id = 10;
	//struct student s2;
	//s = &s2;  //s��һ������ָ��

	//�ṹ���ֵ���ܱ���Ӹı�
	int* p = (int*)&(s->id);
	*p = 24;
	printStudent(*s);
}

void change_stu4(const struct student *const s)
{
	//s->id = 10;
	//struct student s2;
	//s = &s2;  //s��һ������ָ��
	
}

int main()
{
	
	student s1 = { 1,"23" };
	struct student *const s = &s1;
	change_stu3(s);//�ṹ���ֵ���ܱ�ָ�����޸ģ�����const�޶������Ͷ�����ֱ���޸�
	
	return 0;
}