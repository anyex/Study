
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


//��������
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


//���ٶ���
void LinkQueue_Destroy(LinkQueue* queue)
{
	free(queue);
}

//��ն���
void LinkQueue_Clear(LinkQueue* queue)
{
	TLinkQueue* TQ = (TLinkQueue*)queue;
	if (TQ != NULL)
	{
		TQ->length = 0;
		TQ->node->next = NULL;
	}
}

//���
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
//����
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
//��ȡ��ͷ

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
//��ȡ���г���
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

