#include "LinkList.h"
//为了实现代码的复用，即链表能保存任意相同类型的数据，链表只保存地址

typedef struct _tag_TLinkListNode TLinkListNode;
struct _tag_TLinkListNode
{
	TLinkListNode* next;
	void* data;
};
typedef struct _tag_TLinkList {
	TLinkListNode header;
	int length;

}TLinkList;



//创建链表
LinkList* LinkList_Create()
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		
	}
	return ret;
}
//销毁链表
void LinkList_Destroy(LinkList* list)
{
	free(list);
}
//清空链表
void LinkList_Clear(LinkList* list)
{
	TLinkList *sList = (TLinkList*)list;
	if (sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
	}
}
//获取链表的长度
int LinkList_Length(LinkList* list)
{
	TLinkList *sList = (TLinkList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = sList->length;
	}

	return ret;
}
//插入链表
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	TLinkListNode* Node = (TLinkListNode*)malloc(sizeof(TLinkListNode));
	
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL)&&(Node != NULL);
	int i = 0;
	if (ret)
	{
		TLinkListNode* current = (TLinkListNode*)(&sList->header);
		Node->data = node;
		Node->next = NULL;
		for (i = 0; (i<pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		current->next = Node;
		sList->length++;
	}

	return ret;
	
}
//获取指定位置的元素
LinkListNode* LinkList_Get(LinkList* list, int pos)
{

	TLinkList* sList = (TLinkList*)list;
	TLinkListNode* ret = NULL;
	int i = 0;
	TLinkListNode* current = (TLinkListNode*)(&sList->header);
	if ((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}
	}
	
	ret = current->next;
	if (ret == NULL)
		return NULL;
  return ret->data;

	
}
//删除指定位置的元素
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	TLinkListNode* ret = NULL;
	void* retdata = NULL;
	int i = 0;

	if ((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		TLinkListNode* current = (TLinkListNode*)(&sList->header);

		for (i = 0; i<pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		current->next = ret->next;

		sList->length--;
	}
		retdata = ret->data;

		free(ret);

	return retdata;

}
