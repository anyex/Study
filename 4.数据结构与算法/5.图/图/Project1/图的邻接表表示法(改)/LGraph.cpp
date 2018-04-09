#include "LGraph.h"
#include "LinkList.h"


typedef struct _tag_TLGraph
{
	int count;//�������
	LVertex* V;//ͼ�Ķ�����Ϣ
	LinkList** List;//ͼ�ı߼�����
}TLGraph;

typedef struct _tag_EdgeNode
{
	int v;//Ҫ���ӵĽ��
	int w;//�ߵ�Ȩ��
}EdgeNode;




//����ͼ
LGraph* LGraph_Create(LVertex* v, int n)
{
	TLGraph* ret = (TLGraph*)malloc(sizeof(TLGraph));
	int ok = 1;
	if ((ret != NULL)&&( n > 0))
	{
		ret->count = n;
		ret->V = v;
		//Ϊͼ�ı߼���������ָ������
		ret->List = (LinkList**)malloc(sizeof(LinkList*)*n);

		if (ret->List != NULL)
		{
			
			for (int i = 0; (i < n)&&ok; i++)
			{   //Ϊ����ָ�����鴴������
				ok = ok&&((ret->List[i] = LinkList_Create())!=NULL);
			}
		}
		if (!ok)//˵��δ�ɹ���������,���Ѿ��ɹ��������ͷţ���������ͼ���٣�����NULL
		{
			if (ret->List != NULL)
			{
				int i = 0;
				for (i = 0; i < n; i++)
				{
					LinkList_Destroy(ret->List[i]);
				}
			}

			free(ret->List);
			free(ret->V);
			free(ret);
			ret = NULL;
		}
		
	}

	return ret;
}

void LGraph_Destroy(LGraph* graph)
{
	TLGraph* tGraph = (TLGraph*)graph;
	LGraph_Clear(tGraph);//����
	if (tGraph != NULL)
	{
		free(tGraph->List);
		free(tGraph->V);
		free(tGraph);
	}
}

void LGraph_Clear(LGraph* graph)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	if (tLGraph != NULL)
	{
		//�ͷű߼�����������
		for (int i = 0; i < tLGraph->count; i++)
		{
			while (LinkList_Length(tLGraph->List[i]) > 0)
			{
				LinkList_Delete(tLGraph->List[i], 0);
			}
		}
	}
}

int LGraph_AddEdge(LGraph* graph, int v1, int v2, int w)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int ret = (tLGraph != NULL) && (v1 >= 0) && (v2 >= 0);
	EdgeNode* node = (EdgeNode*)malloc(sizeof(EdgeNode));
	ret = ret && (node != NULL);
	if (ret)
	{
		node->v = v2;
		node->w = w;

		LinkList_Insert(tLGraph->List[v1], node, 0);

	}
	
	return ret;

}

int LGraph_RemoveEdge(LGraph* graph, int v1, int v2)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int ret = (tLGraph != NULL) && (v1 >= 0) && (v2 >= 0);
	if (ret)
	{
		int j = 0;
		for (j = 0; j<LinkList_Length(tLGraph->List[v1]); j++)
		{
			
			EdgeNode* node = (EdgeNode*)LinkList_Get(tLGraph->List[v1], j);
			if (node->v == v2)
			{
				LinkList_Delete(tLGraph->List[v1], j);
			}

		}

	}

	return ret;
}

int LGraph_GetEdge(LGraph* graph, int v1, int v2)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int condiction = (tLGraph != NULL) && (v1 >= 0) && (v2 >= 0);
	int ret = -1;
	if (condiction)
	{
		int j = 0;
		for (j = 0; j<LinkList_Length(tLGraph->List[v1]); j++)
		{
			
			EdgeNode* node = (EdgeNode*)LinkList_Get(tLGraph->List[v1], j);
			if (node->v == v2)
			{
				ret = node->w;
			}

		}

	}

	return ret;
}

int LGraph_TD(LGraph* graph, int v)
{
	int ret = 0;
	TLGraph* tLGraph = (TLGraph*)graph;
	int ok = (tLGraph != NULL) && (v >= 0) && (v < tLGraph->count);
	if (ok)
	{
		ret = LinkList_Length(tLGraph->List[v]);//����
		int i = 0, j = 0;
		for ( i = 0; i < tLGraph->count; i++)
		{
			if (i != v)
			{
				for (j = 0; j<LinkList_Length(tLGraph->List[i]); j++)
				{

					EdgeNode* node = (EdgeNode*)LinkList_Get(tLGraph->List[i], j);
					if (node->v == v)
					{
						ret++;//���
					}

				}

			}
		}

	}

	return ret;
}

int LGraph_VertexCount(LGraph* graph)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int ret = 0;
	if (tLGraph != NULL)
	{
		ret = tLGraph->count;
	}
	return ret;
}

int LGraph_EdgeCount(LGraph* graph)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int i = 0, j = 0;
	int ret = 0;
	if (tLGraph != NULL)
	{
		for (i = 0; i < tLGraph->count; i++)
		{

			ret += LinkList_Length(tLGraph->List[i]);
		}
	}
	

	return ret;
}

static void dfs(TLGraph* graph, int v, LGraph_Printf* pFunc, int* visted)
{
	//�ǵݹ鷽ʽ����ȱ���
	LinkStack *stack = LinkStack_Create();
	int i = 0;
	if (stack != NULL)
	{
		LinkStack_Push(stack, &v);
		visted[v] = 1;
		while (LinkStack_Size(stack)>0)
		{
			int *item = (int*)LinkStack_Pop(stack);
		
			pFunc(graph->V, *item);
			for (i = 0; i < LinkList_Length(graph->List[*item]); i++)
			{
				EdgeNode* node = (EdgeNode*)LinkList_Get(graph->List[*item], i);
				if (visted[node->v] == 0)
				{
					int*a =&(node->v);
					
					LinkStack_Push(stack, a);
					
					visted[node->v] = 1;
				}
			}
		}
	}
	printf("\n");
	LinkStack_Destroy(stack);
}

static void recurse_dfs(TLGraph* graph, int v, LGraph_Printf* pFunc,int* visted)
{
	int i = 0;
	visted[v] = 1;
	pFunc(graph->V, v);
	for (i = 0; i < LinkList_Length(graph->List[v]); i++)
	{
		EdgeNode* node = (EdgeNode*)LinkList_Get(graph->List[v], i);
		if (visted[node->v]==0)
		{
			recurse_dfs(graph, node->v, pFunc, visted);
		}
	   
	}

	for (i = 0; i < graph->count; i++)
	{
		if (visted[i] == 0)
		{
			recurse_dfs(graph, i, pFunc, visted);
		}
	}

}

static void bfs(TLGraph* graph, int v, LGraph_Printf* pFunc, int* visted)
{
	int i = 0;

	LinkQueue *q = LinkQueue_Create();
	if (q != NULL)
	{
		LinkQueue_Append(q, &v);
		visted[v] = 1;
		while (LinkQueue_Length(q)>0)
		{
			int item = *((int*)LinkQueue_Retrieve(q));
			
			pFunc(graph->V, item);
			for (i = 0; i < LinkList_Length(graph->List[item]); i++)
			{
				EdgeNode* node = (EdgeNode*)LinkList_Get(graph->List[item], i);
				if (visted[node->v] == 0)
				{
					LinkQueue_Append(q, &node->v);
					visted[node->v] = 1;
				}
				
			}
		}
	}
	/*
	 ������ʼ�㣻
     ��ʼ�����ж����ǣ�
     ��ʼ��һ������queue������ʼ�������У�

  while��queue��Ϊ�գ�
  {

    �Ӷ�����ɾ��һ������s�����Ϊ�ѱ����� //��ʾ������s
    ��s�ڽӵ����л�û�����ĵ������У�
  }
	
	*/

	LinkQueue_Destroy(q);
}

//�����������
void LGraph_DFS(LGraph* graph, int v, LGraph_Printf* pFunc)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int ret = (tLGraph != NULL) && (v >= 0) && (v<tLGraph->count);
	int* visted = (int*)calloc(sizeof(int),tLGraph->count);
	ret = ret&&(visted != NULL);
	if (ret)
	{
	    dfs(tLGraph, v, pFunc, visted);
	}

}



//�����������
void LGraph_BFS(LGraph* graph, int v, LGraph_Printf* pFunc)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	int ret = (tLGraph != NULL) && (v >= 0) && (v<tLGraph->count);
	int* visted = (int*)calloc(sizeof(int), tLGraph->count);
	ret = ret && (visted != NULL);
	if (ret)
	{
		bfs(tLGraph, v, pFunc, visted);
	}

}


void LGraph_Display(LGraph* graph, LGraph_Printf* S)
{
	TLGraph* tLGraph = (TLGraph*)graph;
	if (tLGraph != NULL)
	{
		printf("������Ϣ");
		int i = 0;
		int j = 0;
		for (i= 0; i < tLGraph->count; i++)
		{
			S(tLGraph->V, i);
		}
		printf("\n");
		printf("�߼���\n");

		for(i=0;i<tLGraph->count;i++)
		{
		  for(j = 0;j<LinkList_Length(tLGraph->List[i]);j++)
			{
			    printf("\t");
			    EdgeNode* node = (EdgeNode*) LinkList_Get(tLGraph->List[i], j);
				
				S(tLGraph->V, i);
				printf("---Ȩֵ%d--->",node->w);
				S(tLGraph->V, node->v);
				
			}

		  printf("\n");
		}

	}
}