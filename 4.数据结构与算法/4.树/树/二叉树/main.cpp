#include "BTree.h"

typedef struct Student {
	char name[20];
	int id;
}Student;



void printStudent(BTreeData* s)
{
	Student* st = (Student*)s;
	printf("%s,%d\t", st->name, st->id);
}
int main()
{
	BTree* tree = BTree_Create();
	Student s1 = { "赵",1 };
	Student s2 = { "钱",2 };
	Student s3 = { "孙",3 };
	Student s4 = { "李",4 };
	Student s5 = { "周",5 };
	Student s6 = { "吴",6 };
	Student s7 = { "郑",7 };
	Student s8 = { "王",8 };

	BTree_Insert(tree, &s1, 0,0,BT_LEFT);
	BTree_Insert(tree, &s2, 0x00,1, BT_LEFT);
	BTree_Insert(tree, &s3, 0x01,1, BT_RIGHT);
	BTree_Insert(tree, &s4, 0x00, 2, BT_LEFT);
	BTree_Insert(tree, &s5, 0x02, 2, BT_RIGHT);
	BTree_Display(tree, printStudent, 16, ' ');
	printf("\n前序遍历\n");
	BTree_Front(tree, printStudent);
	printf("\n中序遍历\n");
	BTree_Middle(tree, printStudent);
	printf("\n后序遍历\n");
	BTree_Behand(tree, printStudent);
	printf("\n按层遍历\n");
	BTree_Level(tree, printStudent);
	return 0;
}