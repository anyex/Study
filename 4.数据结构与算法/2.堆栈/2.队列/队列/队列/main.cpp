#include "SeqQueue.h"

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