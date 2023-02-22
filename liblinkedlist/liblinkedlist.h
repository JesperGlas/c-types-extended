#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#ifndef VERBOSE
#define VERBOSE 1
#endif

typedef struct LLNode
{
	int m_data;
	struct LLNode *m_next;
	struct LLNode *m_prev;
} LLNode;

LLNode *lLNodeInit(int value);
void lLNodeFree(LLNode *node);

typedef struct LList
{
	struct LLNode *m_head;
	struct LLNode *m_tail;
	int m_count;
} LList;

void testLib();

LList *lListInit();
void lListFree(LList *lst);
void lListAppend(LList *lst, int value);
int lListPop(LList *lst);

void lListPrint(LList *lst);

#endif
