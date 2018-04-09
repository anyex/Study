#pragma once
#ifndef _BTREE_H_
#define _BTREE_H_
#include "stdio.h"
#include "stdlib.h"
#include "LinkQueue.h"
typedef void BTree;//二叉树
typedef void BTreeData;//二叉树结点
typedef unsigned long long BTPos;//标示二叉树结点位置
typedef void (BTree_Printf)(BTreeData*);

#define BT_LEFT 0
#define BT_RIGHT 1

BTree* BTree_Create();

void BTree_Destroy(BTree* tree);

void BTree_Clear(BTree* tree);
//将结点data插入到BTree中的pos位置处,count为左转右转的次数，flag
int BTree_Insert(BTree* tree, BTreeData* data, BTPos pos, int count, int flag);
//根据路径pos，删除结点
BTreeData* BTree_Delete(BTree* tree, BTPos pos, int count);
//获取路径指向的结点
BTreeData* BTree_Get(BTree* tree, BTPos pos, int count);
//获取根结点
BTreeData* BTree_Root(BTree* tree);
//获取树的高度
int BTree_Height(BTree* tree);
//获取二叉树结点数目
int BTree_Count(BTree* tree);
//获取二叉树深度
int BTree_Degree(BTree* tree);
//打印二叉树
void BTree_Display(BTree* tree, BTree_Printf* pFunc, int gap, char div);
//前序遍历二叉树
void BTree_Front(BTree* tree, BTree_Printf* pFunc);

//中序遍历二叉树
void BTree_Middle(BTree* tree, BTree_Printf* pFunc);
//后序遍历二叉树
void BTree_Behand(BTree* tree, BTree_Printf* pFunc);
//按层遍历
void BTree_Level(BTree* tree, BTree_Printf* pFunc);
#endif // !_BTREE_H_
