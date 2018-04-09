#include "LGraph.h"
#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"
typedef struct Student {
	int i;
	char name[20];
}Student;

void printStu(Student* s)
{
	printf("Ñ§ÉúĞÕÃû£º%s£¬Ñ§ºÅ%d\n", s->name, s->i);
}


int main()
{
	
	Student s1 = { 1,"ÕÔ" };
	Student s2 = { 2,"ÕÔ" };
	Student s3 = { 3,"ÕÔ" };
	Student s4 = { 4,"ÕÔ" };

	LinkList* list = LinkList_Create();
	int ret = LinkList_Insert(list, &s1, 0);
	ret = LinkList_Insert(list, &s2, 1);
	ret = LinkList_Insert(list, &s3, 2);
	ret = LinkList_Insert(list, &s4, 3);

	printStu((Student*)LinkList_Get(list, 0));
	printStu((Student*)LinkList_Get(list, 1));
	printStu((Student*)LinkList_Get(list, 2));
	printStu((Student*)LinkList_Get(list, 3));
	
	return 0;

}
/*

Student s1 = { 1,"ÕÔ" };
Student s2 = { 2,"ÕÔ" };
Student s3 = { 3,"ÕÔ" };
Student s4 = { 4,"ÕÔ" };

LinkList* list = LinkList_Create();
int ret = LinkList_Insert(list, &s1, 0);
ret = LinkList_Insert(list, &s2, 1);
ret = LinkList_Insert(list, &s3, 2);
ret = LinkList_Insert(list, &s4, 3);

printStu((Student*)LinkList_Get(list, 0));
printStu((Student*)LinkList_Get(list, 1));
printStu((Student*)LinkList_Get(list, 2));
printStu((Student*)LinkList_Get(list, 3));

*/