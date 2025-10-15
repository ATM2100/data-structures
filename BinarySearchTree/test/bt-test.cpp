#include "unity.h"
#include "binarytree.hpp"
#include <iostream>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    BinaryTree<int> bt;

    TEST_ASSERT(bt.contains(0) == false);
    bt.put(0);
    TEST_ASSERT(bt.contains(0) == true);
}

void test_multiple(void) {
    BinaryTree<int> bt;

    TEST_ASSERT(bt.contains(0) == false);
    (bt.put(0));
    (bt.put(1));
    (bt.put(2));
    (bt.put(5));
    (bt.put(3));
    (bt.put(10));
    (bt.put(-5));
    (bt.put(-1));
    (bt.put(-10));
    TEST_ASSERT(bt.contains(0) == true);
    TEST_ASSERT(bt.contains(1) == true);
    TEST_ASSERT(bt.contains(2) == true);
    TEST_ASSERT(bt.contains(3) == true);
    //bt.preorder();
    std::cout << "bt.inorder() " << bt.inorderString() << "\n";
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_multiple);
    return UNITY_END();
}
