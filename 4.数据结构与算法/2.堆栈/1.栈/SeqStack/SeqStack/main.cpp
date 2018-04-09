#include "SeqStack.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct _tag_Studetn {
	char name[20];
	int id;
}Student;

void printStudent(Student* s)
{
	printf("ĞÕÃû£º%s,±àºÅ£º%d\n", s->name, s->id);

}
int main()
{
	Student s1 = { "ÕÔ",1};
	Student s2 = { "Ç®",2 };
	Student s3 = { "Ëï",3 };
	Student s4 = { "Àî",4 };



	SeqStack* stack = SeqStack_Create(5);
	int ret = SeqStack_Push(stack, &s1);
	ret = SeqStack_Push(stack, &s2);
	ret = SeqStack_Push(stack, &s3);
	ret = SeqStack_Push(stack, &s4);

	while (SeqStack_Size(stack)>0)
	{
		Student *student = (Student*)SeqStack_Pop(stack);
		printStudent(student);
	}
	
	


	return 0;

}