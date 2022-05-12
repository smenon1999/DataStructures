#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "SingleNode.hpp"
#include "List.hpp"


namespace DataStructures {


    template <typename T>
    class LinkedList: public List<T> {
        public:
            LinkedList() : List<T>() {
                head = NULL;
                curr = head;
            }

            LinkedList(List<T> *copy) : List<T>(copy) {
                this->head = new SingleNode<T>(copy->at(0));
                for (int i = 1; i < copy->getSize(); i++) {
                    this->pushBack(copy->at(i));
                } 
                this->size = copy->getSize();
            }

            virtual ~LinkedList<T>() {
                delete this->head;
            }

            // TODO:
            // Implement iterator


            /**
             * @brief advances curr to the next node
             * 
             */
            void advance() {
                if (this->curr && this->curr->next)
                    this->curr = this->curr->next;
            }


            /**
             * @brief resets curr to head
             * 
             */
            void resetCurr() {
                this->curr = head;
            }

           
            /**
             * Overriden methods from List
             * 
             */
            void pushFront(T data) override {
                SingleNode<T> * newNode = new SingleNode<T>(data);
                newNode->next = this->head;
                this->head = newNode;
                this->size++;
            }

            int insert(T data, int pos) override {
                // create node
                SingleNode<T> *newNode = new SingleNode<T>(data);

                if (pos < 0)
                    return -1;

                if (pos == 0 || this->size == 0) {
                    this->pushFront(data);
                    return 0;
                }

                // reset cursor
                this->resetCurr();

                // advance cursor to position
                for (int i = 1; i < pos; i++)
                    this->advance();

                // insert node and relink
                SingleNode<T> *outer = this->curr->next;
                this->curr->next = newNode;
                newNode->next = outer;
                this->size++;
                return 0;
            }

            void pushBack(T data) override {
                this->insert(data, this->size+1);
            }

            T remove(int pos) override {
                if (pos < 1)
                    this->popFront();
                this->resetCurr();
                // advance to right before desired position
                for (int i = 0; i < pos-1; i++)
                    this->advance();
        
                // get data of next node
                SingleNode<T> *removed = this->curr->next;
                int removedData = removed->data;
                // remove and relink
                SingleNode<T> *newNext = removed->next;
                this->curr->next = newNext;

                delete removed;
                this->size--;
                return removedData;
            }

            T popFront() override {
                SingleNode<T> *front = this->head;
                int data = front->data;
                SingleNode<T> *next = this->head->next;
                this->head = next;
                delete front;
                this->size--;
                return data;
            }

            T popBack() override {
                this->remove(this->size);
            }

            T at(int pos) override {
                this->resetCurr();
                for (int i = 0; i < pos; i++)
                    this->advance();

                return this->curr->data;
            }

            T front() override {
                return this->head->data;
            }

            T back() override {
                this->resetCurr();
                for (int i=0; i<this->size; i++)
                    this->advance();
                return curr->data;
            }

            void append(List<T> *list) override {
                for (int i = 0; i < list->getSize(); i++) {
                    this->pushBack(list->at(i));
                }
            }    


            //virtual std::string to_string() = 0;

        private:
            SingleNode<T> *head;
            SingleNode<T> *curr;

    };
}
