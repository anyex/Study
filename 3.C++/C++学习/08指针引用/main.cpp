#include <iostream>
#include <cstring>
using namespace std;

struct  Teacher
{
	int id;
	char name[64];
};

int getTeacher(Teacher **pp)
{
	Teacher* p = NULL;
	p = (Teacher*)malloc(sizeof(Teacher));
	if (p == NULL)
	{
		cout << "error" << endl;
		return -1;
	}

	memset(p, 0, sizeof(Teacher));

	p->id = 30;
	strcpy_s(p->name, "����");

	*pp = p;

	return 0;
	
}

int getTeacher02(Teacher* &tr)//tr����main�����е�tp,�������õ���һ��ָ��ʹ��
{
	tr = (Teacher*)malloc(sizeof(Teacher));

	if (tr == NULL)
	{
		cout << "error" << endl;
		return -1;
	}

	tr->id = 40;
	strcpy_s(tr->name, "����");

	return 0;
}

void freeTeacher02(Teacher *&tr)
{
	if (tr != NULL)
	{
		free(tr);
		tr = NULL;
	}
}

void freeTeacher(Teacher **pp)
{
	if (pp == NULL)
	{
		return;
	}

	Teacher *p = *pp;

	if (p != NULL)
	{
		free(p);
		*pp = NULL;
	}

}

int main()
{
	Teacher *tp = NULL;

	getTeacher02(tp);

	cout << tp->id << ", " << tp->name << endl;

	freeTeacher02(tp);

	return 0;
}