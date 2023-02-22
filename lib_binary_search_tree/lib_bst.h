#ifndef __BST_H__
#define __BST_H__

typedef struct BSTNode
{
	int m_data;
	struct BSTNode *m_left;
	struct BSTNode *m_right;
} BSTNode;

typedef struct BST
{
	int m_count;
	struct BSTNode *m_root;
} BST;

#endif
