#pragma once 

namespace DataStructures {
    template <class T>
    class Node {

        public:
            virtual ~Node() {};
            T data;
        private:

        protected:
            Node(T data) {
                this->data = data;
            };

    };
}