#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct _tag_Graph TGraph;
struct _tag_Graph
{
	int NodeNum;//图的结点数
	int EdgeNum;//边数
	int **Matrix;//邻接矩阵(边集)
	GraphNode **V;//图的顶点信息（顶点集合）
};


Graph* Graph_Create(int num,GraphNode* viewport)
{
	TGraph *ret = (TGraph*)malloc(sizeof(TGraph));
	int i = 0;
	if (ret != NULL)
	{
		ret->EdgeNum = 0;
		ret->NodeNum = num;
		//分配邻接矩阵
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
		//打印顶点
		printf("顶点：");
		for (i = 0; i < tGraph->NodeNum; i++)
		{
			S(*tGraph->V,i);
			printf("\t");
		}
		//打印边集
		printf("\n");
		printf("图的拓扑结构：\n");
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
//加入边,在v1和v2之间
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
//销毁图
void Graph_Destroy(Graph* graph)
{
	TGraph* tGraph = (TGraph*)graph;
	//释放空间应该层层释放，从高层指针释放到底层指针
	if (tGraph != NULL)
	{
		free(tGraph->V);
		free(tGraph->Matrix[0]);
		free(tGraph->Matrix);
		free(tGraph);
	}
}
//清空图
void Graph_Clear(Graph* graph)
{
	TGraph* tGraph = (TGraph*)graph;

	//取消图即取消边，让各个顶点之间无联系
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
//删除v1->v2的边
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
//获取权
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

//获取结点v的度
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
			}//出度:v->i，起始于顶点v的弧的数目

			if (tGraph->Matrix[i][v] != 0)
			{
				ret++;
			}//入度:i->v,终止于顶点v的弧的数目
		}
	}

	return ret;
	
}

//获取图的结点数
int Graph_NodeNum(Graph* graph)
{
	TGraph* tGraph = (TGraph*)graph;
	if (tGraph != NULL)
	{
		return tGraph->NodeNum;
	}

	return -1;
}

//获取图的边数
int Graph_EdgeNum(Graph* graph)
{

	TGraph* tGraph = (TGraph*)graph;
	if (tGraph != NULL)
	{
		return tGraph->EdgeNum;
	}

	return -1;
}
void Graph_DFS(Graph* graph, int v);//深度优先遍历
