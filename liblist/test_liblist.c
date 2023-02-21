#include "stdio.h"
#include "unity.h"
#include "liblist.h"

void setUp(void)
{
	printf("Setting up tests..\n");
}

void tearDown(void)
{
	printf("Tearing down tests..\n");
}

void testInitList(void)
{
	List *lst = initList(1);
	TEST_ASSERT_EQUAL(1, listSize(lst));

	freeList(lst);
}

void testListAppend(void)
{
	List *lst = initList(1);
	TEST_ASSERT_EQUAL(1, listSize(lst));
	TEST_ASSERT_EQUAL(0, listCount(lst));

	listAppend(lst, 1);
	TEST_ASSERT_EQUAL(1, listSize(lst));
	TEST_ASSERT_EQUAL(1, listCount(lst));

	listAppend(lst, 2);
	TEST_ASSERT_EQUAL(11, listSize(lst));
	TEST_ASSERT_EQUAL(2, listCount(lst));

	freeList(lst);
}

void testListExtend(void)
{
	List *lst = initList(5);
	TEST_ASSERT_EQUAL(5, listSize(lst));
	TEST_ASSERT_EQUAL(0, listCount(lst));

	int a[] = {0, 1, 2, 3, 4};
	listExtend(lst, a, 5);
	TEST_ASSERT_EQUAL(5, listSize(lst));
	TEST_ASSERT_EQUAL(5, listCount(lst));

	int b[] = {5, 6, 7};
	listExtend(lst, b, 3);
	TEST_ASSERT_EQUAL(18, listSize(lst));
	TEST_ASSERT_EQUAL(8, listCount(lst));

	freeList(lst);
}

void testlistPop(void)
{
	// init lstay with 3 items
	List *lst = initList(1);

	listAppend(lst, 1);
	listAppend(lst, 2);
	listAppend(lst, 3);
	TEST_ASSERT_EQUAL(3, listCount(lst));
	
	// test listPop at index 1
	int tmp = listPop(lst, 1);
	TEST_ASSERT_EQUAL(2, tmp);
	TEST_ASSERT_EQUAL(2, listCount(lst));

	// test listPop at inde 1
	tmp = listPop(lst, 1);
	TEST_ASSERT_EQUAL(3, tmp);
	TEST_ASSERT_EQUAL(1, listCount(lst));

	// test listPop at index 0
	tmp = listPopFirst(lst);
	TEST_ASSERT_EQUAL(1, tmp);
	TEST_ASSERT_EQUAL(0, listCount(lst));

	// test listPop with empty lstay
	tmp = listPop(lst, 0);
	TEST_ASSERT_EQUAL(-1, tmp);
	TEST_ASSERT_EQUAL(0, listCount(lst));

	freeList(lst);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testInitList);
	RUN_TEST(testListAppend);
	RUN_TEST(testlistPop);
	RUN_TEST(testListExtend);
	
	return UNITY_END();
}
