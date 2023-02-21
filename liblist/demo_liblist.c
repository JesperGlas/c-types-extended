#include "stdio.h"
#include "liblist.h"

int main(int args, char **argv)
{
	printf("Hello world!\n");
	printf("Verbose flag is set to: %d\n", VERBOSE);


	// allocate memory for and initialize a list
	List *lst = initList(3);

	int a[] = {1, 2};
	listExtend(lst, a, 2);

	int b[] = {3, 4, 5, 6, 7, 8};
	listExtend(lst, b, 6);

	listPrint(lst);

	// free lst
	freeList(lst);

	return 0;
}
