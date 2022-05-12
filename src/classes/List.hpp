#pragma once
#include <string>

namespace DataStructures {
    template <typename T>
    class List {
        public:
           /**
             * @brief inserts data at front of list
             * @param data the data to insert
             */
            virtual void pushFront(T) = 0;

            /**
             * @brief inserts data at position, if position is greater than size, inserts at the back
             * @param data data to insert
             * @param pos position to insert at
             * @returns -1 on failure, 0 on success
             */
            virtual int insert(T, int) = 0;

            /**
             * @brief inserts data at back of list
             * @param data the data to insert
             */
            virtual void pushBack(T) = 0;

            
            /**
             * @brief removes data at specified position and returns the value
             * @param pos specified position
             * @returns the removed data
             */
            virtual T remove(int) = 0;

            /**
             * @brief removes data from the front of the list and returns value
             * @returns the removed data
             */
            virtual T popFront() = 0;

            /**
             * @brief removes data from the rear of the list and returns value
             * @returns the removed data
             */
            virtual T popBack() = 0;

            /**
             * @brief gets data at position; if position is greater than size, return last element; if position is less than 0, get first element
             * @param pos the position
             * @return the data at that position
             */
            virtual T at(int) = 0;

            /**
             * @brief gets object at front of list
             * 
             * @return T object at front of list
             */
            virtual T front() = 0;

            /**
             * @brief gets object at back of list
             * @return T object at back of list
             */
            virtual T back() = 0;

            /**
             * @brief appends LinkedList to end of list
             * @param list the list to add
             */
            virtual void append(List<T>*) = 0;


            /**
             * @brief formats linked list as string
             * 
             * @return the formatted string
             */
            //virtual std::string to_string() = 0;

            /**
             * @brief returns the size of the list
             * @return the size of the list
             */
            virtual int getSize() {
                return this->size;
            };
        private:
        protected:
            // List<T>() {
            //     this->size = 0;
            // };
            List<T>() {
                this->size = 0;
            };
            
            List<T>(List<T> *copy) {
                this->size = copy->getSize();
            }


            virtual ~List<T>() {}

            int size;
    };
}