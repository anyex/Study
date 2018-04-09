#include "StaticList.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct Student {
	int id;
	char name[20];
};

void printStudent(Student s)
{
	printf("学号：%d\t姓名：%s\n", s.id, s.name);
}
int main()
{

	Student s1 = { 1,"赵" };
	Student s2 = { 2,"赵" };
	Student s3 = { 3,"赵" };
	Student s4 = { 4,"赵" };
	Student s5 = { 5,"赵" };

	StaticList* list = StaticList_Create(5);
	int  ret = StaticList_Insert(list, &s1, 0);
		 ret = StaticList_Insert(list, &s2, 1);
		 ret = StaticList_Insert(list, &s3, 2);
		 ret = StaticList_Insert(list, &s4, 3);

		 Student get1 = *(Student*)StaticList_Get(list, 1);
		 Student get2 = *(Student*)StaticList_Get(list, 2);
		 Student get3 = *(Student*)StaticList_Get(list, 3);
		 Student get4 = *(Student*)StaticList_Get(list, 0);

		 printf("链表长度：%d \n", StaticList_Length(list));
		 for (int i = 0; i < StaticList_Length(list); i++)
		 {
			 Student get1 = *(Student*)StaticList_Get(list, i);
			 printStudent(get1);
		 }
	 
		
	     StaticList_Delete(list, 0);
		 printf("链表长度：%d \n", StaticList_Length(list));
	 for (int i = 0; i < StaticList_Length(list); i++)
	 {
		 Student get1 = *(Student*)StaticList_Get(list, i);
		 printStudent(get1);
	 }
		 
	
	return 0;
}