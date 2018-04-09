#include "LinkList.h"
#include "Tree.h"
typedef struct Student {
	char name[20];
	int id;
}Student;



void printStudent(GTreeData* s)
{
	Student* st = (Student*)s;
	printf("%s,%d,%p\n", st->name, st->id,s);
}
int main()
{
	Student s1 = { "赵",1 };
	Student s2 = { "钱",2 };
	Student s3 = { "孙",3 };
	Student s4 = { "李",4 };
	Student s5 = { "周",5 };
	Student s6 = { "吴",6 };
	Student s7 = { "郑",7 };
	Student s8 = { "王",8 };
	Tree* tree = Tree_Create();

	Tree_Insert(tree, &s1, 0);
	Tree_Insert(tree, &s2, 0);
	Tree_Insert(tree, &s3, 0);
	Tree_Insert(tree, &s4, 1);
	Tree_Insert(tree, &s5, 1);
	Tree_Insert(tree, &s6, 2);
	Tree_Insert(tree, &s7, 1);
	Tree_Insert(tree, &s8, 2);
	printf("最大深度：%d\n", Tree_Degree(tree));
	printf("删除前：\n");
	GTree_Display(tree,printStudent,4,'+');
	printf("树的高度：%d", Tree_Height(tree));
	Tree_Delete(tree, 1);
	printf("删除后：\n");
	GTree_Display(tree, printStudent, 4, '-');

	printf("最大深度：%d", Tree_Degree(tree));
	return 0;
}
/*

Student s1 = { "赵",1 };
Student s2 = { "钱",2 };
Student s3 = { "孙",3 };
Student s4 = { "李",4 };


LinkList* list = LinkList_Create();
int re
/*


t = LinkList_Insert(list, &s1, 0);
ret = LinkList_Insert(list, &s1, 1);
ret = LinkList_Insert(list, &s4, 2);

printStudent((Student*)LinkList_Get(list, 1));
printf("v1=%p,get1=%p\n", &s1, LinkList_Get(list, 0));
printf("v2=%p,get2=%p\n", &s2, LinkList_Get(list, 1));
printf("v3=%p,get3=%p\n", &s3, LinkList_Get(list, 2));
*/


