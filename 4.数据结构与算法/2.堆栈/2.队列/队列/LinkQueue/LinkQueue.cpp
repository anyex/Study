
#include "LinkQueue.h"

typedef struct _tag_LinkQueueNode LinkQueueNode;

struct _tag_LinkQueueNode {
	LinkQueueNode* next;
	unsigned int data;
};

typedef struct _tag_SeqQueue {
	int length;
	LinkQueueNode* node;
}TLinkQueue;


//创建队列
LinkQueue* LinkQueue_Create()
{
	TLinkQueue* ret = (TLinkQueue*)malloc(sizeof(TLinkQueue));
	if (ret != NULL)
	{
		ret->length = 0;
		ret->node = NULL;
	}

	return ret;
}


//销毁队列
void LinkQueue_Destroy(LinkQueue* queue)
{
	free(queue);
}

//清空队列
void LinkQueue_Clear(LinkQueue* queue)
{
	TLinkQueue* TQ = (TLinkQueue*)queue;
	if (TQ != NULL)
	{
		TQ->length = 0;
		TQ->node->next = NULL;
	}
}

//入队
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	TLinkQueue* TQ = (TLinkQueue*)queue;
	
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	node->data = (unsigned int)item;
	int ret = (TQ != NULL) && (item != NULL)&&(node != NULL);
	if (ret)
	{
		LinkQueueNode* cur = TQ->node;
		if (cur == NULL)
		{
			TQ->node = node;

		}
		else {
			for (int i = 0; (i < TQ->length) && (cur->next != NULL); i++)
			{
				cur = cur->next;
			}
			cur->next = node;
			
		}
		node->next = NULL;
		TQ->length++;
	}

	return ret;
}
//出队
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueue* TQ = (TLinkQueue*)queue;
	LinkQueueNode* ret = NULL,*cur = NULL;
	if(TQ!=NULL)
	{
	    cur = TQ->node;
		TQ->node = cur->next;
		TQ->length--;
	}
	
	

	return (void*)cur->data;
}
//获取队头

void* LinkQueue_Header(LinkQueue* queue)
{
	LinkQueueNode* ret = NULL;
	TLinkQueue* TQ = (TLinkQueue*)queue;
	if (TQ != NULL)
	{
		ret = TQ->node;
	}

	return (void*)ret->data;
}
//获取队列长度
int LinkQueue_Length(LinkQueue* queue)
{
	TLinkQueue* TQ = (TLinkQueue*)queue;
	int ret = -1;
	if (TQ != NULL)
	{
		ret = TQ->length;
	}

	return ret;
}

