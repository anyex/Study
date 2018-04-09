#include "LinkList.h"
//Ϊ��ʵ�ִ���ĸ��ã��������ܱ���������ͬ���͵����ݣ�����ֻ�����ַ

typedef struct _tag_LinkListNode TLinkListNode;

 struct _tag_LinkListNode
{
	TLinkListNode* next;
	LinkListNode* data;
};

typedef struct _tag_TLinkList {
	TLinkListNode header;
	int length;
}TLinkList;



//��������
LinkList* LinkList_Create()
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.data = NULL;
		ret->header.next = NULL;
	}

	return ret;
}
//��������
void LinkList_Destroy(LinkList* list)
{
	free(list);
}
//�������
void LinkList_Clear(LinkList* list)
{
	TLinkList *sList = (TLinkList*)list;
	if (sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
	}
}
//��ȡ����ĳ���
int LinkList_Length(LinkList* list)
{
	TLinkList *sList = (TLinkList*)list;
	int ret = -1;
	if (sList != NULL)
	{
		ret = sList->length;
	}

	return ret;
}
//��������
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
	TLinkListNode* Data_node = (TLinkListNode*)malloc(sizeof(TLinkListNode));
	ret = ret && (Data_node != NULL);
	int i = 0;
	   
	if (ret)
	{
		TLinkListNode* current = &sList->header;
		Data_node->data = node;
		for (i = 0; (i<pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		Data_node->next = current->next;
		current->next =Data_node;

		sList->length++;
	}

	return ret;
	
}
//��ȡָ��λ�õ�Ԫ��
LinkListNode* LinkList_Get(LinkList* list, int pos)
{

	TLinkList* sList = (TLinkList*)list;
	TLinkListNode* ret = NULL;
	LinkListNode* Ret = NULL;
	int i = 0;

	if ((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		TLinkListNode* current = (TLinkListNode*)sList;

		for (i = 0; i<pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		if (ret != NULL)
		{
			Ret = ret->data;
		}
	}

	return Ret;

	
}
//ɾ��ָ��λ�õ�Ԫ��
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	TLinkListNode* tag = NULL;//Ҫɾ����Ŀ����
	LinkListNode* Ret = NULL;
	int i = 0;

	if ((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		TLinkListNode* current = (TLinkListNode*)sList;

		for (i = 0; i<pos; i++)
		{
			current = current->next;
		}

		 tag= current->next;
		 current->next = tag->next;
		 sList->length--;

		Ret = tag->data;
	}
	  free(tag);
	return Ret;

}
