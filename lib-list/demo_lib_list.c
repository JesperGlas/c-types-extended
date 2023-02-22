#include "stdio.h"
#include "lib_list.h"

int main(int args, char **argv)
{
	printf("Hello world!\n");
	printf("Verbose flag is set to: %d\n", VERBOSE);


	// allocate memory for and initialize a list
	List *lst = l_init(5);

	// add two elements and sort it
	l_append(lst, 100);
	l_append(lst, 99);
	l_print(lst);
	l_sort_bubble(lst);
	l_print(lst);

	// populate the list
	int tmp[] = {2, 3, 6, 1, 9, 8, 0, 4, 7, 5};
	l_extend(lst, tmp, 10);
	l_print(lst);

	// sort list
	l_sort_quick(lst);
	l_print(lst);

	// free lst
	l_free(lst);

	return 0;
}
