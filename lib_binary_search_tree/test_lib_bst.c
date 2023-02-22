#include "stdio.h"
#include "unity.h"
#include "unity_internals.h"
#include "lib_bst.h"

void setUp() { }
void tearDown() { }

void test_bst_init(void)
{
	BST *tree = bst_init();
	TEST_ASSERT_EQUAL(0, tree->m_count);
	TEST_ASSERT_NULL(tree->m_root);

	bst_free(tree);
}

void test_bst_add(void)
{
	BST *tree = bst_init();
	TEST_ASSERT_EQUAL(0, tree->m_count);
	TEST_ASSERT_NULL(tree->m_root);

	// add a root node
	bst_add(tree, 5);
	TEST_ASSERT_EQUAL(1, tree->m_count);

	// add 3 additional nodes
	bst_add(tree, 2);
	bst_add(tree, 1);
	bst_add(tree, 9);
	TEST_ASSERT_EQUAL(4, tree->m_count);

	bst_print(tree);

	bst_free(tree);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_bst_init);
	RUN_TEST(test_bst_add);

	return UNITY_END();
}
