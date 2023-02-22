#include "stdio.h"
#include "unity.h"
#include "liblist.h"

void setUp(void) { }

void tearDown(void) { }

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

// helper function to test a sorting algorithm
static void testListSortTemplate(void (*sort_func)(List *))
{
	// init a list
	int n = 10;
	List *lst = initList(n);

	// fill list
	int tmp[] = {2, 3, 6, 1, 9, 8, 0, 4, 7, 5};
	listExtend(lst, tmp, 10);
	TEST_ASSERT_EQUAL(n, listSize(lst));
	TEST_ASSERT_EQUAL(n, listCount(lst));

	// sort list
	sort_func(lst);
	TEST_ASSERT_EQUAL(n, listSize(lst));
	TEST_ASSERT_EQUAL(n, listCount(lst));

	// make sure list is sorted
	for (int i = 0; i < (n - 1); i++)
	{
		// expects (lesser, greater)
		TEST_ASSERT_GREATER_THAN(lst->m_data[i], lst->m_data[i+1]);
	}

	// free list memory
	freeList(lst);
}

// test various sorting algorithms using a template testing function
void testListSortBubble(void) { testListSortTemplate(listSortBubble); }
void testListSortInsertion(void) { testListSortTemplate(listSortInsertion); }
void testListSortSelection(void) { testListSortTemplate(listSortSelection); }
void testListSortQuick(void) { testListSortTemplate(listSortQuick); }

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testInitList);
	RUN_TEST(testListAppend);
	RUN_TEST(testlistPop);
	RUN_TEST(testListExtend);
	RUN_TEST(testListSortBubble);
	RUN_TEST(testListSortInsertion);
	RUN_TEST(testListSortSelection);
	RUN_TEST(testListSortQuick);
	
	return UNITY_END();
}
