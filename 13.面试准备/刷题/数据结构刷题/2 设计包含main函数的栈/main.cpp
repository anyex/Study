/*
定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素，
要求函数min,push和pop的时间复杂度都是O(1)
复杂度要O(1),只能是顺序栈

使用一个辅助栈，让辅助栈中的栈顶元素始终是最小值
*/


#include "stdlib.h"
#include "stdio.h"

typedef struct tag_StackNode StackNode;

struct tag_StackNode
{   
	int data;//结点的数据
};

struct MinStack {
	int top;
	StackNode* root;
};
typedef struct tag_Stack
{
	StackNode *root;
	int top;
	MinStack* min;
}Stack;

Stack* stack_Create(int MaxNum)
{
	Stack* ret = (Stack*)malloc(sizeof(Stack) + sizeof(StackNode)*MaxNum);
	if (ret != NULL)
	{
		ret->root = (StackNode*)(ret + 1);

		ret->top = -1;//栈顶的位置

		ret->min = (MinStack*)malloc(sizeof(MinStack) * MaxNum);

		ret->min->top = -1;
		ret->min->root = (StackNode*)(ret->min + 1);
	}

	return ret;
}
void stack_Push(Stack* s, int data)
{
	s->root[++s->top].data = data;


	//如果小于了最小栈顶的元素
	if (s->min->root[s->min->top].data> data||s->min->top==-1)
	{
		s->min->root[++s->min->top].data = data;
	}
	else
	{
		int a = s->min->root[s->min->top].data;
		s->min->root[++s->min->top].data = a;
	}
}
int stack_Pop(Stack* s)
{
	int ret = s->root[s->top].data ;
	s->top--;
	s->min->top--;
	
	return ret;
}

int min(Stack* s)
{
	return s->min->root[s->min->top].data;
}

int main()
{
	Stack* stack = stack_Create(10);
	stack_Push(stack, 1);
	stack_Push(stack, 2);
	stack_Push(stack, 3);
	stack_Push(stack, 4);
	stack_Push(stack, -1);
//	stack_Pop(stack);

	printf("%d\n", min(stack));

	return 0;
}