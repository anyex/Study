#include "stdio.h"
#include "SeqList.h"
#include "stdlib.h"

typedef unsigned int TSeqListNode;//Ϊ��ʵ�ִ���ĸ��ã���һ����ַ����������

typedef struct _tag_TSeqList
{
	
	int capacity;//����
	int length;//����
	TSeqListNode* node;

}TSeqList;

//����˳���
SeqList* SeqList_Create(int capacity)
{
	TSeqList* ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode)*capacity);//����������ռ�
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (TSeqListNode*)(ret + 1);//����������ţ��ͻ���(TSeqListNode*)ret + 1����������(TSeqListNode*)��ϣ��ټ�1���൱�ڼ�sizeof(TSeqListNode)���ܵõ���ȷ�Ľ��
	}

	return ret;
}



//����posλ�õ�Ԫ��
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode * ret = NULL;

	//�ж�pos��list�ĺϷ���
	if ((sList != NULL) && (pos >= 0) && (pos < sList->length))
	{
		ret = (TSeqListNode*)sList->node[pos];
	}

	return ret;
}


//����˳���
void SeqList_Destroy(SeqList* list)
{
	free(list);
}

//���˳���
void SeqList_Clear(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	if (sList != NULL)//�������Ϸ���
	{
		sList->length = 0;
	}
}

//����˳��������
int SeqList_Capacity(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if (sList != NULL)//�������Ϸ���
	{
		ret = sList->capacity;
	}

	return ret;
}

//˳�����
int SeqList_Length(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if (sList != NULL)//�������Ϸ���
	{
		ret = sList->length;
	}

	return ret;
}
//ɾ��posλ�õ�Ԫ��
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode * ret = NULL;

	//�ж�pos��list�ĺϷ���
	if ((sList != NULL) && (pos >= 0) && (pos < sList->length))
	{
		ret = (SeqListNode*)sList->node[pos];
	}
	for (int i = pos; i < sList->length-1; i++)
	{
		sList->node[i] = sList->node[i + 1];
		
	}
	sList->length--;
	
	return ret;
}

//��posλ�ò���node
int  SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	//����Ƿ���ϲ���Ԫ�ص�����
	int ret = (sList != NULL) && (pos >= 0);
	    ret = ret && (sList->length + 1 <= sList->capacity);
	int i = 0;
	if (ret)
	{
		if (pos >= sList->length)
		{
			pos = sList->length;
		}
		for (i = sList->length; i > pos; i--)
		{
			sList->node[i] = sList->node[i - 1];
		}

		sList->node[i] = (TSeqListNode) node;
		sList->length++;
	}
		
	return ret;
}