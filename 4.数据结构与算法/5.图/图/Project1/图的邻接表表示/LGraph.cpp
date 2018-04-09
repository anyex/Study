#include "LGraph.h"
#include "LinkList.h"
#include "stdio.h"
#include "stdlib.h"
typedef struct _tag_LGraph
{
	int count;     //记录顶点个数
	int EdgeNum;   //记录边的条数
	LVertex** V;   //记录与顶点相关的数据描述
	LinkList** la; //记录描述边集的链表数组
}TLGraph;

//边集链表的结点
typedef struct _tag_ListNode
{
	LinkListNode header;
	int v;
	int w;
}TListNode;

//创建图
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
//添加边
int LGraph_AddEdge(LGraph* graph, int v1, int v2, int w)
{
	TLGraph* tLGraph = (TLGraph*)graph;

	int ret = (tLGraph != NULL) && (v1 >= 0) && (v2 >= 0);
	//设置要添加的边集结点

	TListNode* EdgeNode = (TListNode*)malloc(sizeof(TListNode));
	if (EdgeNode != NULL)
	{
		EdgeNode->v = v2;
		EdgeNode->w = w;
		
	}
	ret = ret && (EdgeNode != NULL);
	if (ret)
	{
		//插入到边集链表
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
		//打印顶点
		printf("顶点：");
		for (i = 0; i < tGraph->count; i++)
		{
			S(*tGraph->V, i);
			printf("\t");
		}
		//打印边集
		printf("\n");
		printf("图的拓扑结构：\n");
		for (i = 0; i < tGraph->count; i++)
		{

			for (j = 0; j <LinkList_Length(tGraph->la[i]); j++)
			{
				TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i],j);
				S(*tGraph->V, i);
				printf("---(权值%d)----> ", node->w);
				S(*tGraph->V, node->v);
				printf("\t");
			}
			printf("\n");
		}

	}
}

//移除边
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

//销毁图（遇有多级指针的先删除上层指针）
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

//清除图，即删除边集
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
				//释放边集结点
				free(LinkList_Delete(tLGraph->la[i], 0));
			}
		}
	}
}

//获取指定的边
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

//获取指定结点的深度
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
//图的顶点数目
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

//图的边数
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