#include "stdio.h"
#include "lib_bst.h"

int main()
{
	printf("Hello from demo..\n");

	BST *tree = bst_init();

	bst_add(tree, 5);
	bst_print(tree);

	bst_free(tree);

	return 0;
}
