#include "SeqStack.h"

#include "stdio.h"
#include "stdlib.h"

typedef struct _tag_SeqStack
{
	int length;
	int capacity;
	SeqStackNode* node;
}TSeqStack;



SeqStack* SeqStack_Create(int capacity)
{
	TSeqStack* ret = NULL;
	if (capacity >= 0)
	{
		 ret = (TSeqStack*)malloc(sizeof(TSeqStack) + sizeof(SeqStackNode*)*capacity);

	}

	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (SeqStackNode*)(ret + 1);

	}

	return ret;
}
void SeqStack_Destroy(SeqStack* stack)
{
	free(stack);
}
void SeqStack_Clear(SeqStack* stack)
{
	TSeqStack* TStack = (TSeqStack*)stack;
	if (TStack != NULL)
	{
		TStack->length = 0;
		
	}
	
}
int SeqStack_Push(SeqStack* stack, void* item)
{
	TSeqStack* TStack = (TSeqStack*)stack;
	int ret = (TStack != NULL) && (item != NULL);
	if (ret)
	{
		int* a=(int*)TStack->node;
		a[TStack->length] = (int)item;
	}
	TStack->length++;

	return ret;
}//入栈

 //出栈
void* SeqStack_Pop(SeqStack* stack)
{
	TSeqStack* TStack = (TSeqStack*)stack;
	int* Node = (int*)TStack->node;
	SeqStackNode* ret = NULL;
	if (TStack != NULL)
	{
		
		ret = (SeqStackNode*)(Node[TStack->length - 1]);
	}

	   
	TStack->length--;

	return ret;
}

//获取栈顶元素
void* SeqStack_Top(SeqStack* stack)
{
	TSeqStack* TStack = (TSeqStack*)stack;
	int* Node = (int*)TStack->node;
	SeqStackNode* ret = NULL;
	if (TStack != NULL)
	{

		ret = (SeqStackNode*)(Node[TStack->length - 1]);
	}


	return ret;
}
//获取栈的大小
int SeqStack_Size(SeqStack* stack)
{
	TSeqStack* TStack = (TSeqStack*)stack;
	int ret = -1;
	if (TStack != NULL)
	{
		ret = TStack->length;
	}
	return ret;
}
