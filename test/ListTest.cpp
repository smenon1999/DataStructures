#pragma once
#include <gtest/gtest.h>
#include <string>
#include "../src/classes/List.hpp"
#include "../src/classes/LinkedList.hpp"
#include "LinkedListTest.cpp"

// ---------- Linked List Tests ----------------
TEST(LinkedList, Constructor_Int) {
    DataStructures::List<int>* list = linkedListConstructorTestInt();
    EXPECT_EQ(sizeof(DataStructures::List<int> *), sizeof(list));
    EXPECT_EQ(list->getSize(), 0);
}

TEST(LinkedList, CopyConstructor_Int) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->pushBack(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushBack(4);
    list->pushBack(5);
    DataStructures::List<int> *list2 = new DataStructures::LinkedList<int>(list);
    EXPECT_EQ(list2->at(0), 1);
    EXPECT_EQ(list2->at(1), 2);
    EXPECT_EQ(list2->at(2), 3);
    EXPECT_EQ(list2->at(3), 4);
    EXPECT_EQ(list2->at(4), 5);
    EXPECT_EQ(list2->getSize(), 5);
}

TEST(LinkedList, InsertAtFront_Empty) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->pushFront(1);
    EXPECT_EQ(list->front(), 1);
    EXPECT_EQ(list->getSize(), 1);
}

TEST(LinkedList, InsertAtFront_NotEmpty) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->pushFront(1);
    list->pushFront(2);
    EXPECT_EQ(list->front(), 2);
    EXPECT_EQ(list->getSize(), 2);
}

TEST(LinkedList, PushBack_Empty) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->pushBack(3);
    EXPECT_EQ(list->back(), 3);
    EXPECT_EQ(list->getSize(), 1);
}

TEST(LinkedList, PushBack_NotEmpty) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->pushBack(3);
    list->pushBack(2);
    list->pushBack(1);
    EXPECT_EQ(list->back(), 1);
    EXPECT_EQ(list->at(0), 3);
    EXPECT_EQ(list->at(1), 2);
    EXPECT_EQ(list->at(2), 1);
    EXPECT_EQ(list->getSize(), 3);
}

TEST(LinkedList, Insert_Empty_0) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->insert(3, 0);
    EXPECT_EQ(list->at(0), 3);
    EXPECT_EQ(list->getSize(), 1);
}

TEST(LinkedList, Insert_Empty_Non0) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->insert(3, 1);
    EXPECT_EQ(list->at(0), 3);
    EXPECT_EQ(list->getSize(), 1);
}

TEST(LinkedList, Insert_NotEmpty_0) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->insert(3, 0);
    list->insert(4, 0);
    EXPECT_EQ(list->at(0), 4);
    EXPECT_EQ(list->getSize(), 2);
}

TEST(LinkedList, Insert_NotEmpty_Non0) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->insert(3, 0);
    list->insert(4, 1);
    EXPECT_EQ(list->at(1), 4);
    EXPECT_EQ(list->getSize(), 2);
}

TEST(LinkedList, Insert_GreaterThanSize) {
    DataStructures::List<int> *list = linkedListConstructorTestInt();
    list->pushBack(1);
    list->pushBack(2);
    list->pushBack(3);
    list->insert(4, 100);
    EXPECT_EQ(list->at(3), 4);
    EXPECT_EQ(list->getSize(), 4);
}

TEST(LinkedList, Append) {
    DataStructures::List<int> *list1 = linkedListConstructorTestInt();
    list1->pushBack(1);
    list1->pushBack(2);
    list1->pushBack(3);
    DataStructures::List<int> *list2 = linkedListConstructorTestInt();
    list2->pushBack(4);
    list2->pushBack(5);
    list2->pushBack(6);
    list1->append(list2);
    EXPECT_EQ(list1->at(0), 1);
    EXPECT_EQ(list1->at(1), 2);
    EXPECT_EQ(list1->at(2), 3);
    EXPECT_EQ(list1->at(3), 4);
    EXPECT_EQ(list1->at(4), 5);
    EXPECT_EQ(list1->at(5), 6);
    EXPECT_EQ(list1->getSize(), 6);
}

TEST(LinkedList, Append_Empty) {
    DataStructures::List<int> *list1 = linkedListConstructorTestInt();
    DataStructures::List<int> *list2 = linkedListConstructorTestInt();
    list2->pushBack(1);
    list2->pushBack(2);
    list1->append(list2);
    EXPECT_EQ(list1->at(0), 1);
    EXPECT_EQ(list1->at(1), 2);
}

// ---------------------------------------------