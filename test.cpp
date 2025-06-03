/*
    Egor Shastin st129457@student.spbu.ru
    This is code for testing all classes by using Google Test
*/


#include "container.h"
#include <gtest/gtest.h>

// Check: empty list
TEST(CircularLinkedListTest, InitiallyEmpty) {
    CircularLinkedList<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

// Check: push_back and front/back
TEST(CircularLinkedListTest, PushBackAndAccess) {
    CircularLinkedList<int> list;
    list.push_back(42);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.front(), 42);
    EXPECT_EQ(list.back(), 42);
}

// Check: push_front and order
TEST(CircularLinkedListTest, PushFrontAndOrder) {
    CircularLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 1);
}

// Check: pop_front
TEST(CircularLinkedListTest, PopFront) {
    CircularLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.pop_front();
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.size(), 1);
}

// Check: remove by value
TEST(CircularLinkedListTest, RemoveValue) {
    CircularLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove(2);
    EXPECT_EQ(list.find(2), -1);
    EXPECT_EQ(list.size(), 2);
}

// Check: insert and at
TEST(CircularLinkedListTest, InsertAndAt) {
    CircularLinkedList<int> list;
    list.push_back(1);
    list.push_back(3);
    list.insert(1, 2);  // insert between 1 and 3
    EXPECT_EQ(list.at(1), 2);
}

// Check: erase by index
TEST(CircularLinkedListTest, EraseIndex) {
    CircularLinkedList<int> list = {1, 2, 3};
    list.erase(1);
    EXPECT_EQ(list.at(1), 3);
    EXPECT_EQ(list.size(), 2);
}

// Check: iteration
TEST(CircularLinkedListTest, Iteration) {
    CircularLinkedList<int> list = {10, 20, 30};
    int sum = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 60);
}

// Check: copy constructor
TEST(CircularLinkedListTest, CopyConstructor) {
    CircularLinkedList<int> original = {1, 2, 3};
    CircularLinkedList<int> copy = original;
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(copy.front(), 1);
    EXPECT_EQ(copy.back(), 3);
    EXPECT_EQ(copy.at(1), 2);
}

// Check: operator []
TEST(CircularLinkedListTest, BracketOperator) {
    CircularLinkedList<int> list = {5, 6, 7};
    EXPECT_EQ(list[0], 5);
    EXPECT_EQ(list[2], 7);
}

// Check: clear
TEST(CircularLinkedListTest, ClearList) {
    CircularLinkedList<int> list = {1, 2, 3};
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

// Check: swap
TEST(CircularLinkedListTest, SwapLists) {
    CircularLinkedList<int> a = {1, 2};
    CircularLinkedList<int> b = {9, 8, 7};

    a.swap(b);

    EXPECT_EQ(a.size(), 3);
    EXPECT_EQ(a.front(), 9);
    EXPECT_EQ(b.size(), 2);
    EXPECT_EQ(b.front(), 1);
}

// Check: merge
TEST(CircularLinkedListTest, MergeLists) {
    CircularLinkedList<int> a = {1, 2};
    CircularLinkedList<int> b = {3, 4};
    a.merge(b);
    EXPECT_EQ(a.size(), 4);
    EXPECT_TRUE(b.empty());
    EXPECT_EQ(a.back(), 4);
}

// Check: reverse
TEST(CircularLinkedListTest, ReverseList) {
    CircularLinkedList<int> list = {1, 2, 3};
    list.reverse();
    EXPECT_EQ(list.at(0), 3);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 1);
}


// ================= main ===================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
