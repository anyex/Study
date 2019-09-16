/*
�Ѷ�Ԫ��������������˫������

����һ�ö�Ԫ�����������ö�Ԫ������ת����Ϊһ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��

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
 //ת����������ͷβ���
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
 //���ý��ָ��
 //pNodeΪ��ǰ��㣬pLastΪ�����β���
 BTreeNode* convertNode(BTreeNode* pNode, BTreeNode* pLast)
 {
	 if (pNode == NULL)
	 {
		 return NULL;
	 }
	 BTreeNode* pCur = pNode;
	 //�ݹ鴦��������
	 if (pCur->left != NULL)
	 {
		 pLast = convertNode(pNode->left, pLast);
	  }
	 //����ǰ��㣬����ǰ������ָ��ָ���Ѿ�ת���õ���������һ��λ��
	 pCur->left = pLast;
	 //���Ѿ�ת���õ���������һ��������ָ��ָ��ǰ���
	 if (pLast != NULL)
		 pLast->right = pCur;
	 //�����Ѿ�ת���õ���������һ�����
	 pLast = pCur;

	 //�ݹ鴦��������
	 if (pCur->right != NULL)
	 {
		 pLast = convertNode(pNode->right, pLast);
	 }

	 return pLast;
 }

 /*
ת��������
 */
 BTreeNode* convert(BTreeNode* root)
 {
	 if (root == NULL)
	 {
		 return NULL;
	 }
	 //�������������
	 BTreeNode* pLast = NULL;//����β���
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
 ������������������(�󣬸�����).���������ʽ�������������Ƚ�С���ȷ��ʡ�
 �������ÿ����һ����㣬����֮ǰ���ʹ��Ľ���Ѿ�������һ������˫���������ٰ�
 ������ǰ����ָ�뽫�����ӵ������ĩβ�������еĽ�㶼���ʹ�֮��������Ҳ��ת�������

 */