#include "LinkList.h"
#include "stdio.h"

typedef struct Student {
	LinkListNode* head;
	int id;
	
}Student;

int main()
{
	Student s1;
	Student s2;
	Student s3;
	Student s4;
	s1.id = 1;
	s2.id = 2;
	s3.id = 3;
	s4.id = 4;
	
	static LinkListNode* list = LinkList_Create();
	LinkList_Insert(list, (LinkListNode*)&s1, 0);
	LinkList_Insert(list, (LinkListNode*)&s2, 1);
	LinkList_Insert(list, (LinkListNode*)&s3, 2);
	LinkList_Insert(list, (LinkListNode*)&s4, 3);

	Student *get1 = (Student*)LinkList_Get(list, 0);
	Student *get2 = (Student*)LinkList_Get(list, 1);
	Student *get3 = (Student*)LinkList_Get(list, 2);
	Student *get4 = (Student*)LinkList_Get(list, 3);

	printf("%d\t", get1->id);
	printf("%d\t", get2->id);
	printf("%d\t", get3->id);
	printf("%d\t", get4->id);

	printf("\n");
	return 0;
}