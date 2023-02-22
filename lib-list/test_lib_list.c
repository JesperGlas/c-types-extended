#include "stdio.h"
#include "unity.h"
#include "lib_list.h"

void setUp(void) { }

void tearDown(void) { }

void test_list_init(void)
{
	List *lst = l_init(1);
	TEST_ASSERT_EQUAL(1, l_size(lst));

	l_free(lst);
}

void test_list_append(void)
{
	List *lst = l_init(1);
	TEST_ASSERT_EQUAL(1, l_size(lst));
	TEST_ASSERT_EQUAL(0, l_count(lst));

	l_append(lst, 1);
	TEST_ASSERT_EQUAL(1, l_size(lst));
	TEST_ASSERT_EQUAL(1, l_count(lst));

	l_append(lst, 2);
	TEST_ASSERT_EQUAL(11, l_size(lst));
	TEST_ASSERT_EQUAL(2, l_count(lst));

	l_free(lst);
}

void test_list_extend(void)
{
	List *lst = l_init(5);
	TEST_ASSERT_EQUAL(5, l_size(lst));
	TEST_ASSERT_EQUAL(0, l_count(lst));

	int a[] = {0, 1, 2, 3, 4};
	l_extend(lst, a, 5);
	TEST_ASSERT_EQUAL(5, l_size(lst));
	TEST_ASSERT_EQUAL(5, l_count(lst));

	int b[] = {5, 6, 7};
	l_extend(lst, b, 3);
	TEST_ASSERT_EQUAL(18, l_size(lst));
	TEST_ASSERT_EQUAL(8, l_count(lst));

	l_free(lst);
}

void test_pop(void)
{
	// init lstay with 3 items
	List *lst = l_init(1);

	l_append(lst, 1);
	l_append(lst, 2);
	l_append(lst, 3);
	TEST_ASSERT_EQUAL(3, l_count(lst));
	
	// test l_pop_at at index 1
	int tmp = l_pop_at(lst, 1);
	TEST_ASSERT_EQUAL(2, tmp);
	TEST_ASSERT_EQUAL(2, l_count(lst));

	// test l_pop_at at inde 1
	tmp = l_pop_at(lst, 1);
	TEST_ASSERT_EQUAL(3, tmp);
	TEST_ASSERT_EQUAL(1, l_count(lst));

	// test l_pop_at at index 0
	tmp = l_pop(lst);
	TEST_ASSERT_EQUAL(1, tmp);
	TEST_ASSERT_EQUAL(0, l_count(lst));

	// test l_pop_at with empty lstay
	tmp = l_pop_at(lst, 0);
	TEST_ASSERT_EQUAL(-1, tmp);
	TEST_ASSERT_EQUAL(0, l_count(lst));

	l_free(lst);
}

// helper function to test a sorting algorithm
static void test_list_sort_template(void (*sort_func)(List *))
{
	// init a list
	int n = 10;
	List *lst = l_init(n);

	// fill list
	int tmp[] = {2, 3, 6, 1, 9, 8, 0, 4, 7, 5};
	l_extend(lst, tmp, 10);
	TEST_ASSERT_EQUAL(n, l_size(lst));
	TEST_ASSERT_EQUAL(n, l_count(lst));

	// sort list
	sort_func(lst);
	TEST_ASSERT_EQUAL(n, l_size(lst));
	TEST_ASSERT_EQUAL(n, l_count(lst));

	// make sure list is sorted
	for (int i = 0; i < (n - 1); i++)
	{
		// expects (lesser, greater)
		TEST_ASSERT_GREATER_THAN(lst->m_data[i], lst->m_data[i+1]);
	}

	// free list memory
	l_free(lst);
}

// test various sorting algorithms using a template testing function
void test_list_sort_Bubble(void) { test_list_sort_template(l_sort_bubble); }
void test_list_sort_Insertion(void) { test_list_sort_template(l_sort_insertion); }
void test_list_sort_Selection(void) { test_list_sort_template(l_sort_selection); }
void test_list_sort_Quick(void) { test_list_sort_template(l_sort_quick); }

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_list_init);
	RUN_TEST(test_list_append);
	RUN_TEST(test_pop);
	RUN_TEST(test_list_extend);
	RUN_TEST(test_list_sort_Bubble);
	RUN_TEST(test_list_sort_Insertion);
	RUN_TEST(test_list_sort_Selection);
	RUN_TEST(test_list_sort_Quick);
	
	return UNITY_END();
}
