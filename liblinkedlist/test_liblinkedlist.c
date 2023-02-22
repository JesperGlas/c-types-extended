#include "stdio.h"
#include "unity.h"
#include "liblinkedlist.h"
#include "unity_internals.h"

void setUp(void) { }

void tearDown(void) { }

void test_ll_init(void)
{
	LList *lst = ll_init();
	
	TEST_ASSERT_EQUAL(0, lst->m_count);
	TEST_ASSERT_NULL(lst->m_head);
	TEST_ASSERT_NULL(lst->m_tail);

	ll_free(lst);
}

void test_ll_append(void)
{
	LList *lst = ll_init();

	ll_append(lst, 0);
	ll_append(lst, 1);

	TEST_ASSERT_EQUAL(2, lst->m_count);
	TEST_ASSERT_EQUAL(0, lst->m_head->m_data);
	TEST_ASSERT_EQUAL(1, lst->m_tail->m_data);

	ll_free(lst);
}

void test_ll_push(void)
{
	LList *lst = ll_init();

	ll_push(lst, 2);
	ll_push(lst, 1);
	ll_push(lst, 0);

	TEST_ASSERT_EQUAL(3, lst->m_count);
	TEST_ASSERT_EQUAL(0, lst->m_head->m_data);
	TEST_ASSERT_EQUAL(2, lst->m_tail->m_data);

	ll_free(lst);
}

void test_ll_pop(void)
{
	LList *lst = ll_init();

	// append 2 values
	ll_append(lst, 0);
	ll_append(lst, 1);
	TEST_ASSERT_EQUAL(2, lst->m_count);
	TEST_ASSERT_EQUAL(0, lst->m_head->m_data);
	TEST_ASSERT_EQUAL(1, lst->m_tail->m_data);

	// pop first element
	TEST_ASSERT_EQUAL(0, ll_pop(lst));
	TEST_ASSERT_EQUAL(1, lst->m_count);

	// pop only element
	TEST_ASSERT_EQUAL(1, ll_pop(lst));
	TEST_ASSERT_EQUAL(0, lst->m_count);

	// pop empty list
	TEST_ASSERT_EQUAL(-1, ll_pop(lst));
	TEST_ASSERT_EQUAL(0, lst->m_count);
}

int main()
{
	UNITY_BEGIN();
	
	RUN_TEST(test_ll_init);
	RUN_TEST(test_ll_append);
	RUN_TEST(test_ll_push);
	RUN_TEST(test_ll_pop);

	return UNITY_END();
}
