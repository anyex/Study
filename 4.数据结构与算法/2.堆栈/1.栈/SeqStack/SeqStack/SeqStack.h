#pragma once
#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;
typedef void SeqStackNode;
SeqStack* SeqStack_Create(int capacity);
void SeqStack_Destroy(SeqStack* stack);
void SeqStack_Clear(SeqStack* stack);
int SeqStack_Push(SeqStack* stack, void* item);//入栈

void* SeqStack_Pop(SeqStack* stack);//出栈

void* SeqStack_Top(SeqStack* stack);//获取栈顶元素

int SeqStack_Size(SeqStack* stack);//获取栈的大小

#endif // !_SEQSTACK
