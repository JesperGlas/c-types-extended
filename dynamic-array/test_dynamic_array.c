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

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(testInitArray);
	RUN_TEST(testAppend);
	
	return UNITY_END();
}
