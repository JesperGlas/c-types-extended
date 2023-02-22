#include "stdio.h"
#include "unity.h"
#include "liblinkedlist.h"
#include "unity_internals.h"

void setUp(void) { }

void tearDown(void) { }

void test_lListInit(void)
{
	LList *lst = lListInit();
	
	TEST_ASSERT_EQUAL(0, lst->m_count);
	TEST_ASSERT_NULL(lst->m_head);
	TEST_ASSERT_NULL(lst->m_tail);

	lListFree(lst);
}

void test_lListAppend(void)
{
	LList *lst = lListInit();

	lListAppend(lst, 0);
	lListAppend(lst, 1);

	TEST_ASSERT_EQUAL(2, lst->m_count);
	TEST_ASSERT_EQUAL(0, lst->m_head->m_data);
	TEST_ASSERT_EQUAL(1, lst->m_tail->m_data);

	lListFree(lst);
}

void test_lListPop(void)
{
	LList *lst = lListInit();

	// append 2 values
	lListAppend(lst, 0);
	lListAppend(lst, 1);
	TEST_ASSERT_EQUAL(2, lst->m_count);
	TEST_ASSERT_EQUAL(0, lst->m_head->m_data);
	TEST_ASSERT_EQUAL(1, lst->m_tail->m_data);

	// pop first element
	TEST_ASSERT_EQUAL(0, lListPop(lst));
	TEST_ASSERT_EQUAL(1, lst->m_count);

	// pop only element
	TEST_ASSERT_EQUAL(1, lListPop(lst));
	TEST_ASSERT_EQUAL(0, lst->m_count);

	// pop empty list
	TEST_ASSERT_EQUAL(-1, lListPop(lst));
	TEST_ASSERT_EQUAL(0, lst->m_count);
}

int main()
{
	UNITY_BEGIN();
	
	RUN_TEST(test_lListInit);
	RUN_TEST(test_lListAppend);
	RUN_TEST(test_lListPop);

	return UNITY_END();
}
