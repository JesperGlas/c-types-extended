#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "liblist.h"

/* ### PRIVATE HELP FUNCTIONS ### */
static void swap(int *a, int *b)
{
	// dereference first value and save as temporary
	int tmp = *a;
	// set value at ptr a to value at ptr b
	*a = *b;
	// set value at ptr b to value of tmp (old value at a)
	*b = tmp;
}

List *l_init(int size)
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

void l_free(List *lst)
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

int l_size(List *lst)
{
	return lst->m_size;
}

int l_count(List *lst)
{
	return lst->m_ptr;
}

void l_print(List *lst)
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

void l_info(List *lst)
{
	printf("### LIST INFO ###\n");
	printf("Count/Size: %d/%d\n", lst->m_ptr, lst->m_size);
	printf("Data:\n");
	l_print(lst);
	printf("### END ###\n");
}

void l_append(List *lst, int value)
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

	// increment pointer to next empty index
	lst->m_ptr++;
}

void l_extend(List *lst, int values[], int values_count)
{
	int new_count = lst->m_ptr + values_count;

	// check if all new values fit in existing list
	//	allocate more memory and move data if not
	if (lst->m_size < new_count)
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

	// index for the new values array
	int i = 0;
	// run until all new values are added, i.e. when ptr reaches empty element
	while (lst->m_ptr < new_count) {
		// add new value at ptr
		lst->m_data[lst->m_ptr] = values[i];
		// increment list ptr and new value array index
		lst->m_ptr++;
		i++;
	}
}

int l_pop_at(List *lst, int index)
{
	// check index out of bounds
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

int l_pop(List *lst)
{
	return l_pop_at(lst, 0);
}

void l_sort_bubble(List *lst)
{
	// verbose info, counts swaps
	int swaps = 0;

	// make sure list has atleast 2 elements
	if (lst->m_ptr < 2)
		return;

	// set a variable for how many elements the list contains
	int n = lst->m_ptr;

	// sorting phase (outer loop)
	for (int i = 0; i < (n - 1); i++)
	{
		// sorting phase (inner loop)
		for (int j = 0; j < (n - i - 1); j++)
		{
			// comparison phase
			if (lst->m_data[j] > lst->m_data[j+1])
			{
				// swaping phase
				swap(&lst->m_data[j], &lst->m_data[j+1]);
				swaps++;

			} // end comparison phase

		} // end inner loop

	} // end outer loop
	
	// verbose info
	if (VERBOSE)
	{
		printf("Bubblesorted in %d swaps.\n", swaps);
	}
} // end l_sort_Bubble

void l_sort_insertion(List *lst)
{
	// verbose info, counts swaps
	int swaps = 0;

	// make sure list has atleast 2 elements
	if (lst->m_ptr < 2)
		return;

	// set a variable for how many elements the list contains
	int n = lst->m_ptr;

	// sorting phase, incrementing from index 0 (outer loop)
	for (int i = 1; i < n; i++)
	{
		// save value at current i
		int tmp = lst->m_data[i];

		// variable for inner loop index, start from element before index i
		int j = i - 1;

		// sorting phase, decrementing from i-1 towards 0 (inner loop
		while (j >= 0 && lst->m_data[j] > tmp)
		{
			// move all elements forward in list to make room for tmp insertion
			lst->m_data[j+1] = lst->m_data[j];
			swaps++;
			
			// decrement inner loop index
			j--;

		} // end of inner loope

		// re-insert tmp value in list at duplicated element
		lst->m_data[j+1] = tmp;
		swaps++;

	} // end of outer loop
	
	// verbose info
	if (VERBOSE)
	{
		printf("Insertion Sort in %d swaps.\n", swaps);
	}
} // end of listInsertionSort

void l_sort_selection(List *lst)
{
	// verbose info, counts swaps
	int swaps = 0;

	// make sure list has atleast 2 elements
	if (lst->m_ptr < 2)
		return;

	// set variable for how many elements the list contains
	int n = lst->m_ptr;

	// sorting phase, incrementing from index 0 (outer loop)
	for (int i = 0; i < n; i++)
	{
		// variable to the smallest value of the inner loop
		int *smallest = &lst->m_data[i];

		// sorting phase, incrementing from i+1 (inner loop)
		for (int j = (i + 1); j < n; j++)
		{
			// comparison phase (element at j and dereferenced smallest)
			if (lst->m_data[j] < *smallest)
			{
				smallest = &lst->m_data[j];
			} // end of comparsion
		} // end of inner loop
		
		// swap current value at i with smallest value of unsorted
		swap(&lst->m_data[i], smallest);
		swaps++;
	} // end of outer loop
	
	// verbose info
	if (VERBOSE)
	{
		printf("Selection Sort in %d swaps.\n", swaps);
	}
} // end of l_sort_Selection

static int aux_sort_around_pivot(List *lst, int low, int high)
{
	// nothing to sort if high and low are equal
	if (low == high)
		return low;

	// set index for lowest unsorted element
	int i = low;

	// set last element at high index as pivot value
	int pivot = lst->m_data[high];

	// sorting phase loop
	for (int j = low; j <= high; j++)
	{
		// if element at index j is less or equal to pivot value
		if (lst->m_data[j] <= pivot)
		{
			// swap elem[j] with first unsorted element and increment i
			swap(&lst->m_data[i], &lst->m_data[j]);
			i++;
		}
	} // end loop
	
	// return i - 1 to compensate for last i increment
	return (i - 1);
}

static void aux_sort_quick(List *lst, int low, int high)
{
	// only sort if low index not equal high index
	if (low < high)
	{
		// find pivot point between high and low
		int pivot = aux_sort_around_pivot(lst, low, high);

		// sort both sides of pivot recursively
		aux_sort_quick(lst, low, (pivot - 1));
		aux_sort_quick(lst, (pivot + 1), high);
	}
} // end of aux_sort_quick

void l_sort_quick(List *lst)
{
	// make sure list has at least two elements
	if (lst->m_ptr < 2)
		return;

	// set variable for list length
	int n = lst->m_ptr;

	// sort list recursively
	aux_sort_quick(lst, 0, (n - 1));
}
