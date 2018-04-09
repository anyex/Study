#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct _tag_Graph TGraph;
struct _tag_Graph
{
	int NodeNum;//ͼ�Ľ����
	int EdgeNum;//����
	int **Matrix;//�ڽӾ���(�߼�)
	GraphNode **V;//ͼ�Ķ�����Ϣ�����㼯�ϣ�
};


Graph* Graph_Create(int num,GraphNode* viewport)
{
	TGraph *ret = (TGraph*)malloc(sizeof(TGraph));
	int i = 0;
	if (ret != NULL)
	{
		ret->EdgeNum = 0;
		ret->NodeNum = num;
		//�����ڽӾ���
		ret->Matrix = (int**)malloc(sizeof(int)*num);
		ret->V = (GraphNode**)malloc(sizeof(GraphNode*));
		if (ret->Matrix != NULL)
		{
			for (int i = 0; i < num; i++)
			{
				ret->Matrix[i] = (int*)calloc(num, sizeof(int));
			}	
		}
	}

	ret->V[i] = viewport;
	
	return ret;
}

void Graph_Display(Graph* graph, printGraph* S)
{
	TGraph* tGraph = (TGraph*)graph;
	if (tGraph != NULL)
	{
		int i = 0,j = 0;
		//��ӡ����
		printf("���㣺");
		for (i = 0; i < tGraph->NodeNum; i++)
		{
			S(*tGraph->V,i);
			printf("\t");
		}
		//��ӡ�߼�
		printf("\n");
		printf("ͼ�����˽ṹ��\n");
		for (i = 0; i < tGraph->NodeNum; i++)
		{
			
			for (j = 0; j < tGraph->NodeNum; j++)
			{
				if (tGraph->Matrix[i][j] != 0)
				{
					S(tGraph->V[0], i);
  					printf("->");
					S(tGraph->V[0],j);
					printf("\t");
				}
				
			}
			printf("\n");
		}

	}
}
//�����,��v1��v2֮��
int Graph_AddEdge(Graph* graph, int v1, int v2, int weight)
{
	TGraph* tGraph = (TGraph*)graph;
	int ret = (tGraph != NULL) && (v1 >= 0) && (v2 >= 0);
	ret = ret && (weight >= 0);
	if (ret)
	{
		tGraph->Matrix[v1][v2] = weight;
		tGraph->EdgeNum++;
	}

	return ret;
}
//����ͼ
void Graph_Destroy(Graph* graph)
{
	TGraph* tGraph = (TGraph*)graph;
	//�ͷſռ�Ӧ�ò���ͷţ��Ӹ߲�ָ���ͷŵ��ײ�ָ��
	if (tGraph != NULL)
	{
		free(tGraph->V);
		free(tGraph->Matrix[0]);
		free(tGraph->Matrix);
		free(tGraph);
	}
}
//���ͼ
void Graph_Clear(Graph* graph)
{
	TGraph* tGraph = (TGraph*)graph;

	//ȡ��ͼ��ȡ���ߣ��ø�������֮������ϵ
	if (tGraph != NULL)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < tGraph->NodeNum; i++)
		{
			for (j = 0; j < tGraph->NodeNum; j++)
			{
				tGraph->Matrix[i][j] = 0;
			}
		}
	}
}
//ɾ��v1->v2�ı�
int Graph_DeletEdge(Graph* graph, int v1, int v2)
{
	TGraph* tGraph = (TGraph*)graph;
	int ret = (tGraph != 0) && (v1 >= 0) && (v2 >= 0);
	if (ret)
	{
		tGraph->Matrix[v1][v2] = 0;
	}

	return ret;
}
//��ȡȨ
int Graph_GetWeight(Graph* graph, int v1, int v2)
{
	TGraph* tGraph = (TGraph*)graph;
	int ret = (tGraph != 0) && (v1 >= 0) && (v2 >= 0);
	if (ret)
	{
		ret = tGraph->Matrix[v1][v2];
	}

	return ret;
}

//��ȡ���v�Ķ�
int Graph_GetDepth(Graph* graph,int v)
{
	TGraph* tGraph = (TGraph*)graph;
	int condition = (tGraph != NULL) && (v >= 0) && (v < tGraph->NodeNum);
	int ret = -1;
	if (condition)
	{
		int i = 0;

		for (i = 0; i<tGraph->NodeNum; i++)
		{
			if (tGraph->Matrix[v][i] != 0)
			{
				ret++;
			}//����:v->i����ʼ�ڶ���v�Ļ�����Ŀ

			if (tGraph->Matrix[i][v] != 0)
			{
				ret++;
			}//���:i->v,��ֹ�ڶ���v�Ļ�����Ŀ
		}
	}

	return ret;
	
}

//��ȡͼ�Ľ����
int Graph_NodeNum(Graph* graph)
{
	TGraph* tGraph = (TGraph*)graph;
	if (tGraph != NULL)
	{
		return tGraph->NodeNum;
	}

	return -1;
}

//��ȡͼ�ı���
int Graph_EdgeNum(Graph* graph)
{

	TGraph* tGraph = (TGraph*)graph;
	if (tGraph != NULL)
	{
		return tGraph->EdgeNum;
	}

	return -1;
}
void Graph_DFS(Graph* graph, int v);//������ȱ���
