#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct Student {
	int i;
	char name[20];
}Student;

void printStudent(void* St,int i)
{
	Student *S = (Student*)St;
	
	printf("(%d %s)", S[i].i, S[i].name);
}

int main()
{
	Student a[5] = { {0,"’‘"},{ 1,"«Æ" },{ 2,"ÀÔ" },{ 3,"¿Ó" },{ 4,"÷‹" } };
	Graph* g = Graph_Create(5, a);
	Graph_AddEdge(g, 0, 2, 1);
	Graph_AddEdge(g, 1, 2, 1);
	Graph_AddEdge(g, 2, 3, 1);
	Graph_AddEdge(g, 1, 3, 1);
	Graph_AddEdge(g, 0, 1, 1);
	
	Graph_Display(g, printStudent);
	Graph_DeletEdge(g, 1, 3);
	Graph_Display(g, printStudent);
	return 0;

}