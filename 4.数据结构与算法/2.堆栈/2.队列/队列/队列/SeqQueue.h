#pragma once
#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
#include "stdio.h"
#include "stdlib.h"

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);//创建队列

void SeqQueue_Destroy(SeqQueue* queue);//销毁队列

void SeqQueue_Clear(SeqQueue* queue);//清空队列

int SeqQueue_Append(SeqQueue* queue, void* item);//入队

void* SeqQueue_Retrieve(SeqQueue* queue);//获取队尾

void* SeqQueue_Header(SeqQueue* queue);//获取队头

int SeqQueue_Length(SeqQueue* queue);//获取队列长度

int SeqQueue_Capacity(SeqQueue* queue);//获取队列容量

#endif
