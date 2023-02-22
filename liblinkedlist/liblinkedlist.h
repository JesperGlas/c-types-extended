#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#ifndef VERBOSE
#define VERBOSE 1
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
 * 		A pointer to the new node
 * */
LLNode *lLNodeInit(int value);

/**
 * Function to free the memory allocated by the node.
 *
 * PRE:
 * 	(LLNode *) node:
 * 		A pointer to the node
 * */
void lLNodeFree(LLNode *node);


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
 * 		A pointer to the newly created list
 * */
LList *lListInit();

/**
 * Function for freeing the memory allocated by the linked list
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list
 * */
void lListFree(LList *lst);

/**
 * Function to append a value to the list,
 * 	adding it to the end of the list
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list
 * 	(int) value:
 * 		The value that should be added to the list
 * */
void lListAppend(LList *lst, int value);

/**
 * Function to push a value to the list,
 * 	adding it to the beginning of the list
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list
 * 	(int) value:
 * 		The value that should be added to the list
 * */
void lListPush(LList *lst, int value);

/**
 * Function to pop a value from the beginning of the list,
 * 	also removes the element.
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list
 *
 * POST:
 * 	(int):
 * 		The value of the removed element
 * */
int lListPop(LList *lst);

/**
 * Function that prints the list
 *
 * PRE:
 * 	(LList *) lst:
 * 		A pointer to the list
 * */
void lListPrint(LList *lst);

#endif
