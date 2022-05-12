#pragma once
#include "../src/classes/LinkedList.hpp"

DataStructures::LinkedList<int> *linkedListConstructorTestInt() {
    return new DataStructures::LinkedList<int>();
}