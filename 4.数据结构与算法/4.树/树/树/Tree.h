#pragma once
#ifndef _TREE_H_
#define _TREE_H_

typedef void Tree;
typedef void GTreeData;
typedef void (GTree_Printf)(GTreeData*);//����һ������ĺ���ָ��
//������
Tree* Tree_Create();

//�����Ѿ����ڵ���
void Tree_Destroy(Tree *tree);

//���Ѿ����ڵ������
void Tree_Clear(Tree* tree);

//�����node���뵽tree�е�posλ�ô�
int Tree_Insert(Tree* tree, GTreeData* data, int pos);

//��tree��posλ�õĽ��ɾ��������
GTreeData* Tree_Delete(Tree* tree, int pos);

//��tree�е�posλ�ô��Ľ�㷵��
GTreeData* Tree_Get(Tree* tree, int pos);

//����tree�ĸ��ڵ�
GTreeData* Tree_Root(Tree* tree);

//����tree�ĸ߶�
int Tree_Height(Tree* tree);

//�������Ľ����
int Tree_Count(Tree* tree);

//�������Ķ���
int Tree_Degree(Tree* tree);

void GTree_Display(Tree* tree,GTree_Printf* pFunc,int gap, char div);


#endif // !_TREE_H_
