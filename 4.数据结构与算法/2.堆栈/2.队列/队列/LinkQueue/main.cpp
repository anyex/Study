#include "LinkQueue.h"
typedef struct _tag_Student {
	char name[20];
	int id;
}Student;

void printStudent(Student* stu)
{
	printf("ѧ��������%s��ѧ��%d\n", stu->name, stu->id);
}
int main()
{
	Student v1 = { "��",1 };
	Student v2 = { "Ǯ",2 };
	Student v3 = { "��",3 };
	Student v4 = { "��",4 };

	LinkQueue* sq = LinkQueue_Create();
	int ret = LinkQueue_Append(sq, &v1);
	ret = LinkQueue_Append(sq, &v2);
	ret = LinkQueue_Append(sq, &v3);
	ret = LinkQueue_Append(sq, &v4);

	printStudent((Student*)LinkQueue_Header(sq));
	while (LinkQueue_Length(sq))
	{
		printStudent((Student*)LinkQueue_Retrieve(sq));
	}
	return 0;
}