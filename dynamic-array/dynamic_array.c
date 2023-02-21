#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dynamic_array.h"

DynamicArray *initDynamicArray(int size)
{
	// allocating memory for struct
	DynamicArray *arr = malloc(sizeof(DynamicArray));
	printf(	"Allocating memory for struct DynamicArray..\n");
	printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
		sizeof(DynamicArray),
		sizeof(*arr) );

	// initializing helper variables
	arr->m_size = size;
	arr->m_ptr = 0;

	// allocating memory for data
	arr->m_data = malloc(arr->m_size * sizeof(int));
	printf(	"Allocating memory for array data..\n");
	printf(	"\tActual: (%d*%lu) %lu bytes\n",
		arr->m_size,
		sizeof(int),
		arr->m_size * sizeof(int) );

	return arr;
}

void freeDynamicArray(DynamicArray *arr)
{
	free(arr->m_data);
	printf( "Freeing memory of array data..\n");
	printf(	"\tActual: (%d*%lu) %lu bytes\n",
		arr->m_size,
		sizeof(int),
		arr->m_size * sizeof(int) );

	free(arr);
	printf(	"Freeing memory for struct DynamicArray..\n");
	printf(	"\tEstimate/Actual: %lu/%lu bytes\n",
		sizeof(DynamicArray),
		sizeof(*arr) );
}

int size(DynamicArray *arr)
{
	return arr->m_size;
}

int count(DynamicArray *arr)
{
	return arr->m_ptr;
}

void append(DynamicArray *arr, int value)
{
	// if pointer exceeds size, allocate larger array
	if (arr->m_ptr >= arr->m_size)
	{
		printf("Expanding array..\n");
		// save old size for memcpy, update size
		int oldSize = arr->m_size;
		arr->m_size += 10;

		// save old pointer to data for memcpy, allocate new memory
		int *tmp = arr->m_data;
		arr->m_data = malloc(arr->m_size * sizeof(int));
		printf(	"Allocating memory for additional data..\n");
		printf(	"\tActual: (%d*%lu) %lu bytes\n",
			arr->m_size,
			sizeof(int),
			arr->m_size * sizeof(int) );

		// copy over data
		for (size_t i = 0; i < arr->m_ptr; i++)
		{
			arr->m_data[i] = tmp[i];
		}
		printf(	"Moving %lu bytes of data..\n",
			oldSize * sizeof(int) );

		// free memory of old data
		free(tmp);
		printf(	"Freeing memory of old data..\n");
		printf(	"\tActual: (%d*%lu) %lu bytes\n",
			oldSize,
			sizeof(int),
			oldSize * sizeof(int) );
	}

	// append new value
	arr->m_data[arr->m_ptr] = value;

	// increment pointer to last element
	arr->m_ptr++;
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
