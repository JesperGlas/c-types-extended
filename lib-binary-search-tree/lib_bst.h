#ifndef __BST_H__
#define __BST_H__

#ifndef VERBOSE
#define VERBOSE 1
#endif

/**
 * Struct for the binary search tree node.
 *
 * (u_int) m_leaf:
 *	Flag if node is leaf node, no children (1=true, 0=false)
 * (BSTNode *) m_left:
 *	Pointer to the left child node
 * (BSTNode *) m_right:
 *	Pointer to the right child node
 * (int) m_data:
 *	The data contained in the node
 * */
typedef struct BSTNode
{
	unsigned int m_leaf : 1;
	struct BSTNode *m_left;
	struct BSTNode *m_right;
	int m_data;
} BSTNode;

/**
 * Function to initialize a new node
 *
 * PRE:
 *	(int) value:
 *		The value of the new node
 *
 * POST:
 *	(BSTNode *):
 *		A pointer to the newly created node
 * */
BSTNode *bstn_init(int value);

/**
 * Function to free the memory allocated by a single node
 *
 * PRE:
 *	(BSTNode *) st_node:
 *		A pointer to the node
 * */
void bstn_free(BSTNode *st_node);

/**
 * Struct for the search tree.
 *
 * (BSTNode *) m_root:
 *	A pointer to the trees root node
 * (int) m_count:
 *	Amount of nodes currently in the tree
 * */
typedef struct BST
{
	struct BSTNode *m_root;
	int m_count;
} BST;

/**
 * Function to initialize a new binary search tree.
 *
 * POST:
 *	(BST *)
 *		A pointer to the newly created BST
 * */
BST *bst_init();

/**
 * Function to free the memory allocated to a BST.
 *
 * PRE:
 *	(BST *) st_tree:
 *		A pointer to the BST
 * */
void bst_free(BST *st_tree);

/**
 * Function to add new values to the BST. Won't add duplicates.
 *
 * PRE:
 *	(BST *) st_tree:
 *		A pointer to the BST
 *	(int) value:
 *		The value that should be added
 * */
void bst_add(BST *st_tree, int value);

/**
 * Function to print out the content of the BST to the terminal in order.
 *
 * PRE:
 *	(BST *) st_tree:
 *		A pointer to the BST
 * */
void bst_print(BST *st_tree);

#endif
