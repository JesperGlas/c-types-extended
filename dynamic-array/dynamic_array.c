#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dynamic_array.h"

DynamicArray *initDynamicArray(int size)
{
	// allocating memory for struct
	DynamicArray *arr = malloc(sizeof(DynamicArray));

	// verbose info
	if (VERBOSE)
	{
		printf(	"Allocating memory for struct DynamicArray..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(DynamicArray),
			sizeof(*arr) );
	}

	// initializing helper variables
	arr->m_size = size;
	arr->m_ptr = 0;

	// allocating memory for data
	arr->m_data = malloc(arr->m_size * sizeof(int));

	// verbose info
	if (VERBOSE)
	{
		printf(	"Allocating memory for array data..\n");
		printf(	"\tActual: (%d*%lu) %lu bytes\n",
			arr->m_size,
			sizeof(int),
			arr->m_size * sizeof(int) );
	}

	return arr;
}

void freeDynamicArray(DynamicArray *arr)
{
	// free memory of data
	free(arr->m_data);

	// verbose info
	if (VERBOSE)
	{
		printf( "Freeing memory of array data..\n");
		printf(	"\tActual: (%d*%lu) %lu bytes\n",
			arr->m_size,
			sizeof(int),
			arr->m_size * sizeof(int) );
	}

	// free memory of struct
	free(arr);

	// verbose info
	if (VERBOSE)
	{
		printf(	"Freeing memory for struct DynamicArray..\n");
		printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
			sizeof(DynamicArray),
			sizeof(*arr) );
	}
}

int size(DynamicArray *arr)
{
	return arr->m_size;
}

int count(DynamicArray *arr)
{
	return arr->m_ptr;
}

void print(DynamicArray *arr)
{
	if (0 < arr->m_ptr)
	{
		printf("[%d", arr->m_data[0]);
		for (size_t i = 1; i < arr->m_ptr; i++)
		{
			printf(", %d", arr->m_data[i]);
		}
		printf("]\n");
	}
}

void info(DynamicArray *arr)
{
	printf("### ARRAY INFO ###\n");
	printf("Count/Size: %d/%d\n", arr->m_ptr, arr->m_size);
	printf("Data:\n");
	print(arr);
	printf("### END ###\n");
}

void append(DynamicArray *arr, int value)
{
	// if pointer exceeds size, allocate larger array
	if (arr->m_ptr >= arr->m_size)
	{
		// verbose info
		if (VERBOSE)
			printf("Expanding array..\n");

		// save old size for memcpy, update size
		int oldSize = arr->m_size;
		arr->m_size += 10;

		// save old pointer to data for memcpy, allocate new memory
		int *tmp = arr->m_data;
		arr->m_data = malloc(arr->m_size * sizeof(int));

		// verbose info
		if (VERBOSE)
		{
			printf(	"Allocating memory for additional data..\n");
			printf(	"\tActual: (%d*%lu) %lu bytes\n",
				arr->m_size,
				sizeof(int),
				arr->m_size * sizeof(int) );
		}

		// copy over data
		for (size_t i = 0; i < arr->m_ptr; i++)
		{
			arr->m_data[i] = tmp[i];
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
	arr->m_data[arr->m_ptr] = value;

	// increment pointer to last element
	arr->m_ptr++;
}

int pop(DynamicArray *arr, int index)
{
	if (index < 0 || index >= arr->m_ptr)
	{
		printf("WARNING: Index out of bounds, returning -1\n");
		return -1;
	}

	// save value at index
	int tmp = arr->m_data[index];
	
	// decrement ptr
	arr->m_ptr--;

	// move all elements after pop back
	for (int i = index; i < arr->m_ptr; i++)
	{
		arr->m_data[i] = arr->m_data[i+1];
	}

	// set value at ptr to 0
	arr->m_data[arr->m_ptr] = 0;

	return tmp;
}

int popFirst(DynamicArray *arr)
{
	return pop(arr, 0);
}
