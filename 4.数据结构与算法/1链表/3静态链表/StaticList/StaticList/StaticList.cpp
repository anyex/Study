#include "StaticList.h"
#include "stdlib.h"
#include "stdio.h"
#define AVAILABLE -1

typedef struct _tag_StaticListNode {
	void* date;//为了复用，保存数据地址
	int next;

}TStaticListNode;

typedef struct _tag_StaticList {
	int capacity;
	TStaticListNode header;
	TStaticListNode node[];
}TStaticList;

StaticList* StaticList_Create(int capacity)
{
	int i = 0;
	TStaticList* ret = NULL;

	if (capacity >= 0)
	{ 
		ret = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode)*capacity);
	}
	if (ret!=NULL)
	{
		ret->capacity = capacity;
		ret->header.date = (int*)malloc(sizeof(int));//链表长度
		*((int*)(ret->header.date)) = 0;
		ret->header.next = 0;
		for (i = 0; i <= capacity; i++)
		{
			ret->node[i].next = AVAILABLE;
		}
	}

	return ret;
}
void StaticList_Destroy(StaticList* list)
{
	free(list);
}
void StaticList_Clear(StaticList* list)
{
	int i = 0;
	TStaticList* sList = (TStaticList*)list;
	if (sList != NULL)
	{
		sList->header.date = 0;
		sList->header.next = 0;

		for (i = 1; i <= sList->capacity; i++)
		{
			sList->node[i].next = AVAILABLE;
		}

		
	}
}
int StaticList_Length(StaticList* list)
{
	TStaticList* sList = (TStaticList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = *((int*)sList->header.date);
		
	}

	return ret;
}
int StaticList_Insert(StaticList* list, StaticListNode* node, int pos)
{
	TStaticList* sList = (TStaticList*)list;
	TStaticListNode* Node = (TStaticListNode*)node;
	int ret = (sList != NULL) && (pos >= 0)&&(node!=NULL);
	int i = 0;
	int index =0;
	int cur = 0;
	if (ret)
	{
		//寻找空闲空间
		for (i = 1;i <= sList->capacity; i++)
		{
			if (sList->node[i].next == AVAILABLE)
			{
				index = i;
				break;
			}
		}

		//将传入的数据保存到空间空间
		sList->node[index].date = (void*)node;
		sList->node[0] = sList->header;

		//找到要插入的位置
		for (i = 0; (i < pos) && (sList->node[cur].next != 0); i++)
		{
			cur = sList->node[cur].next;
		}
		//插入
		sList->node[index].next = sList->node[cur].next;
		sList->node[cur].next = index;
		//长度加1
		(*(int*)(sList->header.date))++;

		sList->header = sList->node[0];
	
		  
	}

	return ret;
	
}
StaticListNode* StaticList_Get(StaticList* list, int pos)
{
	TStaticList* sList = (TStaticList*)list;
	int cur =0;
	for (int i = 0; i < pos; i++)
	{
		cur = sList->node[i].next;
	}

	return sList->node[sList->node[cur].next].date;
}
StaticListNode* StaticList_Delete(StaticList* list, int pos)
{
	TStaticList* sList = (TStaticList*)list;
	int cur = 0;
	for (int i = 0; i < pos; i++)
	{
		cur = sList->node[i].next;
	}
	int obj = sList->node[cur].next;
	sList->node[cur].next = sList->node[obj].next;
	(*(int*)(sList->header.date))--;
	return (StaticListNode*)sList->node[obj].date;
	
}