#include "unity.h"
#include "heap.hpp"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    Heap<int> heap(10);

	heap.insert(42);
    TEST_ASSERT(heap[0] == 42);
}

void test_complex1(void) {
    Heap<int> heap(10);

    heap.insert(42);
    heap.insert(12);
    heap.insert(9);
    TEST_ASSERT(heap.removeFirst() == 42);
    TEST_ASSERT(heap.removeFirst() == 12);
    TEST_ASSERT(heap.removeFirst() == 9);
}

void test_complex2(void) {
    Heap<int> heap(10);

    heap.insert(42);
    heap.insert(9);
    heap.insert(12);
    heap.print();
    TEST_ASSERT(heap.removeFirst() == 42);
    heap.print();
    TEST_ASSERT(heap.removeFirst() == 12);
    heap.print();
    TEST_ASSERT(heap.removeFirst() == 9);
    heap.print();
}

void test_complex3(void) {
    Heap<int> heap(10);

    heap.insert(42);
    heap.insert(9);
    heap.insert(32);
    heap.insert(7);
    heap.insert(8);
    heap.insert(20);
    heap.insert(21);
    heap.insert(11);
    heap.insert(19);
    TEST_ASSERT(heap.removeFirst() == 42);
    heap.print();
    TEST_ASSERT(heap.removeFirst() == 32);
    heap.print();
    TEST_ASSERT(heap.removeFirst() == 21);
    heap.print();
    TEST_ASSERT(heap.removeFirst() == 20);
    TEST_ASSERT(heap.removeFirst() == 19);
    TEST_ASSERT(heap.removeFirst() == 11);
    TEST_ASSERT(heap.removeFirst() == 9);
    TEST_ASSERT(heap.removeFirst() == 8);
    TEST_ASSERT(heap.removeFirst() == 7);
}

void test_complex4(void) {
    Heap<int> heap(10);

    heap.insert(9);
    heap.insert(7);
    heap.insert(8);
    heap.insert(21);
    heap.insert(32);
    heap.insert(11);
    heap.insert(19);
    heap.insert(20);
    heap.insert(42);
    heap.insert(1);

    TEST_ASSERT(heap.removeFirst() == 42);
    TEST_ASSERT(heap.removeFirst() == 32);
    TEST_ASSERT(heap.removeFirst() == 21);
    TEST_ASSERT(heap.removeFirst() == 20);
    TEST_ASSERT(heap.removeFirst() == 19);
    TEST_ASSERT(heap.removeFirst() == 11);
    TEST_ASSERT(heap.removeFirst() == 9);
    TEST_ASSERT(heap.removeFirst() == 8);
    TEST_ASSERT(heap.removeFirst() == 7);
    TEST_ASSERT(heap.removeFirst() == 1);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_complex1);
    RUN_TEST(test_complex2);
    RUN_TEST(test_complex3);
    RUN_TEST(test_complex4);
    return UNITY_END();
}
