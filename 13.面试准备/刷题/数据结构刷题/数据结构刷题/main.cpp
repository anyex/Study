/*
把二元查找树变成排序的双向链表

输入一棵二元查找树，将该二元查找树转换成为一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向

      10
  6        14
4  8     12  16

4->6->8->10->12->14->16
*/
#include "stdio.h"
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef struct tag_BTreeNode BTreeNode;
 struct tag_BTreeNode
{
	int m_value;
	BTreeNode* left;
	BTreeNode* right;
};

 


 typedef struct tag_BTree {
	 BTreeNode* root;
	 int n;
 }BTree;
 //转换后的链表的头尾结点
 BTreeNode* head = NULL, *tail = NULL;
 BTree* BTree_Creat(void)
 {
	 BTree *tree = new BTree;
	 if (tree != NULL)
	 {
		 tree->n = 0;
		 tree->root = NULL;
	 }

	 return tree;

 }

 void rescurse_Insert(BTreeNode*parent,BTreeNode* node,int flag,int v)
 {
	 if (node == NULL)
	 {
		 node = (BTreeNode*)malloc(sizeof(BTreeNode));
		 node->m_value = v;
		 node->left = NULL;
		 node->right = NULL;

		 if (flag)
		 {
			 parent->right = node;
		 }
		 else
			 parent->left = node;
		 

		 return;
	 }

	 if (v > node->m_value)
	 {
		 
		 rescurse_Insert(node,node->right, 1,v);
	 }
	 if (v < node->m_value)
	 {
		 rescurse_Insert(node,node->left,0, v);
	 }
	 if (v == node->m_value)
	 {
		 return;
	 }


 }

 BTree* BTree_Insert(BTree* tree,int v)
 {
	 if (tree != NULL)
	 {
		 BTreeNode* r = tree->root;
		 if (r == NULL)
		 {
			 tree->root = new BTreeNode;
			 r = tree->root;
			 r->left = NULL;
			 r->right = NULL;
			 r->m_value = v;
		 }
		 else
		 {
			 rescurse_Insert(r, r,0,v);
		 }
		
	 }
	 return tree;
 }



 void BTree_Print(BTree* tree)
 {
	 BTreeNode* root = tree->root;
	 queue<BTreeNode*> q;
	 q.push(root);
	 while (!q.empty())
	 {
		 BTreeNode* ret = q.front();
		 q.pop();
		 
		 if (ret->left != NULL)
		 {
			 q.push(ret->left);
		 }
		 if (ret->right != NULL)
		 {
			 q.push(ret->right);
		 }

		 printf("%d\t", ret->m_value);
	 }
 }
 //设置结点指针
 //pNode为当前结点，pLast为链表的尾结点
 BTreeNode* convertNode(BTreeNode* pNode, BTreeNode* pLast)
 {
	 if (pNode == NULL)
	 {
		 return NULL;
	 }
	 BTreeNode* pCur = pNode;
	 //递归处理左子树
	 if (pCur->left != NULL)
	 {
		 pLast = convertNode(pNode->left, pLast);
	  }
	 //处理当前结点，将当前结点的左指针指向已经转换好的链表的最后一个位置
	 pCur->left = pLast;
	 //将已经转换好的链表的最后一个结点的右指针指向当前结点
	 if (pLast != NULL)
		 pLast->right = pCur;
	 //更新已经转换好的链表的最后一个结点
	 pLast = pCur;

	 //递归处理右子树
	 if (pCur->right != NULL)
	 {
		 pLast = convertNode(pNode->right, pLast);
	 }

	 return pLast;
 }

 /*
转换成链表
 */
 BTreeNode* convert(BTreeNode* root)
 {
	 if (root == NULL)
	 {
		 return NULL;
	 }
	 //处理二叉搜索树
	 BTreeNode* pLast = NULL;//链表尾结点
	 pLast = convertNode(root, pLast);
	 BTreeNode* pHead = pLast;
	 while (pLast!=NULL&&pLast->left!=NULL)
	 {
		 
		 pHead = pHead->left;
		 if (pHead->left == NULL)
			 return pHead;
	 }

	 return pHead;
 }



 int main()
 {
	 BTree* tree = BTree_Creat();
	 BTree_Insert(tree, 10);
	 BTree_Insert(tree, 6);
	 BTree_Insert(tree, 14);
	 BTree_Insert(tree, 16);
	 BTree_Insert(tree, 4);
	 BTree_Insert(tree, 8);
	 BTree_Insert(tree, 10);
	 BTree_Insert(tree, 12);

	// BTree_Print(tree);
	
	 BTreeNode* list = convert(tree->root);


	 return 0;
 }

 /*
 这个可以利用中序遍历(左，根，右).按照这个方式遍历的树，结点比较小的先访问。
 如果我们每访问一个结点，假设之前访问过的结点已经调整成一个排序双链表，我们再把
 调整当前结点的指针将其连接到链表的末尾。当所有的结点都访问过之后，整棵树也就转换完成了

 */