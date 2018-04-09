#pragma once
#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include "stdio.h"
#include "stdlib.h"

typedef void LinkList;
typedef struct _tag_LinkListNode LinkListNode ;
struct _tag_LinkListNode
{
	LinkListNode* next;

};

//创建链表
LinkList* LinkList_Create();
//销毁链表
void LinkList_Destroy(LinkList* list);
//清空链表
void LinkList_Clear(LinkList* list);
//获取链表的长度
int LinkList_Length(LinkList* list);
//插入链表
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
//获取指定位置的元素
LinkListNode* LinkList_Get(LinkList* list, int pos);
//删除指定位置的元素
LinkListNode* LinkList_Delete(LinkList* list, int pos);
#endif // !_LINKLIST_H_
