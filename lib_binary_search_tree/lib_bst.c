#include "stdio.h"
#include "stdlib.h"
#include "lib_bst.h"

BSTNode *bstn_init(int value)
{
	// initialize node struct
	BSTNode *st_node = malloc(sizeof(BSTNode));
	st_node->m_data = value;
	st_node->m_leaf = 1;
	st_node->m_left = NULL;
	st_node->m_right = NULL;

	// verbose info
	if (VERBOSE)
	{
		printf("Allocating memory for new node..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(BSTNode),
			sizeof(*st_node) );
	} // verbose info

	// return pointer to node
	return st_node;
}

void bstn_free(BSTNode *st_node)
{
	// break if node is NULL
	if (st_node == NULL) { return; }

	// verbose info
	if (VERBOSE)
	{
		printf("Freeing memory of node..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(BSTNode),
			sizeof(*st_node) );
	} // end verbose infor
	
	// free node memory
	free(st_node);

	return;
}

BST *bst_init()
{
	// initialize tree struct
	BST *st_tree = malloc(sizeof(BST));
	st_tree->m_root = NULL;
	st_tree->m_count = 0;

	// verbose info
	if (VERBOSE)
	{
		printf("Allocating memory for BST..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(BST),
			sizeof(*st_tree) );
	} // end verbose info

	// return pointer to tree
	return st_tree;
}

static void aux_bst_free(BSTNode *st_node)
{
	// break if node is NULL
	if (st_node == NULL) { return; }

	// free node branches/leafs
	aux_bst_free(st_node->m_left);
	aux_bst_free(st_node->m_right);

	// free current node
	bstn_free(st_node);

	return;
}

void bst_free(BST *st_tree)
{
	// break if tree is NULL
	if (st_tree == NULL) { return; }

	// verbose info
	if (VERBOSE)
	{
		printf("Freeing memory of BST..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(BST),
			sizeof(*st_tree) );
	} // end verbose info
	
	// free all nodes
	aux_bst_free(st_tree->m_root);
	
	// free tree memory
	free(st_tree);

	return;
}

static int aux_bst_add(BSTNode *st_node, int value)
{
	// focus on left branch/leaf if value is less than current,
	if (value < st_node->m_data)
	{
		// if left node is NULL,
		if (st_node->m_left == NULL)
		{
			// add new node as left
			st_node->m_left = bstn_init(value);
			// current is no longer a leaf node
			st_node->m_leaf = 0;
			// return success
			return 1;
		} // else pass left node to aux recursively
		return aux_bst_add(st_node->m_left, value);
	}
	// focus on right branch/leaf if value is less than current,
	else if (value > st_node->m_data)
	{
		// if right is NULL,
		if (st_node->m_right == NULL)
		{
			// create new node as right
			st_node->m_right = bstn_init(value);
			// current is no longer leaf node
			st_node->m_leaf = 0;
			// return success
			return 1;
		} // else pass right node to aux recursively
		return aux_bst_add(st_node->m_right, value);
	} // else return failure
	return 0;
}

void bst_add(BST *st_tree, int value)
{
	// no root node means tree is empty,
	if (st_tree->m_root == NULL)
	{
		// add initial node as root
		st_tree->m_root = bstn_init(value);
		// increment tree counter
		st_tree->m_count++;
	} // else pass root node to aux add function,
	
	// if aux returns sucessful add,
	if (aux_bst_add(st_tree->m_root, value))
	{
		// increment tree counter
		st_tree->m_count++;
	}

	return;
}

static void aux_bst_print(BSTNode *st_node)
{
	// break if node is NULL
	if (st_node == NULL) { return; }

	// pass left side (less) to aux print func
	aux_bst_print(st_node->m_left);
	// print current node
	printf(" %d,", st_node->m_data);
	// pass right side (greater) to aux print func
	aux_bst_print(st_node->m_right);

	return;
}

void bst_print(BST *st_tree)
{
	printf("[");
	// pass root node to aux print func
	aux_bst_print(st_tree->m_root);
	printf(" ]\n");
}
