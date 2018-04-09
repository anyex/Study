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
int LinkStack_Push(LinkStack* stack, void* item);//入栈

void* LinkStack_Pop(LinkStack* stack);//出栈

void* LinkStack_Top(LinkStack* stack);//获取栈顶元素

int LinkStack_Size(LinkStack* stack);//获取栈的大小

#endif // !_SEQSTACK
