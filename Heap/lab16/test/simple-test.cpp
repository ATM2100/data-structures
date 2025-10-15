#include "unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    TEST_ASSERT_EQUAL_INT(10, 1);
    TEST_ASSERT(10 == 0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    return UNITY_END();
}
