#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct LLNode
{
	int data;
	struct LLNode *next;
} LLNode;

typedef struct LList
{
	struct LLNode *m_head;
	struct LLNode *m_tail;
	int m_count;
} LList;

void testLib();

#endif
