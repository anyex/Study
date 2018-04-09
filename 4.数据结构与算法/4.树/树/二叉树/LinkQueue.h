#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "stdio.h"
#include "stdlib.h"

typedef void LinkQueue;

LinkQueue* LinkQueue_Create();//��������

void LinkQueue_Destroy(LinkQueue* queue);//���ٶ���

void LinkQueue_Clear(LinkQueue* queue);//��ն���

int LinkQueue_Append(LinkQueue* queue, void* item);//���

void* LinkQueue_Retrieve(LinkQueue* queue);//��ȡ��β

void* LinkQueue_Header(LinkQueue* queue);//��ȡ��ͷ

int LinkQueue_Length(LinkQueue* queue);//��ȡ���г���


#endif