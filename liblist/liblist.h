#ifndef __LIST_H__
#define __LIST_H__

#define VERBOSE 0

typedef struct List
{
	int m_size;
	int m_ptr;
	int *m_data;
} List;

List *initList(int);
void freeList(List *);

int listSize(List *);
int listCount(List *);
void listPrint(List *);
void listInfo(List *);

void listAppend(List *, int);
int listPop(List *, int);
int listPopFirst(List *);

#endif
