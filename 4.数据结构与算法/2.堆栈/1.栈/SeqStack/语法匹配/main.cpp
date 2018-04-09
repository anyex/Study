#include "stdio.h"
#include "stdlib.h"
#include "LinkStack.h"

//如果是左边的字符
int isLeft(char c)
{
	int ret = 0;
	switch (c)
	{
		case '<':
		case '(':
		case '[':
		case '{':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
		break;
	}

	return ret;
}

//判断是否是右边的字符
int isRight(char c)
{
	int ret = 0;

	switch (c)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

//判断左右字符是否匹配
int match(char left, char right)
{
	int ret = 0;

	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int scanner(const char* code)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;
	while (code[i] != '\0')
	{
		if (isLeft(code[i]))
		{
			LinkStack_Push(stack,(void*)(code+i));
		}
		if (isRight(code[i]))
		{
			char* c = (char*)LinkStack_Pop(stack);
			if ((c == NULL) || !match(*c, code[i]))
			{
				printf("%c不能正确匹配", *c);
			}
		}
		

		i++;
	}
	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0'))
	{
		printf("匹配成功\n");

	}

	else
	{
		printf("代码输入出错\n");
	}

	LinkStack_Destroy(stack);
	return ret;

}

int main()
{
	const char* code = "<)";
	scanner(code);
	return 0;

}