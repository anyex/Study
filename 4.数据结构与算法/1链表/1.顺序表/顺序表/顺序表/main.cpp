#include "SeqList.h"
#include "stdio.h"
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

	SeqList *A = SeqList_Create(6);

	int ret = SeqList_Insert(A, &v1, 0);
	    ret = SeqList_Insert(A, &v2, 1);
		ret = SeqList_Insert(A, &v3, 2);
		ret =SeqList_Insert(A, &v4, 3);
	
		for (int i = 0; i < SeqList_Length(A); i++)
		{
			printStudent((Student*)SeqList_Get(A, i));
	   }
	
		SeqList_Delete(A, 1);
		printf("ɾ��һ��Ԫ��\n");
		for (int i = 0; i < SeqList_Length(A); i++)
		{
			printStudent((Student*)SeqList_Get(A, i));
		}

	return 0;
}