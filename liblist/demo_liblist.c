#include "stdio.h"
#include "liblist.h"

int main(int args, char **argv)
{
	printf("Hello world!\n");
	printf("Verbose flag is set to: %d\n", VERBOSE);


	// allocate memory for and initialize a list
	List *lst = initList(3);

	listAppend(lst, 0);
	listPrint(lst);
	listAppend(lst, 1);
	listPrint(lst);
	listAppend(lst, 2);
	listPrint(lst);
	listAppend(lst, 3);
	listPrint(lst);
	listAppend(lst, 4);
	listPrint(lst);
	listAppend(lst, 5);
	listPrint(lst);

	listPop(lst, 2);
	listPrint(lst);

	// free lst
	freeList(lst);

	return 0;
}
