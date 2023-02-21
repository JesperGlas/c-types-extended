#ifndef __LIST_H__
#define __LIST_H__

// verbose flag for memory information in terminal
#ifndef VERBOSE
#define VERBOSE 0
#endif

/**
 * Struct for the dynamic List class.
 *
 *	m_size:
 *		Holds information about the current allocated memory
 *		size of the list
 *
 *	m_ptr:
 *		Holds the index of the next element past the last one
 *		added
 *
 *	*m_data:
 *		Pointer to the data in the list. A new pointer will be
 *		generated if the list grows to large, and the data will
 *		be copied over.
 * */
typedef struct List
{
	int m_size;
	int m_ptr;
	int *m_data;
} List;

/**
 * Function to initialize a new list of a specified size.
 *
 * PRE:
 *	(int) size:
 *		The initial size of the list. It determines
 *		how much memory is allocated for data.
 *
 * POST:
 *	(List *)
 *		Returns a pointer to the newly initialized List struct
 * */
List *initList(int size);

/**
 * Function to free up all memory allocated by the List.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list that is beeing freed.
 * */
void freeList(List *lst);

/**
 * Function to get the current size of the list,
 *	i.e. how many elements it can hold
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 *
 * POST:
 *	(int):
 *		Returns how many elements it can hold with
 *		its current memory allocation.
 * */
int listSize(List *lst);

/**
 * Function to get how many elements are currently in the list.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 *
 * POST:
 *	(int):
 *		Number of elements currently in the list.
 * */
int listCount(List *lst);

/**
 * Function to print the content of the list.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 * */
void listPrint(List *lst);

/**
 * Function to print information about the list such as:
 *	capacity, count and content.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 * */
void listInfo(List *lst);

/**
 * Function to append a value to a list.
 *	The function automatically allocates
 *	additional memory if needed.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 *	(int) value:
 *		Takes an integer value to add to the list.
 * */
void listAppend(List *lst, int value);

/**
 * Function to append multiple values to a list.
 *	The function automatically allocates new memory
 *	if needed.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 *	(int[]) values:
 *		Takes an array of new values to be
 *		appended to the list.
 *	(int) values_count:
 *		Takes an integer representing how many
 *		new values are to be added to the list.
 * */
void listExtend(List *lst, int values[], int values_size);

/**
 * Function to pop a value from the list at a given index.
 *
 * PRE:
 *	(List *) lst:
 *		Takes a pointer to the list.
 *	(int) index:
 *		Takes an integer representing the index
 *		of the value that is to be popped.
 *
 * POST:
 *	(int):
 *		Returns the value at the given index.
 *		Out of bounds returns -1.
 * */
int listPop(List *lst, int index);
int listPopFirst(List *lst);

/**
 * Functions that sorts the list using the bubble sort algorithm
 * PRE:
 *	(List *) lst:
 *		The list that is to be sorted.
 * */
void listSortBubble(List *lst);

#endif
