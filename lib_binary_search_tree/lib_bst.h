#ifndef __BST_H__
#define __BST_H__

#ifndef VERBOSE
#define VERBOSE 1
#endif

typedef struct BSTNode
{
	unsigned int m_leaf : 1;
	struct BSTNode *m_left;
	struct BSTNode *m_right;
	int m_data;
} BSTNode;

BSTNode *bstn_init(int value);
void bstn_free(BSTNode *st_node);

typedef struct BST
{
	int m_count;
	struct BSTNode *m_root;
} BST;

BST *bst_init();
void bst_free(BST *st_tree);
void bst_add(BST *st_tree, int value);
void bst_print(BST *st_tree);

#endif
