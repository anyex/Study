#include "LGraph.h"
#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"
typedef struct Student {
	int i;
	char name[20];
}Student;


void printStudent(void* St, int i)
{
	Student *S = (Student*)St;

	printf("(%d %s)\t", S[i].i, S[i].name);
}

int main()
{
	Student a[5] = { { 0,"��" },{ 1,"Ǯ" },{ 2,"��" },{ 3,"��" },{ 4,"��" } };
	LGraph* g = LGraph_Create(a, 5);
	
	
	LGraph_AddEdge(g, 0, 1, 1);
	LGraph_AddEdge(g, 0, 2, 1);
	LGraph_AddEdge(g, 2, 3, 1);
	LGraph_AddEdge(g, 3, 4, 1);
	LGraph_AddEdge(g, 1, 3, 1);

	LGraph_Display(g, printStudent);
	int EdgeNum = LGraph_EdgeCount(g);//����
	int NodeNum = LGraph_VertexCount(g);//�����
	int TD = LGraph_TD(g, 2);//��
	printf("������%d\t�������%d\t���2�Ķȣ�%d\n",EdgeNum,NodeNum,TD);
	//LGraph_RemoveEdge(g, 1, 2);//�Ƴ�1->2
	LGraph_Display(g, printStudent);
	printf("��ȱ���:\n");
	printf("\n");
	
	LGraph_DFS(g, 0, printStudent);
	LGraph_Display(g, printStudent);
	printf("��ȱ���:\n");
	LGraph_BFS(g, 0, printStudent);
	return 0;

}
