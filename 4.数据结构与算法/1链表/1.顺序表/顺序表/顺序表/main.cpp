#include "SeqList.h"
#include "stdio.h"
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
		printf("删除一个元素\n");
		for (int i = 0; i < SeqList_Length(A); i++)
		{
			printStudent((Student*)SeqList_Get(A, i));
		}

	return 0;
}