#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);//����˳���

SeqListNode* SeqList_Get(SeqList* list, int pos);//����posλ�õ�Ԫ��

void SeqList_Destroy(SeqList* list);//����˳���
void SeqList_Clear(SeqList* list);//���˳���
int SeqList_Capacity(SeqList* list);//����˳��������

SeqListNode* SeqList_Delete(SeqList* list, int pos);//ɾ��posλ�õ�Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);//��posλ�ò���node
int SeqList_Length(SeqList* list);
#endif // !_SEQLIST_H_
