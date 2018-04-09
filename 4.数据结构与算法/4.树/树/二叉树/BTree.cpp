#include "BTree.h"

typedef struct _tag_TBTree TBTree;
typedef struct _tag_TBTreeNode TBTreeNode;
struct _tag_TBTreeNode {
	TBTreeNode* left;
	TBTreeNode* right;
	BTreeData* data;
};
struct _tag_TBTree
{
	int count;//结点个数
	TBTreeNode* root;
};
//前序遍历
static void recursive_front(TBTreeNode* root, BTree_Printf* pFunc)
{
	if (root != NULL)
	{
		pFunc(root->data);
		if (root->left != NULL)
		{
			recursive_front(root->left, pFunc);
		}
		if (root->right != NULL)
		{
			recursive_front(root->right, pFunc);
		}
	}
}
//中序遍历
static void recursive_middle(TBTreeNode* root, BTree_Printf* pFunc)
{
	if (root != NULL)
	{
		
		if (root->left != NULL)
		{
			recursive_front(root->left, pFunc);
		}
		pFunc(root->data);
		if (root->right != NULL)
		{
			recursive_front(root->right, pFunc);
		}
	}
}
//后序遍历
static void recursive_behand(TBTreeNode* root, BTree_Printf* pFunc)
{
	if (root != NULL)
	{

		if (root->left != NULL)
		{
			recursive_front(root->left, pFunc);
		}
	
		if (root->right != NULL)
		{
			recursive_front(root->right, pFunc);
		}
		pFunc(root->data);
	}
}
static int recursive_degree(TBTreeNode* root)
{
	int ret = 0;
	if (root != NULL)
	{
		if (root->left != NULL)
		{
			ret++;
		}

		if (root->right != NULL)
		{
			ret++;
		}

		if (ret == 1)
		{
			int ld = recursive_degree(root->left);
			int rd = recursive_degree(root->right);

			if (ret < ld)
			{
				ret = ld;
			}

			if (ret < rd)
			{
				ret = rd;
			}
		}
	}

	return ret;
}
static int recursive_height(TBTreeNode* root)
{
	int ret = -1;
	if (root != NULL)
	{
		int subHeight = 0;
		subHeight = recursive_height(root->left)+1;
		if (ret < subHeight)
		{
			ret = subHeight;
		}
		subHeight = recursive_height(root->right) + 1;
		if (ret < subHeight)
		{
			ret = subHeight;
		}
	}

	return ret;
}
//子树的结点数
static int recursive_count(TBTreeNode* root)
{
	int ret = 0;
	if (root != NULL)
	{
		ret = recursive_count(root->left) + recursive_count(root->right) + 1;
	}

	return ret;
}

//打印二叉树

static void recursive_print(TBTreeNode* node, BTree_Printf* pFunc, int format, int gap,char div)
{
	int i = 0;
	if ((node != NULL) && (pFunc != NULL))
	{
		for (i = 0; i < format; i++)
		{
			printf("%c", div);
		}
		pFunc(node->data);
		recursive_print(node->left, pFunc, format - gap, gap, div);
		
		recursive_print(node->right, pFunc, format + gap, gap, div);
		printf("\n");
	}
	
}


BTree* BTree_Create()
{
	TBTree* ret = (TBTree*)malloc(sizeof(TBTree));
	if (ret != NULL)
	{
		ret->count = 0;
		ret->root = NULL;

	}
	return ret;

}

void BTree_Destroy(BTree* tree)
{
	free(tree);
}

void BTree_Clear(BTree* tree)
{
	TBTree* btree = (TBTree*)tree;
	if (btree != NULL)
	{
		btree->count = 0;
		btree->root = NULL;
	}

}
// 将结点node插入到BTree中的pos位置处, count为左转右转的次数，flag
int BTree_Insert(BTree* tree, BTreeData* data, BTPos pos, int count, int flag)
{
	TBTree* btree = (TBTree*)tree;
	TBTreeNode* node = (TBTreeNode*)malloc(sizeof(TBTreeNode));
	int bit = 0;
	int ret =(btree != NULL) &&(node != NULL)&&((flag==BT_LEFT)||(flag==BT_RIGHT));
	if (ret)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		TBTreeNode* cur = (TBTreeNode*)btree->root;
		TBTreeNode* parent = NULL;

		//根据路径寻找到指定的位置
		while ((count > 0) && (cur != NULL))
		{
			bit = pos & 1;
			pos = pos >> 1;

			parent = cur;
			if (bit == BT_LEFT)
			{
				cur = cur->left;
			}
			else if (bit == BT_RIGHT)
			{
				cur = cur->right;
			}

			count--;
		}
		//将当前结点的子树插入到node1
		  if(flag == BT_LEFT)
		  { 
			 node->left = cur;
		  }
		  else if(flag == BT_RIGHT)
		  {
			  node->right = cur;
		  }
		  //将插入的结点放入父结点
		  if (parent != NULL)
		  {
			  if (bit == BT_LEFT)
				  parent->left = node;
			  else if (bit == BT_RIGHT)
				  parent->right = node;
		  }
		  else
			  btree->root = node;
		  
		
	}

	btree->count++;
	return ret;
}

BTreeData* BTree_Delete(BTree* tree, BTPos pos, int count)
{
	BTreeData* ret = NULL;
	TBTree* btree = (TBTree*)tree;
	if ((pos >= 0) && (count >= 0))
	{
		TBTreeNode* cur = btree->root;
		TBTreeNode* parent = cur;
		int bit = 0;
		while ((cur != NULL) && (count >= 0))
		{
			parent = cur;
			bit = pos & 1;
			pos = pos >> 1;

			if (bit == BT_RIGHT)
				cur = cur->left;
			else if (bit = BT_LEFT)
				cur = cur->left;
			count--;
		}
			if (parent != NULL)
			{
				if (bit == BT_LEFT)
					parent->left = NULL;
				else if (bit == BT_RIGHT)
					parent->right =NULL;
			}
			else
				btree->root = NULL;
			ret = cur->data;
			btree->count -= recursive_count(cur);
	}
	
	return ret;

}

BTreeData* BTree_Get(BTree* tree, BTPos pos, int count)
{
	BTreeData* ret = NULL;
	TBTree* btree = (TBTree*)tree;
	if ((pos >= 0) && (count >= 0))
	{
		TBTreeNode* cur = btree->root;
		TBTreeNode* parent = cur;
		int bit = 0;
		while ((cur != NULL) && (count >= 0))
		{
			parent = cur;
			bit = pos & 1;
			pos = pos >> 1;

			if (bit == BT_RIGHT)
				cur = cur->left;
			else if (bit = BT_LEFT)
				cur = cur->left;
			count--;
		}
		if(cur!=NULL)
		ret = cur->data;
	}

	return ret;
}

BTreeData* BTree_Root(BTree* tree)
{
	TBTree* btree = (TBTree*)tree;
	TBTreeNode* ret = NULL;
	if (btree != NULL)
	{
		ret = btree->root;
	}

	return ret;
}

int BTree_Height(BTree* tree)
{
	TBTree* btree = (TBTree*)tree;
	int ret = -1;
	if (btree != NULL)
	{
		ret = recursive_height(btree->root);
	}
	return ret;
}

int BTree_Count(BTree* tree)
{
	int ret = -1;
	TBTree* BTree = (TBTree*)tree;
	if (BTree != NULL)
	{
		ret =BTree->count;
	}
	return ret;
}


int BTree_Degree(BTree* tree)
{
	TBTree* btree = (TBTree*)tree;
	int ret = 0;
	if (btree != NULL)
	{
		ret = recursive_degree(btree->root);
	}
	return ret;
}

void BTree_Display(BTree* tree, BTree_Printf* pFunc, int gap, char div)
{
	TBTree* ret = (TBTree*)tree;
	if (ret != NULL)
	{
		recursive_print(ret->root, pFunc, 20, gap, div);
	}
}

//前序遍历二叉树
void BTree_Front(BTree* tree, BTree_Printf* pFunc)
{
	TBTree* btree = (TBTree*)tree;
	if (btree != NULL)
	{
		recursive_front(btree->root,pFunc);
	}

}



//中序遍历二叉树
void BTree_Middle(BTree* tree, BTree_Printf* pFunc)
{
	TBTree* btree = (TBTree*)tree;
	if (btree != NULL)
	{
		recursive_middle(btree->root, pFunc);
	}

}
//后序遍历二叉树
void BTree_Behand(BTree* tree, BTree_Printf* pFunc)
{
	TBTree* btree = (TBTree*)tree;
	if (btree != NULL)
	{
		recursive_behand(btree->root, pFunc);
	}
}
//按层遍历二叉树
void BTree_Level(BTree* tree, BTree_Printf* pFunc)
{
	TBTreeNode* last = NULL;//当前遍历层的最右结点
	TBTreeNode* nlast = NULL;//下一层的最右结点
	TBTree* ret = (TBTree*)tree;
	LinkQueue* queue = LinkQueue_Create();//创建一个队列
	
	LinkQueue_Append(queue, ret->root);
	last = ret->root;
	nlast = ret->root;

	while (LinkQueue_Length(queue)>0)
	{
		TBTreeNode* t = (TBTreeNode*)LinkQueue_Retrieve(queue);
		if(t!=NULL)
		pFunc(t->data);
		if (t->left != NULL)
		{
			LinkQueue_Append(queue, t->left);
			nlast = t->left;
		}
		if (t->right != NULL)
		{
			LinkQueue_Append(queue, t->right);
			nlast = t->right;
		}
		if (last == t)
		{
			last = nlast;
			printf("\n");
		}
	}


}