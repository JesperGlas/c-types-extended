#include "stdio.h"
#include "stdlib.h"
#include "liblinkedlist.h"

void testLib()
{
	printf("Hello from lib\n");
}

LLNode *lLNodeInit(int value)
{
	LLNode *node = malloc(sizeof(LLNode));
	node->m_data = value;
	node->m_next = NULL;
	node->m_prev = NULL;

	// verbose info
	if (VERBOSE)
	{
		printf("Allocating memory for new node..\n");
		printf("\tEstimate/Actual: %lu/%lu bytes\n", sizeof(LLNode), sizeof(*node));
	}

	return node;
}

void lLNodeFree(LLNode *node)
{
	// verbose info
	if (VERBOSE)
	{
		printf("Freeing memory for node..\n");
		printf("\tEstinmate/Actual: %lu/%lu bytes\n", sizeof(LLNode), sizeof(*node));
	}

	free(node);

	return;
}

LList *lListInit()
{
	LList *lst = malloc(sizeof(LList));
	lst->m_head = NULL;
	lst->m_tail = NULL;
	lst->m_count = 0;

	// verbose info
	if (VERBOSE)
	{
		printf("Allocating memory for new linked list..\n");
		printf("\tEstimate/Actual: %lu/%lu bytes\n", sizeof(LList), sizeof(*lst));
	}

	return lst;
}

void lListFree(LList *lst)
{
	if (lst->m_count > 0)
	{
		// set current as first node
		LLNode *current = lst->m_head;

		// free all intermediate nodes
		while (current != lst->m_tail)
		{
			current = current->m_next;
			lLNodeFree(current->m_prev);
		}

		// free tail node
		lLNodeFree(lst->m_tail);
	}

	// verbose info
	if (VERBOSE)
	{
		printf("Freeing memory for linked list..\n");
		printf("\tEstimate/Actual: %lu/%lu bytes\n", sizeof(LList), sizeof(*lst));
	}

	free(lst);

	return;
}

void lListAppend(LList *lst, int value)
{
	// create new node
	LLNode *node = lLNodeInit(value);

	// append node to lst
	if (lst->m_count == 0)
	{
		// first element act as both head and tail
		lst->m_head = lst->m_tail = node;
	}
	else
	{
		// set new node as tail nodes next
		lst->m_tail->m_next = node;
		// set new nodes prev as current tail
		node->m_prev = lst->m_tail;
		// update tail to new node
		lst->m_tail = node;
	}

	// increment list counter
	lst->m_count++;

	return;
}

void lListPush(LList *lst, int value)
{
	// create a new node
	LLNode *node = lLNodeInit(value);

	// prepend node to list
	if (lst->m_count ==0)
	{
		// first element act as both head and tail
		lst->m_head = lst->m_tail = node;
	}
	else
	{
		// set new node as head nodes prev
		lst->m_head->m_prev = node;
		// set new nodes next as current head
		node->m_next = lst->m_head;
		// update head to new node
		lst->m_head = node;
	}

	// increment list counter
	lst->m_count++;

	return;
}

int lListPop(LList *lst)
{
	// return -1 if list is empty
	if (lst->m_count <= 0) { return -1; }
	
	// save current head node in temp variable
	LLNode *tmp = lst->m_head;

	// one element case
	if (lst->m_count == 1)
	{
		lst->m_head = lst->m_tail = NULL;
	}
	else
	{
		// replace current head with 2nd element in list
		lst->m_head = lst->m_head->m_next;
		// update new heads previous node
		lst->m_head->m_prev = NULL;
	}

	// save value of tmp node before freeing it
	int res = tmp->m_data;

	// free old head node
	lLNodeFree(tmp);

	// decement list counter
	lst->m_count--;

	return res;
}

void lListPrint(LList *lst)
{
	if (lst->m_count == 0) { printf("[ ]\n"); }
	else
	{
		LLNode *current = lst->m_head;
		printf("[%d", current->m_data);
		while (current != lst->m_tail)
		{
			current = current->m_next;
			printf(", %d", current->m_data);
		}
		printf("]\n");
	}
}
