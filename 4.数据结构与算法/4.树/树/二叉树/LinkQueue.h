#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "stdio.h"
#include "stdlib.h"

typedef void LinkQueue;

LinkQueue* LinkQueue_Create();//创建队列

void LinkQueue_Destroy(LinkQueue* queue);//销毁队列

void LinkQueue_Clear(LinkQueue* queue);//清空队列

int LinkQueue_Append(LinkQueue* queue, void* item);//入队

void* LinkQueue_Retrieve(LinkQueue* queue);//获取队尾

void* LinkQueue_Header(LinkQueue* queue);//获取队头

int LinkQueue_Length(LinkQueue* queue);//获取队列长度


#endif