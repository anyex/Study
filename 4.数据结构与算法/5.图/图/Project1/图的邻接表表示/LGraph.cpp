#include "LGraph.h"
#include "LinkList.h"
#include "stdio.h"
#include "stdlib.h"
typedef struct _tag_LGraph
{
	int count;     //��¼�������
	int EdgeNum;   //��¼�ߵ�����
	LVertex** V;   //��¼�붥����ص���������
	LinkList** la; //��¼�����߼�����������
}TLGraph;

//�߼�����Ľ��
typedef struct _tag_ListNode
{
	LinkListNode header;
	int v;
	int w;
}TListNode;

//����ͼ
LGraph* LGraph_Create(LVertex* v, int n)
{
	TLGraph* ret = NULL;

	int ok = 1;
	if ((v != NULL)&&(n >= 0))
	{
		ret = (TLGraph*)malloc(sizeof(TLGraph));

		if (ret)
		{
			ret->count = n;
			ret->EdgeNum = 0;
			ret->V = (LVertex**)calloc(n, sizeof(LVertex*));
			ret->la = (LinkList**)calloc(n, sizeof(LinkList*));

			ok = (ret->V != NULL)&&(ret->la != NULL);

			if (ok)
			{
				int i = 0;

				for (i = 0; (i < n) && ok; i++)
				{
					ok = ok && ((ret->la[i] = LinkList_Create()) != NULL);
				}
			}
		}
	}
	
	*ret->V = v;

	return ret;

}
//��ӱ�
int LGraph_AddEdge(LGraph* graph, int v1, int v2, int w)
{
	TLGraph* tLGraph = (TLGraph*)graph;

	int ret = (tLGraph != NULL) && (v1 >= 0) && (v2 >= 0);
	//����Ҫ��ӵı߼����

	TListNode* EdgeNode = (TListNode*)malloc(sizeof(TListNode));
	if (EdgeNode != NULL)
	{
		EdgeNode->v = v2;
		EdgeNode->w = w;
		
	}
	ret = ret && (EdgeNode != NULL);
	if (ret)
	{
		//���뵽�߼�����
		LinkList_Insert(tLGraph->la[v1], (LinkListNode*)EdgeNode, 0);
	}

	return ret;
}
void Graph_Display(LGraph* graph, LGraph_Printf* S)
{
	TLGraph* tGraph = (TLGraph*)graph;
	if (tGraph != NULL)
	{
		int i = 0, j = 0;
		//��ӡ����
		printf("���㣺");
		for (i = 0; i < tGraph->count; i++)
		{
			S(*tGraph->V, i);
			printf("\t");
		}
		//��ӡ�߼�
		printf("\n");
		printf("ͼ�����˽ṹ��\n");
		for (i = 0; i < tGraph->count; i++)
		{

			for (j = 0; j <LinkList_Length(tGraph->la[i]); j++)
			{
				TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i],j);
				S(*tGraph->V, i);
				printf("---(Ȩֵ%d)----> ", node->w);
				S(*tGraph->V, node->v);
				printf("\t");
			}
			printf("\n");
		}

	}
}

//�Ƴ���
int LGraph_RemoveEdge(LGraph* graph, int v1, int v2)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int condition = (tGraph != NULL);
	int ret = 0;

	condition = condition && (0 <= v1) && (v1 < tGraph->count);
	condition = condition && (0 <= v2) && (v2 < tGraph->count);

	if (condition)
	{
		TListNode* node = NULL;
		int i = 0;

		for (i = 0; i<LinkList_Length(tGraph->la[v1]); i++)
		{
			node = (TListNode*)LinkList_Get(tGraph->la[v1], i);

			if (node->v == v2)
			{
				ret = node->w;

				LinkList_Delete(tGraph->la[v1], i);

				free(node);

				break;
			}
		}
	}

	return ret;
}

//����ͼ�����ж༶ָ�����ɾ���ϲ�ָ�룩
void LGraph_Destroy(LGraph* graph) 
{
	TLGraph* tGraph = (TLGraph*)graph;

	LGraph_Clear(tGraph);

	if (tGraph != NULL)
	{
		int i = 0;

		for (i = 0; i<tGraph->count; i++)
		{
			LinkList_Destroy(tGraph->la[i]);
		}

		free(tGraph->la);
		free(tGraph->V);
		free(tGraph);
	}
}

//���ͼ����ɾ���߼�
void LGraph_clear(LGraph* graph)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	if (tLGraph != NULL)
	{
		int i = 0;
		for (i = 0; i < tLGraph->count; i++)
		{
			while (LinkList_Length(tLGraph->la[i]) > 0)
			{
				//�ͷű߼����
				free(LinkList_Delete(tLGraph->la[i], 0));
			}
		}
	}
}

//��ȡָ���ı�
int LGraph_GetEdge(LGraph* graph, int v1, int v2) // O(n*n)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int condition = (tGraph != NULL);
	int ret = 0;

	condition = condition && (0 <= v1) && (v1 < tGraph->count);
	condition = condition && (0 <= v2) && (v2 < tGraph->count);

	if (condition)
	{
		TListNode* node = NULL;
		int i = 0;

		for (i = 0; i<LinkList_Length(tGraph->la[v1]); i++)
		{
			node = (TListNode*)LinkList_Get(tGraph->la[v1], i);

			if (node->v == v2)
			{
				ret = node->w;

				break;
			}
		}
	}

	return ret;
}

//��ȡָ���������
int LGraph_TD(LGraph* graph, int v) // O(n*n*n)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int condition = (tGraph != NULL);
	int ret = 0;

	condition = condition && (0 <= v) && (v < tGraph->count);

	if (condition)
	{
		int i = 0;
		int j = 0;

		for (i = 0; i<tGraph->count; i++)
		{
			for (j = 0; j<LinkList_Length(tGraph->la[i]); j++)
			{
				TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i], j);

				if (node->v == v)
				{
					ret++;
				}
			}
		}

		ret += LinkList_Length(tGraph->la[v]);
	}

	return ret;
}
//ͼ�Ķ�����Ŀ
int LGraph_VertexCount(LGraph* graph) // O(1)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int ret = 0;

	if (tGraph != NULL)
	{
		ret = tGraph->count;
	}

	return ret;
}

//ͼ�ı���
int LGraph_EdgeCount(LGraph* graph) // O(n)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int ret = 0;

	if (tGraph != NULL)
	{
		int i = 0;

		for (i = 0; i<tGraph->count; i++)
		{
			ret += LinkList_Length(tGraph->la[i]);
		}
	}

	return ret;
}