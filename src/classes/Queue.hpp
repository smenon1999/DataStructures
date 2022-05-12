#pragma once
#include "LinkedList.hpp"

namespace DataStructures {

    template <typename T>
    class Queue {
        public:
            /**
             * @brief Construct a new Queue object
             * 
             */
            Queue() {
                kernel = new LinkedList<T>();
            }

            /**
             * @brief Construct a new Queue object as a copy of another Queue
             * 
             * @param copy 
             */
            Queue(Queue<T> *copy) {
                
            }

            /**
             * @brief Construct a new Queue object as a copy of a List
             * 
             * @param copy 
             */
            Queue(List<T> *copy) {
                kernel = new LinkedList<T>(copy);
            }

            /**
             * @brief returns the poll element of the queue
             * 
             * @return T the poll element
             */
            T poll() {
                return kernel->front();
            }

            /**
             * @brief removes and returns the poll element of the queue
             * 
             * @return T the poll element of the queue
             */
            T pop() {
                return kernel->popFront();
            }

            /**
             * @brief adds an element to the end of the queue
             * 
             * @param data the data to add
             */
            void push(T data) {
                kernel->pushBack();
            }

        private:
            List<T> *kernel;
        protected:

    };
}