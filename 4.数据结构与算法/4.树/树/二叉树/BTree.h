#pragma once
#ifndef _BTREE_H_
#define _BTREE_H_
#include "stdio.h"
#include "stdlib.h"
#include "LinkQueue.h"
typedef void BTree;//������
typedef void BTreeData;//���������
typedef unsigned long long BTPos;//��ʾ���������λ��
typedef void (BTree_Printf)(BTreeData*);

#define BT_LEFT 0
#define BT_RIGHT 1

BTree* BTree_Create();

void BTree_Destroy(BTree* tree);

void BTree_Clear(BTree* tree);
//�����data���뵽BTree�е�posλ�ô�,countΪ��ת��ת�Ĵ�����flag
int BTree_Insert(BTree* tree, BTreeData* data, BTPos pos, int count, int flag);
//����·��pos��ɾ�����
BTreeData* BTree_Delete(BTree* tree, BTPos pos, int count);
//��ȡ·��ָ��Ľ��
BTreeData* BTree_Get(BTree* tree, BTPos pos, int count);
//��ȡ�����
BTreeData* BTree_Root(BTree* tree);
//��ȡ���ĸ߶�
int BTree_Height(BTree* tree);
//��ȡ�����������Ŀ
int BTree_Count(BTree* tree);
//��ȡ���������
int BTree_Degree(BTree* tree);
//��ӡ������
void BTree_Display(BTree* tree, BTree_Printf* pFunc, int gap, char div);
//ǰ�����������
void BTree_Front(BTree* tree, BTree_Printf* pFunc);

//�������������
void BTree_Middle(BTree* tree, BTree_Printf* pFunc);
//�������������
void BTree_Behand(BTree* tree, BTree_Printf* pFunc);
//�������
void BTree_Level(BTree* tree, BTree_Printf* pFunc);
#endif // !_BTREE_H_
