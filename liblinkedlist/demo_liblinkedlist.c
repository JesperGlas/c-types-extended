#include "stdio.h"
#include "liblinkedlist.h"

int main()
{
	printf("Hello from demo\n");
	testLib();

	LList *lst = lListInit();

	lListAppend(lst, 0);
	lListAppend(lst, 1);
	lListAppend(lst, 2);
	lListAppend(lst, 3);

	lListPrint(lst);

	lListFree(lst);

	return 0;
}
