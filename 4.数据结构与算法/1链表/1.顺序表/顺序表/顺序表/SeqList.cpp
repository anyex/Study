#include "stdio.h"
#include "SeqList.h"
#include "stdlib.h"

typedef unsigned int TSeqListNode;//为了实现代码的复用，用一个地址来保存数据

typedef struct _tag_TSeqList
{
	
	int capacity;//容量
	int length;//长度
	TSeqListNode* node;

}TSeqList;

//创建顺序表
SeqList* SeqList_Create(int capacity)
{
	TSeqList* ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode)*capacity);//按容量分配空间
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (TSeqListNode*)(ret + 1);//如果不加括号，就会变成(TSeqListNode*)ret + 1，这样先与(TSeqListNode*)结合，再加1就相当于加sizeof(TSeqListNode)不能得到正确的结果
	}

	return ret;
}



//查找pos位置的元素
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode * ret = NULL;

	//判断pos和list的合法性
	if ((sList != NULL) && (pos >= 0) && (pos < sList->length))
	{
		ret = (TSeqListNode*)sList->node[pos];
	}

	return ret;
}


//销毁顺序表
void SeqList_Destroy(SeqList* list)
{
	free(list);
}

//清空顺序表
void SeqList_Clear(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	if (sList != NULL)//检查链表合法性
	{
		sList->length = 0;
	}
}

//返回顺序表的容量
int SeqList_Capacity(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if (sList != NULL)//检查链表合法性
	{
		ret = sList->capacity;
	}

	return ret;
}

//顺序表长度
int SeqList_Length(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if (sList != NULL)//检查链表合法性
	{
		ret = sList->length;
	}

	return ret;
}
//删除pos位置的元素
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode * ret = NULL;

	//判断pos和list的合法性
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

//在pos位置插入node
int  SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	//检查是否符合插入元素的条件
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