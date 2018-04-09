#include "LinkQueue.h"
typedef struct _tag_Student {
	char name[20];
	int id;
}Student;

void printStudent(Student* stu)
{
	printf("学生姓名：%s，学号%d\n", stu->name, stu->id);
}
int main()
{
	Student v1 = { "赵",1 };
	Student v2 = { "钱",2 };
	Student v3 = { "孙",3 };
	Student v4 = { "李",4 };

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