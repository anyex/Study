#pragma once
#ifndef _LINKLIST_H_
#define _LINKLIST_H_


typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
	LinkListNode* next;
};

LinkListNode* LinkList_Create();

void LinkList_Destroy(LinkListNode* list);

void LinkList_Clear(LinkListNode* list);

int LinkList_Length(LinkListNode* list);

int LinkList_Insert(LinkListNode* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkListNode* list, int pos);

LinkListNode* LinkList_Delete(LinkListNode* list, int pos);

#endif
