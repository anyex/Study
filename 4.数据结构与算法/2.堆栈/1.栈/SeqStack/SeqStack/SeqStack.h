#pragma once
#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;
typedef void SeqStackNode;
SeqStack* SeqStack_Create(int capacity);
void SeqStack_Destroy(SeqStack* stack);
void SeqStack_Clear(SeqStack* stack);
int SeqStack_Push(SeqStack* stack, void* item);//��ջ

void* SeqStack_Pop(SeqStack* stack);//��ջ

void* SeqStack_Top(SeqStack* stack);//��ȡջ��Ԫ��

int SeqStack_Size(SeqStack* stack);//��ȡջ�Ĵ�С

#endif // !_SEQSTACK
