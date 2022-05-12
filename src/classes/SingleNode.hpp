#pragma once
#include "Node.hpp"



namespace DataStructures {

    template <typename T>
    class SingleNode : public Node<T> {
        public:
            SingleNode<T>(T data) : Node <T> (data) {}
            virtual ~SingleNode() {
                if (this->next)
                    delete this->next;
            };
            SingleNode<T> *next;

        private:

        protected:
    };
}