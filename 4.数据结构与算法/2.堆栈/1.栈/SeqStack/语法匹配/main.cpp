#include "stdio.h"
#include "stdlib.h"
#include "LinkStack.h"

//�������ߵ��ַ�
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

//�ж��Ƿ����ұߵ��ַ�
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

//�ж������ַ��Ƿ�ƥ��
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
				printf("%c������ȷƥ��", *c);
			}
		}
		

		i++;
	}
	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0'))
	{
		printf("ƥ��ɹ�\n");

	}

	else
	{
		printf("�����������\n");
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