#pragma once
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef void LinkStack;
typedef struct _tag_LinkStackNode LinkStackNode;
struct _tag_LinkStackNode {
	LinkStackNode* next;
	void* data;
};
LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack, void* item);//��ջ

void* LinkStack_Pop(LinkStack* stack);//��ջ

void* LinkStack_Top(LinkStack* stack);//��ȡջ��Ԫ��

int LinkStack_Size(LinkStack* stack);//��ȡջ�Ĵ�С

#endif // !_SEQSTACK
