#include "Tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"
typedef struct Student {
	char name[20];
	int id;
}Student;
//extern void printStudent(Student* s);
typedef struct  _tag_GTreeNode GTreeNode;//树结点
struct _tag_GTreeNode {
	GTreeData* data;//保存的数据内容
	GTreeNode* parent;//父结点
	LinkList* child;//子结点链表
};

typedef struct _tag_TLNode TLNode;
struct  _tag_TLNode//组织链表
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

		//从组织链表删除
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

		//从父结点的子结点链表中删除
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


//创建树
Tree* Tree_Create()
{
	return LinkList_Create();
}

//销毁已经存在的树
void Tree_Destroy(Tree *tree)
{
	Tree_Clear(tree);
	LinkList_Destroy(tree);
}

//将已经存在的树清空
void Tree_Clear(Tree* tree)
{
	Tree_Delete(tree, 0);
}

//将结点node插入到tree中的pos位置处的父结点下
int Tree_Insert(Tree* tree, GTreeData* data, int pos)
{

	//获取该结点的双亲节点和组织链表
	LinkList* list = (LinkList*)tree;
	int ret = (list != NULL)&&(data!=NULL)&&(pos>=0);
	GTreeNode* pNode = (GTreeNode*)LinkList_Get(list, pos);

	if (ret)
	{
		//设置当前的树结点
		GTreeNode* cNode = (GTreeNode*)malloc(sizeof(GTreeNode));
		cNode->parent = pNode;
		cNode->data = data;
		cNode->child = LinkList_Create();

		//将结点插入组织链表和父结点
		if (pNode != NULL)
		{
			LinkList_Insert(pNode->child, cNode, LinkList_Length(pNode->child));
		}
		LinkList_Insert(list, cNode, LinkList_Length(list));
	}
	
	
	return ret;

}



//将tree中pos位置的结点删除并返回
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

//将tree中的pos位置处的结点返回
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

//返回tree的根节点
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

//返回tree的高度
int Tree_Height(Tree* tree)
{
	GTreeNode* node = (GTreeNode*)LinkList_Get(tree, 0);
	int ret = -1;

	if(node!=NULL)
		ret = recursive_height(node);
	return ret;
}

//返回树的结点数
int Tree_Count(Tree* tree)
{
	int ret = -1;
	if (tree != NULL)
	{
		ret = LinkList_Length(tree);
	}

	return ret;
}

//返回树的最大度数
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

