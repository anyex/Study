#include "SeqQueue.h"

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

	SeqQueue* sq = SeqQueue_Create(6);
	int ret = SeqQueue_Append(sq, &v1);
	    ret = SeqQueue_Append(sq, &v2);
		ret = SeqQueue_Append(sq, &v3);
		ret = SeqQueue_Append(sq, &v4);

		printStudent((Student*)SeqQueue_Header(sq));
		while ( SeqQueue_Length(sq))
		{
			printStudent((Student*)SeqQueue_Retrieve(sq));
		}

		return 0;

}