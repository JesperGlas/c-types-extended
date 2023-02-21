#ifndef __LIST_H__
#define __LIST_H__

#define VERBOSE 1

typedef struct List
{
	int m_size;
	int m_ptr;
	int *m_data;
} List;

List *initList(int size);
void freeList(List *lst);

int listSize(List *lst);
int listCount(List *lst);
void listPrint(List *lst);
void listInfo(List *lst);

void listAppend(List *lst, int value);
void listExtend(List *lst, int values[], int values_size);
int listPop(List *lst, int index);
int listPopFirst(List *lst);

#endif
