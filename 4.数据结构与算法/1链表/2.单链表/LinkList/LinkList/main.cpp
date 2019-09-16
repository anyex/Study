#include "LinkList.h"

typedef struct Student {
	char name[20];
	int id;
}Student;

typedef struct s
{
	LinkListNode next;//�ṹ��s�ĵ�ַҲ����next����ʼ��ַ������(LinkListNode*)sҲ�������˽ṹ��s������ά��next���൱����ά���ṹ��s
	Student t;
}Node;
void printStudent(Node* s)
{
	Student stu = s->t;
	printf("ѧ��������%s��ѧ��%d\n", stu.name, stu.id);
}
int main()
{
	#if 0
Node v1;
	Node v2;
	Node v3;
	Node v4;
	v1.t = { "��",1};
	v2.t = { "Ǯ",2};
	v3.t = { "��",3};
	v4.t = { "��",4};


	LinkList* list = LinkList_Create();
	int ret = LinkList_Insert(list, (LinkListNode*)&v1, 0);
	ret = LinkList_Insert(list,(LinkListNode*)&v2, 1);
	ret = LinkList_Insert(list, (LinkListNode*)&v3, 2);
	printStudent((Node*)LinkList_Get(list, 1));
	printf("v1=%p,get1=%p\n", &v1, LinkList_Get(list, 0));
	printf("v2=%p,get2=%p\n", &v2, LinkList_Get(list, 1));
	printf("v3=%p,get3=%p\n", &v3, LinkList_Get(list, 2));
#endif
	
	
	return 0;
}