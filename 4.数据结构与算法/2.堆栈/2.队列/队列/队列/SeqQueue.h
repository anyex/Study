#pragma once
#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
#include "stdio.h"
#include "stdlib.h"

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);//��������

void SeqQueue_Destroy(SeqQueue* queue);//���ٶ���

void SeqQueue_Clear(SeqQueue* queue);//��ն���

int SeqQueue_Append(SeqQueue* queue, void* item);//���

void* SeqQueue_Retrieve(SeqQueue* queue);//��ȡ��β

void* SeqQueue_Header(SeqQueue* queue);//��ȡ��ͷ

int SeqQueue_Length(SeqQueue* queue);//��ȡ���г���

int SeqQueue_Capacity(SeqQueue* queue);//��ȡ��������

#endif
