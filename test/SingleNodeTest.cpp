#pragma once
#include "../src/classes/SingleNode.hpp"

DataStructures::Node<int> *singleNodeConstructorTestInt(int data) {
    return new DataStructures::SingleNode<int>(data);
}