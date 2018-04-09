#include "LinkStack.h"
#include "stdio.h"

typedef struct _tag_Studetn {
	char name[20];
	int id;
}FStudent;

typedef struct TStudent {
	LinkStackNode* next;
	FStudent* student;
}TStudent;

void printStudent(TStudent* ts)
{
	FStudent *s = ts->student;
	printf("ÐÕÃû£º%s,±àºÅ£º%d\n", s->name, s->id);
}
int main()
{
	FStudent fs1 = { "ÕÔ",1 };
	FStudent fs2 = { "Ç®",2 };
	FStudent fs3 = { "Ëï",3 };
	FStudent fs4 = { "Àî",4 };
	TStudent ts1 ,ts2,ts3,ts4;
	ts1.student = &fs1;
	ts2.student = &fs2; 
	ts3.student = &fs3; 
	ts4.student = &fs4;

	LinkStack* stack = LinkStack_Create();
	int ret = LinkStack_Push(stack, &ts1);
	ret = LinkStack_Push(stack, &ts2);
	ret = LinkStack_Push(stack, &ts3);
	ret = LinkStack_Push(stack, &ts4);
	
	while (LinkStack_Size(stack)>0)
	{
		TStudent *student = (TStudent*)LinkStack_Pop(stack);
		printStudent(student);
	}

	printf("%d\n", sizeof(stack));
	LinkStack_Size(stack);
	return 0;
}