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
	Student s1 = { "��",1 };
	Student s2 = { "Ǯ",2 };
	Student s3 = { "��",3 };
	Student s4 = { "��",4 };
	Student s5 = { "��",5 };
	Student s6 = { "��",6 };
	Student s7 = { "֣",7 };
	Student s8 = { "��",8 };

	BTree_Insert(tree, &s1, 0,0,BT_LEFT);
	BTree_Insert(tree, &s2, 0x00,1, BT_LEFT);
	BTree_Insert(tree, &s3, 0x01,1, BT_RIGHT);
	BTree_Insert(tree, &s4, 0x00, 2, BT_LEFT);
	BTree_Insert(tree, &s5, 0x02, 2, BT_RIGHT);
	BTree_Display(tree, printStudent, 16, ' ');
	printf("\nǰ�����\n");
	BTree_Front(tree, printStudent);
	printf("\n�������\n");
	BTree_Middle(tree, printStudent);
	printf("\n�������\n");
	BTree_Behand(tree, printStudent);
	printf("\n�������\n");
	BTree_Level(tree, printStudent);
	return 0;
}