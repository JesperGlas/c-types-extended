#include "stdio.h"
#include "dynamic_array.h"

int main(int args, char **argv)
{
	printf("Hello world!\n");

	// allocate memory for and initialize a dynamic array
	DynamicArray *arr = initDynamicArray(3);

	append(arr, 0);
	print(arr);
	append(arr, 1);
	print(arr);
	append(arr, 2);
	print(arr);
	append(arr, 3);
	print(arr);
	append(arr, 4);
	print(arr);
	append(arr, 5);
	print(arr);

	pop(arr, 2);
	print(arr);

	// free arr
	freeDynamicArray(arr);

	return 0;
}
