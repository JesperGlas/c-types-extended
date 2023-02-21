#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

typedef struct DynamicArray
{
	int m_size;
	int m_ptr;
	int *m_data;
} DynamicArray;

DynamicArray *initDynamicArray(int size);
void freeDynamicArray(DynamicArray *arr);
int size(DynamicArray *arr);
int count(DynamicArray *arr);
void append(DynamicArray *arr, int value);
void print(DynamicArray *arr);
void info(DynamicArray *arr);

#endif