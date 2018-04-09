#pragma once
#ifndef _TREE_H_
#define _TREE_H_

typedef void Tree;
typedef void GTreeData;
typedef void (GTree_Printf)(GTreeData*);//定义一个输出的函数指针
//创建树
Tree* Tree_Create();

//销毁已经存在的树
void Tree_Destroy(Tree *tree);

//将已经存在的树清空
void Tree_Clear(Tree* tree);

//将结点node插入到tree中的pos位置处
int Tree_Insert(Tree* tree, GTreeData* data, int pos);

//将tree中pos位置的结点删除并返回
GTreeData* Tree_Delete(Tree* tree, int pos);

//将tree中的pos位置处的结点返回
GTreeData* Tree_Get(Tree* tree, int pos);

//返回tree的根节点
GTreeData* Tree_Root(Tree* tree);

//返回tree的高度
int Tree_Height(Tree* tree);

//返回树的结点数
int Tree_Count(Tree* tree);

//返回树的度数
int Tree_Degree(Tree* tree);

void GTree_Display(Tree* tree,GTree_Printf* pFunc,int gap, char div);


#endif // !_TREE_H_
