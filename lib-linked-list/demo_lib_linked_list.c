#include "stdio.h"
#include "lib_linked_list.h"

int main()
{
	printf("Hello from demo\n");

	LList *lst = ll_init();

	ll_append(lst, 0);
	ll_append(lst, 1);
	ll_append(lst, 2);
	ll_append(lst, 3);

	ll_print(lst);

	ll_free(lst);

	return 0;
}
