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
	
	TEST_ASSERT_EQUAL(listSize(lst), 1);

	freeList(lst);
}

void testListAppend(void)
{
	List *lst = initList(1);

	TEST_ASSERT_EQUAL(listSize(lst), 1);
	TEST_ASSERT_EQUAL(listCount(lst), 0);

	listAppend(lst, 1);
	TEST_ASSERT_EQUAL(listSize(lst), 1);
	TEST_ASSERT_EQUAL(listCount(lst), 1);

	listAppend(lst, 2);
	TEST_ASSERT_EQUAL(listSize(lst), 11);
	TEST_ASSERT_EQUAL(listCount(lst), 2);

	freeList(lst);
}

void testlistPop(void)
{
	// init lstay with 3 items
	List *lst = initList(1);

	listAppend(lst, 1);
	listAppend(lst, 2);
	listAppend(lst, 3);
	TEST_ASSERT_EQUAL(listCount(lst), 3);
	
	// test listPop at index 1
	int tmp = listPop(lst, 1);
	TEST_ASSERT_EQUAL(tmp, 2);
	TEST_ASSERT_EQUAL(listCount(lst), 2);

	// test listPop at inde 1
	tmp = listPop(lst, 1);
	TEST_ASSERT_EQUAL(tmp, 3);
	TEST_ASSERT_EQUAL(listCount(lst), 1);

	// test listPop at index 0
	tmp = listPopFirst(lst);
	TEST_ASSERT_EQUAL(tmp, 1);
	TEST_ASSERT_EQUAL(listCount(lst), 0);

	// test listPop with empty lstay
	tmp = listPop(lst, 0);
	TEST_ASSERT_EQUAL(tmp, -1);
	TEST_ASSERT_EQUAL(listCount(lst), 0);

	freeList(lst);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testInitList);
	RUN_TEST(testListAppend);
	RUN_TEST(testlistPop);
	
	return UNITY_END();
}
