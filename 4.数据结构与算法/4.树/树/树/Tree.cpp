#include "Tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"
typedef struct Student {
	char name[20];
	int id;
}Student;
//extern void printStudent(Student* s);
typedef struct  _tag_GTreeNode GTreeNode;//�����
struct _tag_GTreeNode {
	GTreeData* data;//�������������
	GTreeNode* parent;//�����
	LinkList* child;//�ӽ������
};

typedef struct _tag_TLNode TLNode;
struct  _tag_TLNode//��֯����
{
	TLNode* header;
	GTreeNode* node;
};
static int recursive_degree(GTreeNode* node)
{
	int ret = 0;
	if (node != NULL)
	{
		int subDegree = 0;
		int i = 0;

		ret = LinkList_Length(node->child);

		for (i = 0; i < LinkList_Length(node->child); i++)
		{
			GTreeNode* trNode = (GTreeNode*)LinkList_Get(node->child, i);
			subDegree = recursive_degree(trNode);
			if (ret < subDegree)
			{
				ret = subDegree;
			}
		}
	}

	return ret;
}
static int recursive_height(GTreeNode* node)
{
	int ret = 0;
	if (node != NULL)
	{
		int subHeight = 0;
		int i;
		for ( i = 0; i < LinkList_Length(node->child); i++)
		{
			GTreeNode* trNode = (GTreeNode*)LinkList_Get(node->child, i);
			subHeight = recursive_height(trNode);
			if (ret < subHeight)
				ret = subHeight;
		}
		ret = ret + 1;
	}

	return ret;
}

static void recursive_delete(LinkList* list, GTreeNode* node)
{
	if ((list != NULL) && (node != NULL))
	{
		GTreeNode* parent = node->parent;
		int index = -1;
		int i = 0;

		//����֯����ɾ��
		for (i = 0; i < LinkList_Length(list); i++)
		{
			GTreeNode* trNode = (GTreeNode*)LinkList_Get(list, i);

			if (trNode == node)
			{
				LinkList_Delete(list, i);
				index = i;
				break;
			}
		}

		//�Ӹ������ӽ��������ɾ��
		if (index >= 0)
		{
			if (parent != NULL)
			{
				for (i = 0; i < LinkList_Length(parent->child); i++)
				{
					GTreeNode* trNode = (GTreeNode*)LinkList_Get(parent->child, i);
				
					if (trNode == node)
					{
						LinkList_Delete(parent->child, i);
						break;
					}
				
				}
			}
		}

		while (LinkList_Length(node->child)>0)
		{
			GTreeNode* trNode = (GTreeNode*)LinkList_Get(node->child, 0);

			recursive_delete(list, trNode);
		}

		LinkList_Destroy(node->child);

		free(node);
	}
}


//������
Tree* Tree_Create()
{
	return LinkList_Create();
}

//�����Ѿ����ڵ���
void Tree_Destroy(Tree *tree)
{
	Tree_Clear(tree);
	LinkList_Destroy(tree);
}

//���Ѿ����ڵ������
void Tree_Clear(Tree* tree)
{
	Tree_Delete(tree, 0);
}

//�����node���뵽tree�е�posλ�ô��ĸ������
int Tree_Insert(Tree* tree, GTreeData* data, int pos)
{

	//��ȡ�ý���˫�׽ڵ����֯����
	LinkList* list = (LinkList*)tree;
	int ret = (list != NULL)&&(data!=NULL)&&(pos>=0);
	GTreeNode* pNode = (GTreeNode*)LinkList_Get(list, pos);

	if (ret)
	{
		//���õ�ǰ�������
		GTreeNode* cNode = (GTreeNode*)malloc(sizeof(GTreeNode));
		cNode->parent = pNode;
		cNode->data = data;
		cNode->child = LinkList_Create();

		//����������֯����͸����
		if (pNode != NULL)
		{
			LinkList_Insert(pNode->child, cNode, LinkList_Length(pNode->child));
		}
		LinkList_Insert(list, cNode, LinkList_Length(list));
	}
	
	
	return ret;

}



//��tree��posλ�õĽ��ɾ��������
GTreeData* Tree_Delete(Tree* tree, int pos)
{
	GTreeNode* trNode = (GTreeNode*)LinkList_Get(tree, pos);
	GTreeData* ret = NULL;

	if (trNode != NULL)
	{
		ret = trNode->data;

		recursive_delete(tree, trNode);
	}
	return ret;
}

//��tree�е�posλ�ô��Ľ�㷵��
GTreeData* Tree_Get(Tree* tree, int pos)
{

	GTreeData* ret = NULL;

	GTreeNode* node = (GTreeNode*)LinkList_Get(tree, pos);

	if (node != NULL)
	{
		ret = node->data;
	}

	return ret;
}

//����tree�ĸ��ڵ�
GTreeData* Tree_Root(Tree* tree)
{
	GTreeData* ret = NULL;

	GTreeNode* node = (GTreeNode*)LinkList_Get(tree, 0);

	if (node != NULL)
	{
		ret = node->data;
	}

	return ret;
}

//����tree�ĸ߶�
int Tree_Height(Tree* tree)
{
	GTreeNode* node = (GTreeNode*)LinkList_Get(tree, 0);
	int ret = -1;

	if(node!=NULL)
		ret = recursive_height(node);
	return ret;
}

//�������Ľ����
int Tree_Count(Tree* tree)
{
	int ret = -1;
	if (tree != NULL)
	{
		ret = LinkList_Length(tree);
	}

	return ret;
}

//��������������
int Tree_Degree(Tree* tree)
{
	GTreeNode* root = (GTreeNode*)LinkList_Get(tree, 0);
	int ret = -1;
	if(root!=NULL)
	ret = recursive_degree(root);
	return ret;
}
static void recursive_display(GTreeNode* node, GTree_Printf* pFunc,int format,int gap,char div)
{
	int i = 0;
	if (node != NULL)
	{
		for (i = 0; i < format;i++)
		{
			printf("%c", div);
		}
		
       pFunc((Student*)node->data);
		printf("\n");
		for (i = 0; i < LinkList_Length(node->child); i++)
		{
			GTreeNode* trNode = (GTreeNode*)LinkList_Get(node->child, i);
			
			recursive_display(trNode,pFunc,format + gap,gap,div);
		}
	}
}

void GTree_Display(Tree* tree, GTree_Printf* pFunc,int gap,char div)
{

	TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
	if (trNode != NULL)
	{
		recursive_display((GTreeNode*)trNode, pFunc,0,gap,div);
	}

}

