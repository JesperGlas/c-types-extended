#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "liblist.h"

List *initList(int size)
{
	// allocating memory for struct
	List *lst = malloc(sizeof(List));

	// verbose info
	if (VERBOSE)
	{
		printf(	"Allocating memory for struct List..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(List),
			sizeof(*lst) );
	}

	// initializing helper variables
	lst->m_size = size;
	lst->m_ptr = 0;

	// allocating memory for data
	lst->m_data = malloc(lst->m_size * sizeof(int));

	// verbose info
	if (VERBOSE)
	{
		printf(	"Allocating memory for list data..\n");
		printf(	"\tActual: (%d*%lu) %lu bytes\n",
			lst->m_size,
			sizeof(int),
			lst->m_size * sizeof(int) );
	}

	return lst;
}

void freeList(List *lst)
{
	// free memory of data
	free(lst->m_data);

	// verbose info
	if (VERBOSE)
	{
		printf( "Freeing memory of list data..\n");
		printf(	"\tActual: (%d*%lu) %lu bytes\n",
			lst->m_size,
			sizeof(int),
			lst->m_size * sizeof(int) );
	}

	// free memory of struct
	free(lst);

	// verbose info
	if (VERBOSE)
	{
		printf(	"Freeing memory for struct List..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(List),
			sizeof(*lst) );
	}
}

int listSize(List *lst)
{
	return lst->m_size;
}

int listCount(List *lst)
{
	return lst->m_ptr;
}

void listPrint(List *lst)
{
	if (0 < lst->m_ptr)
	{
		printf("[%d", lst->m_data[0]);
		for (size_t i = 1; i < lst->m_ptr; i++)
		{
			printf(", %d", lst->m_data[i]);
		}
		printf("]\n");
	}
}

void listInfo(List *lst)
{
	printf("### LIST INFO ###\n");
	printf("Count/Size: %d/%d\n", lst->m_ptr, lst->m_size);
	printf("Data:\n");
	listPrint(lst);
	printf("### END ###\n");
}

void listAppend(List *lst, int value)
{
	// if pointer exceeds size, allocate larger array
	if (lst->m_ptr >= lst->m_size)
	{
		// verbose info
		if (VERBOSE)
			printf("Expanding list..\n");

		// save old size for memcpy, update size
		int oldSize = lst->m_size;
		lst->m_size += 10;

		// save old pointer to data for memcpy, allocate new memory
		int *tmp = lst->m_data;
		lst->m_data = malloc(lst->m_size * sizeof(int));

		// verbose info
		if (VERBOSE)
		{
			printf(	"Allocating memory for additional data..\n");
			printf(	"\tActual: (%d*%lu) %lu bytes\n",
				lst->m_size,
				sizeof(int),
				lst->m_size * sizeof(int) );
		}

		// copy over data
		for (size_t i = 0; i < lst->m_ptr; i++)
		{
			lst->m_data[i] = tmp[i];
		}

		// verbose info
		if (VERBOSE)
		{
			printf(	"Moving %lu bytes of data..\n",
				oldSize * sizeof(int) );
		}

		// free memory of old data
		free(tmp);

		// verbose info
		if (VERBOSE)
		{
			printf(	"Freeing memory of old data..\n");
			printf(	"\tActual: (%d*%lu) %lu bytes\n",
				oldSize,
				sizeof(int),
				oldSize * sizeof(int) );
		}
	}

	// append new value
	lst->m_data[lst->m_ptr] = value;

	// increment pointer to last element
	lst->m_ptr++;
}

void listExtend(List *lst, int values[], int values_count)
{
	int new_count = lst->m_ptr + values_count;

	// check if all new values fit in existing list
	// allocate more memory and move data if not
	if (lst->m_size <= new_count)
	{
		// save old pointer to data and old size
		int *tmp = lst->m_data;
		int old_size = lst->m_size;

		// set new size of list (place for all data and additional 10 elements)
		lst->m_size = new_count + 10;

		// allocate new memory
		lst->m_data = malloc( lst->m_size * sizeof(int));

		// verbose info
		if (VERBOSE)
		{
			printf("Expanding list..\n");
			printf("Allocating memory for additional data..\n");
			printf(	"\tActual: (%d*%lu) %lu\n",
				lst->m_size,
				sizeof(int),
				lst->m_size * sizeof(int) );
		}

		// copying old data to new address
		for (int i = 0; i < lst->m_ptr; i++)
		{
			lst->m_data[i] = tmp[i];
		}
		
		// free up old data
		free(tmp);

		// verbose info
		if (VERBOSE)
		{
			printf("Freeing memory of old data..\n");
			printf(	"\tActual: (%d*%lu) %lu bytes\n",
				old_size,
				sizeof(int),
				old_size * sizeof(int) );
		}
	}

	// copying new data
	int i = 0;
	while (lst->m_ptr < new_count) {
		lst->m_data[lst->m_ptr] = values[i];
		lst->m_ptr++;
		i++;
	}
}

int listPop(List *lst, int index)
{
	if (index < 0 || index >= lst->m_ptr)
	{
		printf("WARNING: Index out of bounds, returning -1\n");
		return -1;
	}

	// save value at index
	int tmp = lst->m_data[index];
	
	// decrement ptr
	lst->m_ptr--;

	// move all elements after pop back
	for (int i = index; i < lst->m_ptr; i++)
	{
		lst->m_data[i] = lst->m_data[i+1];
	}

	// set value at ptr to 0
	lst->m_data[lst->m_ptr] = 0;

	return tmp;
}

int listPopFirst(List *lst)
{
	return listPop(lst, 0);
}
