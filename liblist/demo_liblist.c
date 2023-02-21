#include "stdio.h"
#include "liblist.h"

int main(int args, char **argv)
{
	printf("Hello world!\n");
	printf("Verbose flag is set to: %d\n", VERBOSE);


	// allocate memory for and initialize a list
	List *lst = initList(5);

	// populate the list
	int tmp[] = {2, 3, 6, 1, 9, 8, 0, 4, 7, 5};
	listExtend(lst, tmp, 10);
	listPrint(lst);

	// sort list
	listSortBubble(lst);
	listPrint(lst);

	// free lst
	freeList(lst);

	return 0;
}
