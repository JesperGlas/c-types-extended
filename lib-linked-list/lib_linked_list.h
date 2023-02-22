#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#ifndef VERBOSE
#define VERBOSE 0
#endif

/**
 * Struct for each element in the linked list
 *
 * (int) m_data:
 * 	The value of the node
 * (LLNode *) m_next:
 * 	The following node in the list
 * (LLNode *) m_prev:
 * 	The previous node in the list
 * */
typedef struct LLNode
{
	int m_data;
	struct LLNode *m_next;
	struct LLNode *m_prev;
} LLNode;

/**
 * Function for initializing a new node
 *
 * PRE:
 * 	(int) value:
 * 		The value of the node
 * 
 * POST:
 * 	(LLNode *):
 * 		A pointer to the new node struct
 * */
LLNode *lln_init(int value);

/**
 * Function to free the memory allocated by the node.
 *
 * PRE:
 * 	(LLNode *) st_node:
 * 		A pointer to the node struct
 * */
void lln_free(LLNode *st_node);


/**
 * Struct for the linked list
 *
 * (LLNode *) m_head:
 * 	The first element of the list
 * (LLNode *) m_tail:
 * 	The last element of the list
 * (int) m_count:
 * 	How many elements are in the list
 * */
typedef struct LList
{
	struct LLNode *m_head;
	struct LLNode *m_tail;
	int m_count;
} LList;

/**
 * A function for initializing a new linked list
 *
 * POST:
 * 	(LList *):
 * 		A pointer to the newly created list struct
 * */
LList *ll_init();

/**
 * Function for freeing the memory allocated by the linked list
 *
 * PRE:
 * 	(LList *) st_lst:
 * 		A pointer to the list struct
 * */
void ll_free(LList *st_lst);

/**
 * Function to append a value to the list,
 * 	adding it to the end of the list
 *
 * PRE:
 * 	(LList *) lst_st:
 * 		A pointer to the list struct
 * 	(int) value:
 * 		The value that should be added to the list
 * */
void ll_append(LList *st_lst, int value);

/**
 * Function to push a value to the list,
 * 	adding it to the beginning of the list
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list struct
 * 	(int) value:
 * 		The value that should be added to the list
 * */
void ll_push(LList *st_lst, int value);

/**
 * Function to pop a value from the beginning of the list,
 * 	also removes the element.
 *
 * PRE:
 * 	(LList *) st_lst:
 * 		A pointer to the list struct
 *
 * POST:
 * 	(int):
 * 		The value of the removed element
 * */
int ll_pop(LList *st_lst);

/**
 * Function that prints the list
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list struct
 * */
void ll_print(LList *st_lst);

#endif
