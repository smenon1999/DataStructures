#pragma once
#include "BinaryTreeNode.hpp"
#include "LinkedList.hpp"

namespace DataStructures {
    
    template <typename T>
    class BinaryTree {

        public:
            BinaryTree<T>() {
                root = NULL;
                curr = root;
            }

            /**
             * @brief advances curr to the right node of itself
             * 
             */
            void advanceRight() {
                this->resetCurr;
                if (this->curr->right)
                    this->curr = this->curr->right;
            }

            /**
             * @brief advances curr to the right node of itself
             * 
             */
            void advanceLeft() {
                this->resetCurr;
                if (this->curr->left)
                    this->curr = this->curr->left;
            }

            /**
             * @brief resets curr to the root
             * 
             */
            void resetCurr() {
                this->curr = this->root;
            }

            /**
             * @brief gets a pointer to the tree starting one to the right of root
             * 
             * @return BinaryTree<T> the tree on the right side of root
             */
            BinaryTree<T>* getRight() {
                BinaryTree<T> *rightTree;
                rightTree->root = this->root->right;
                return rightTree;
            }

            /**
             * @brief gets a pointer to the tree starting one to the left of root
             * 
             * @return BinaryTree<T> the tree on the left side of root
             */
            BinaryTree<T>* getLeft() {
                BinaryTree<T> *leftTree;
                leftTree->root = this->root->left;
                return leftTree;
            }

            /**
             * @brief checks whether Tree contains data
             * 
             * @return bool true if contains, false otherwise
             */
            bool contains() {
                return false;
            }

            /**
             * @brief inserts a value at the left most leaf Node
             * @param data the data to insert
             * 
             */
            void insertLeft(T data) {
                while (this->curr->left)
                    this->advanceLeft();
                this->curr->left = new BinaryTreeNode(data);
            }

            /**
             * @brief inserts a value at the right most leaf Node
             * 
             */
            void insertRight() {
                while (this->curr->right)
                    this->advanceRight();
                this->curr->right = new BinaryTreeNode(data);
            }

            /**
             * @brief assembles a left tree, root node, and right tree
             * @param left left tree
             * @param right right tree
             * @param root the data at the root node
             */
            void assemble(BinaryTree<T> *left, BinaryTree<T> *right, T root) {
                this->root = new BinaryTreeNode<T>(root);
                this->root->left = left->root;
                this->root->right = right->root;
            }

            /**
             * @brief assembles a left tree, a root node, and right tree
             * @param left left tree
             * @param right left tree
             * @param root the root node
             */
            void assemble(BinaryTree<T> *left, BinaryTree<T> *right, BinaryTreeNode<T> *root) {
                this->root = root;
                this->root->left = left->root;
                this->root->right = right->root;
            }

            /**
             * @brief dissassembles tree ino a left tree and a right tree
             * @param left the left tree
             * @param right the right tree
             * @returns root as data type
             */
            T dissassemble(BinaryTree<T> *&left, BinaryTree<T> *&right) {
                left->root = this->root->left;
                right->root = this->root->right;
                return this->root->data;
            }

            /**
             * @brief dissassembles tree ino a left tree and a right tree
             * @param left the left tree
             * @param right the right tree
             * @returns root as a binary tree node
             */
            BinaryTreeNode<T>* dissassemble(BinaryTree<T> *&left, BinaryTree<T> *&right) {
                left->root = this->root->left;
                right->root = this->root->right;
                return this->root;
            }

            /**
             * @brief in order traversal of the tree
             * @returns in order traversal as a linkedlist of nodes
             */
            LinkedList<T>* inOrderTraversal() {
                LinkedList<T> *leftList = new LinkedList();
                LinkedList<T> *rightList = new LinkedList();

                T data = this->root->data;

                if (this->root->left)
                    leftList = this->root->left->inOrderTraversal();
                if (this->root->right)
                    rightList = this->root->right->inOrderTraversal();

                leftList->pushBack(data);
                leftList->append(rightList);

                return leftList;
            }

            /**
             * @brief pre order traversal of the tree
             * @returns the preorder traversal as a linkedlist of nodes
             */
            LinkedList<T>* preOrderTraversal() {
                LinkedList<T> *list = new LinkedList();
                LinkedList<T> *leftList = new LinkedList();
                LinkedList<T> *rightList = new LinkedList();

                if (this->root->left)
                    leftList = this->root->left->preOrderTraversal();
                
                if (this->root->right)
                    rightList = this->root->right->preOrderTraversal();

                list->pushBack(this->root);
                list->append(leftList);
                list->append(rightList);
                
                return list;
            }

            /**
             * @brief post order traversal of the tree
             * @returns post order traversal as a linkedlist of nodes
             */
            LinkedList<T>* postOrderTraversal() {
                LinkedList<T> *list = new LinkedList();
                LinkedList<T> *leftList = new LinkedList();
                LinkedList<T> *rightList = new LinkedList();

                if (this->root->left)
                    leftList = this->root->left->postOrderTraversal();
                
                if (this->root->right)
                    rightList = this->root->right->postOrderTraversal();

                return list
            }

 
            

        private:
            BinaryTreeNode<T> *root;
            BinaryTreeNode<T> *curr;
        protected:
    };
}