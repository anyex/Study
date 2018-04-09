#include"LinkStack.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct _tag_LinkStack {
	LinkStackNode* next;
	int length;
}TLinkStack;

LinkStack* LinkStack_Create()
{
	TLinkStack* ret = (TLinkStack*)malloc(sizeof(TLinkStack));
	if (ret != NULL)
	{
		ret->length = 0;
		ret->next = NULL;
	}

	return ret;
}
void LinkStack_Destroy(LinkStack* stack)
{
	free(stack);
}
void LinkStack_Clear(LinkStack* stack)
{
	TLinkStack* Stack = (TLinkStack*)stack;
	if (Stack != NULL)
	{
		Stack->length = 0;
		Stack->next = NULL;
	}
}

//入栈
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStack* Stack = (TLinkStack*)stack;
	LinkStackNode* addPoint = (LinkStackNode*)malloc(sizeof(LinkStackNode));

	addPoint->data = (unsigned int)item;
	int i = 0;
	int ret = (stack != NULL) && (addPoint != NULL);
	LinkStackNode* cur = (LinkStackNode*)Stack;
	if (ret)
	{
		for (i = 0; i<Stack->length; i++)
		{
			cur = cur->next;
		}

		cur->next = addPoint;
	}
	Stack->length++;
	return ret;
}

//出栈

void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStack* Stack = (TLinkStack*)stack;
	int i = 0;
	int ret = (stack != NULL);
	LinkStackNode* cur = (LinkStackNode*)Stack, *rest = NULL;
	if (ret)
	{
		for (i = 0; i<Stack->length; i++)
		{
			cur = cur->next;
		}
		rest = cur;
	}

	cur = cur->next;
	Stack->length--;
	return (void*)rest->data;
}
//获取栈顶元素
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStack* Stack = (TLinkStack*)stack;
	int i = 0;
	int ret = (stack != NULL);
	LinkStackNode* cur = Stack->next;
	if (ret)
	{
		for (i = 0; i<Stack->length; i++)
		{
			cur = cur->next;
		}

	}

	return cur;
}


//获取栈的大小
int LinkStack_Size(LinkStack* stack)
{
	TLinkStack* Stack = (TLinkStack*)stack;
	int ret = -1;
	if (Stack != NULL)
	{
		ret = Stack->length;
	}
	return ret;
}