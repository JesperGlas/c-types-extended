#include "stdio.h"
#include "stdlib.h"
#include "liblinkedlist.h"

LLNode *lln_init(int value)
{
	LLNode *st_node = malloc(sizeof(LLNode));
	st_node->m_data = value;
	st_node->m_next = NULL;
	st_node->m_prev = NULL;

	// verbose info
	if (VERBOSE)
	{
		printf("Allocating memory for new node..\n");
		printf("\tEstimate/Actual: %lu/%lu bytes\n", sizeof(LLNode), sizeof(*st_node));
	}

	return st_node;
}

void lln_free(LLNode *st_node)
{
	// verbose info
	if (VERBOSE)
	{
		printf("Freeing memory for node..\n");
		printf("\tEstinmate/Actual: %lu/%lu bytes\n", sizeof(LLNode), sizeof(*st_node));
	}

	free(st_node);

	return;
}

LList *ll_init()
{
	LList *st_lst = malloc(sizeof(LList));
	st_lst->m_head = NULL;
	st_lst->m_tail = NULL;
	st_lst->m_count = 0;

	// verbose info
	if (VERBOSE)
	{
		printf("Allocating memory for new linked list..\n");
		printf("\tEstimate/Actual: %lu/%lu bytes\n", sizeof(LList), sizeof(*st_lst));
	}

	return st_lst;
}

void ll_free(LList *st_lst)
{
	if (st_lst->m_count > 0)
	{
		// set current as first node
		LLNode *current = st_lst->m_head;

		// free all intermediate nodes
		while (current != st_lst->m_tail)
		{
			current = current->m_next;
			lln_free(current->m_prev);
		}

		// free tail node
		lln_free(st_lst->m_tail);
	}

	// verbose info
	if (VERBOSE)
	{
		printf("Freeing memory for linked list..\n");
		printf("\tEstimate/Actual: %lu/%lu bytes\n", sizeof(LList), sizeof(*st_lst));
	}

	// free memory allocated by linked list
	free(st_lst);

	return;
}

void ll_append(LList *st_lst, int value)
{
	// create new node
	LLNode *node= lln_init(value);

	// append node to lst
	if (st_lst->m_count == 0)
	{
		// first element act as both head and tail
		st_lst->m_head = st_lst->m_tail = node;
	}
	else
	{
		// set new node as tail nodes next
		st_lst->m_tail->m_next = node;
		// set new nodes prev as current tail
		node->m_prev = st_lst->m_tail;
		// update tail to new node
		st_lst->m_tail = node;
	}

	// increment list counter
	st_lst->m_count++;

	return;
}

void ll_push(LList *st_lst, int value)
{
	// create a new node
	LLNode *node = lln_init(value);

	// prepend node to list
	if (st_lst->m_count == 0)
	{
		// first element act as both head and tail
		st_lst->m_head = st_lst->m_tail = node;
	}
	else
	{
		// set new node as head nodes prev
		st_lst->m_head->m_prev = node;
		// set new nodes next as current head
		node->m_next = st_lst->m_head;
		// update head to new node
		st_lst->m_head = node;
	}

	// increment list counter
	st_lst->m_count++;

	return;
}

int ll_pop(LList *st_lst)
{
	// return -1 if list is empty
	if (st_lst->m_count <= 0) { return -1; }
	
	// save current head node in temp variable
	LLNode *tmp = st_lst->m_head;

	// one element case
	if (st_lst->m_count == 1)
	{
		st_lst->m_head = st_lst->m_tail = NULL;
	}
	else
	{
		// replace current head with 2nd element in list
		st_lst->m_head = st_lst->m_head->m_next;
		// update new heads previous node
		st_lst->m_head->m_prev = NULL;
	}

	// save value of tmp node before freeing it
	int res = tmp->m_data;

	// free old head node
	lln_free(tmp);

	// decement list counter
	st_lst->m_count--;

	return res;
}

void ll_print(LList *st_lst)
{
	if (st_lst->m_count == 0) { printf("[ ]\n"); }
	else
	{
		LLNode *current = st_lst->m_head;
		printf("[%d", current->m_data);
		while (current != st_lst->m_tail)
		{
			current = current->m_next;
			printf(", %d", current->m_data);
		}
		printf("]\n");
	}
}
