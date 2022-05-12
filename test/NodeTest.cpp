#pragma once
#include <gtest/gtest.h>
#include "SingleNodeTest.cpp"
#include "../src/classes/SingleNode.hpp"

TEST(Node, SingleNodeConstructor_Int) {
    DataStructures::Node<int> *node = singleNodeConstructorTestInt(3);
    EXPECT_EQ(node->data, 3);
    EXPECT_EQ(sizeof(node), sizeof(DataStructures::Node<int> *));
}

TEST(Node, SingleNodeDestructor_Next) {
    DataStructures::Node<int> *node1 = singleNodeConstructorTestInt(3);
    DataStructures::Node<int> *node2 = singleNodeConstructorTestInt(4);
    delete node1;
    delete node2;
    EXPECT_EQ(sizeof(node1), sizeof(DataStructures::Node<int> *));
}
