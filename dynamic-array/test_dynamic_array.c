#include "stdio.h"
#include "unity.h"
#include "dynamic_array.h"

void setUp(void)
{
	printf("Setting up tests..\n");
}

void tearDown(void)
{
	printf("Tearing down tests..\n");
}

void testInitArray(void)
{
	DynamicArray *arr = initDynamicArray(1);
	TEST_ASSERT_EQUAL(size(arr), 1);
}

void testAppend(void)
{
	DynamicArray *arr = initDynamicArray(1);
	TEST_ASSERT_EQUAL(size(arr), 1);
	TEST_ASSERT_EQUAL(count(arr), 0);

	append(arr, 1);
	TEST_ASSERT_EQUAL(size(arr), 1);
	TEST_ASSERT_EQUAL(count(arr), 1);

	append(arr, 2);
	TEST_ASSERT_EQUAL(size(arr), 11);
	TEST_ASSERT_EQUAL(count(arr), 2);
}

void testPop(void)
{
	// init array with 3 items
	DynamicArray *arr = initDynamicArray(1);
	append(arr, 1);
	append(arr, 2);
	append(arr, 3);
	TEST_ASSERT_EQUAL(count(arr), 3);
	
	// test pop at index 1
	int tmp = pop(arr, 1);
	TEST_ASSERT_EQUAL(tmp, 2);
	TEST_ASSERT_EQUAL(count(arr), 2);

	// test pop at inde 1
	tmp = pop(arr, 1);
	TEST_ASSERT_EQUAL(tmp, 3);
	TEST_ASSERT_EQUAL(count(arr), 1);

	// test pop at index 0
	tmp = popFirst(arr);
	TEST_ASSERT_EQUAL(tmp, 1);
	TEST_ASSERT_EQUAL(count(arr), 0);

	// test pop with empty array
	tmp = pop(arr, 0);
	TEST_ASSERT_EQUAL(tmp, -1);
	TEST_ASSERT_EQUAL(count(arr), 0);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testInitArray);
	RUN_TEST(testAppend);
	RUN_TEST(testPop);
	
	return UNITY_END();
}
