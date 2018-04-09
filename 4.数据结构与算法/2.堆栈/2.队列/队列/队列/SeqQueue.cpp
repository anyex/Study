#include "SeqQueue.h"

//创建队列

typedef unsigned int SeqQueueNode;

typedef struct _tag_SeqQueue {
	int capacity;
	int length;
	SeqQueueNode* node;
}TSeqQueue;

SeqQueue* SeqQueue_Create(int capacity)
{
	TSeqQueue* ret = (TSeqQueue*)malloc(sizeof(TSeqQueue) + sizeof(SeqQueue*)*capacity);
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (SeqQueueNode*)(ret + 1);
	}
	return ret;
}
//销毁队列
void SeqQueue_Destroy(SeqQueue* queue)
{
	free(queue);
}
//清空队列
void SeqQueue_Clear(SeqQueue* queue)
{
	TSeqQueue *ret = (TSeqQueue*)queue;
	if (ret != NULL)
	{
		ret->length = 0;
	}


}

//入队
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	TSeqQueue *TQ = (TSeqQueue*)queue;
	int ret = (TQ != NULL)&&(item!=NULL);
	if (ret)
	{
		SeqQueueNode* cur = TQ->node;
		cur[TQ->length] = (SeqQueueNode)item;
		TQ->length++;
	}
	
	return ret;

}

//出队
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	TSeqQueue* TQ = (TSeqQueue*)queue;
	
	SeqQueueNode* ret =NULL;
	if (TQ != NULL)
	{
		ret = (unsigned int*)TQ->node[0];
		TQ->length--;
		TQ->node = &TQ->node[1];
	}



	return ret;
}

//获取队头
void* SeqQueue_Header(SeqQueue* queue)
{
	TSeqQueue* TQ = (TSeqQueue*)queue;

	SeqQueueNode* ret = NULL;
	if (TQ != NULL)
	{
		ret =(unsigned int*) TQ->node[0];
	}



	return ret;
}

//获取队列长度
int SeqQueue_Length(SeqQueue* queue)
{
	TSeqQueue* TQ = (TSeqQueue*)queue;
	int ret = -1;
	if (TQ != NULL)
	{
		ret = TQ->length;
	}

	return ret;
}

//获取队列容量
int SeqQueue_Capacity(SeqQueue* queue)
{
	TSeqQueue* TQ = (TSeqQueue*)queue;
	int ret = -1;

	if (TQ != NULL)
	{
		ret = TQ->capacity;
	}
	return ret;
}
