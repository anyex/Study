#pragma once
#ifndef  _GRAPH_H_
#define  _GRAPH_H_
#include "stdio.h"
#include "stdlib.h"
typedef void Graph;
typedef void GraphNode;
typedef void(printGraph)(GraphNode*,int);

Graph* Graph_Create(int num, GraphNode* viewport);//����һ����num������ͼ
void Graph_Destroy(Graph* graph);//����ͼ
void Graph_Clear(Graph* graph);//���ͼ
int Graph_AddEdge(Graph* graph,int v1,int v2, int weight);//�����,��v1��v2֮��
int Graph_DeletEdge(Graph* graph,int v1,int v2);//ɾ����
int Graph_GetWeight(Graph* graph, int v1, int v2);//��ȡȨ
int Graph_GetDepth(Graph* graph,int v);//��ȡ���v�Ķ�
int Graph_NodeNum(Graph* graph);//��ȡͼ�Ľ����
int Graph_EdgeNum(Graph* graph);//��ȡͼ�ı���
void Graph_DFS(Graph* graph, int v);//������ȱ���
void Graph_BFS(Graph* graph, int v);//������ȱ���
void Graph_Display(Graph* graph, printGraph* S);//��ӡͼ

#endif // !_GRAPH_H_
