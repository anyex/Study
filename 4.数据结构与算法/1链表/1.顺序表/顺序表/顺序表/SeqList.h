#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);//创建顺序表

SeqListNode* SeqList_Get(SeqList* list, int pos);//查找pos位置的元素

void SeqList_Destroy(SeqList* list);//销毁顺序表
void SeqList_Clear(SeqList* list);//清空顺序表
int SeqList_Capacity(SeqList* list);//返回顺序表的容量

SeqListNode* SeqList_Delete(SeqList* list, int pos);//删除pos位置的元素
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);//在pos位置插入node
int SeqList_Length(SeqList* list);
#endif // !_SEQLIST_H_
