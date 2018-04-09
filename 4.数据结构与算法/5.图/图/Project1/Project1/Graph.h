#pragma once
#ifndef  _GRAPH_H_
#define  _GRAPH_H_
#include "stdio.h"
#include "stdlib.h"
typedef void Graph;
typedef void GraphNode;
typedef void(printGraph)(GraphNode*,int);

Graph* Graph_Create(int num, GraphNode* viewport);//创建一个有num个结点的图
void Graph_Destroy(Graph* graph);//销毁图
void Graph_Clear(Graph* graph);//清空图
int Graph_AddEdge(Graph* graph,int v1,int v2, int weight);//加入边,在v1和v2之间
int Graph_DeletEdge(Graph* graph,int v1,int v2);//删除边
int Graph_GetWeight(Graph* graph, int v1, int v2);//获取权
int Graph_GetDepth(Graph* graph,int v);//获取结点v的度
int Graph_NodeNum(Graph* graph);//获取图的结点数
int Graph_EdgeNum(Graph* graph);//获取图的边数
void Graph_DFS(Graph* graph, int v);//深度优先遍历
void Graph_BFS(Graph* graph, int v);//广度优先遍历
void Graph_Display(Graph* graph, printGraph* S);//打印图

#endif // !_GRAPH_H_
