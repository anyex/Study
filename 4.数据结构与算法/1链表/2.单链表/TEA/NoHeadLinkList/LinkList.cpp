#include "LinkList.h"
#include "stdlib.h"
LinkListNode* LinkList_Create()
{
	 LinkListNode* ret = (LinkListNode*)malloc(sizeof(LinkListNode)) ;
	 if (ret != NULL)
		 ret->next = NULL;
	return ret;
}

void LinkList_Destroy(LinkListNode* list)
{

}

void LinkList_Clear(LinkListNode* list)
{

}

int LinkList_Length(LinkListNode* list)
{
	int ret = 0;
	LinkListNode* sList = list;
	for (int i = 0; sList->next != NULL; i++)
	{
		ret++;
	}
	return ret;
}

int LinkList_Insert(LinkListNode* list, LinkListNode* node, int pos)
{
	
	LinkListNode* cur = list;
	int ret = (node != NULL) && (pos >= 0);
	if (ret)
	{
		for (int i = 0; (i < pos)&&(cur->next != NULL); i++)
		{
			cur = cur->next;
		}
		
		node->next = cur->next;
		cur->next = node;
		if (list->next == node)
		{
			list = node;
		}
	}

	return ret;

}

LinkListNode* LinkList_Get(LinkListNode* list, int pos)
{
	LinkListNode* ret = list;
	
	for (int i = 0; i < pos&&(ret->next!=NULL); i++)
	{
		ret = ret->next;
	}
	
	return ret;
}

LinkListNode* LinkList_Delete(LinkListNode* list, int pos);