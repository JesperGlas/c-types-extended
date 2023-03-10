#ifndef __LIST_H__
#define __LIST_H__

// verbose flag for memory information in terminal
#ifndef VERBOSE
#define VERBOSE 1
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
List *l_init(int size);

/**
 * Function to free up all memory allocated by the List.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct.
 * */
void l_free(List *st_lst);

/**
 * Function to get the current size of the list,
 *	i.e. how many elements it can hold
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 *
 * POST:
 *	(int):
 *		Returns how many elements it can hold with
 *		its current memory allocation.
 * */
int l_size(List *st_lst);

/**
 * Function to get how many elements are currently in the list.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 *
 * POST:
 *	(int):
 *		Number of elements currently in the list.
 * */
int l_count(List *st_lst);

/**
 * Function to print the content of the list.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 * */
void l_print(List *st_lst);

/**
 * Function to print information about the list such as:
 *	capacity, count and content.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 * */
void l_info(List *st_lst);

/**
 * Function to append a value to a list.
 *	The function automatically allocates
 *	additional memory if needed.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 *	(int) value:
 *		Takes an integer value to add to the list.
 * */
void l_append(List *st_lst, int value);

/**
 * Function to append multiple values to a list.
 *	The function automatically allocates new memory
 *	if needed.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 *	(int[]) values:
 *		Takes an array of new values to be
 *		appended to the list.
 *	(int) values_count:
 *		Takes an integer representing how many
 *		new values are to be added to the list.
 * */
void l_extend(List *st_lst, int values[], int values_size);

/**
 * Function to pop a value from the list at a given index.
 *
 * PRE:
 *	(List *) st_lst:
 *		Takes a pointer to the list struct
 *	(int) index:
 *		Takes an integer representing the index
 *		of the value that is to be popped.
 *
 * POST:
 *	(int):
 *		Returns the value at the given index.
 *		Out of bounds returns -1.
 * */
int l_pop_at(List *st_lst, int index);
int l_pop(List *st_lst);

/**
 * Functions that sorts the list using the bubble sort algorithm.
 *
 * PRE:
 *	(List *) lst:
 *		Pointer to the list struct
 * */
void l_sort_bubble(List *st_lst);

/**
 * Function that sorts the list using the insertion sort algorithm.
 *
 * PRE:
 *	(List *) st_lst:
 *		Pointer to the list struct
 * */
void l_sort_insertion(List *st_lst);

/**
 * Function that sorts the list using the selection sort algorithm.
 *
 * PRE:
 *	(List *) st_lst:
 *		Pointer to the list struct
 * */
void l_sort_selection(List *st_lst);

/**
 * Function that sorts the list using the quick sort algorithm.
 *
 * PRE:
 *	(List *) lst:
 *		Pointer to the list struct
 * */
void l_sort_quick(List *st_lst);

#endif
