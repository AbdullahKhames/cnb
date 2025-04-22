#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "queue"
#include "base.h"
template <class T>
class BinaryTreeNode{
    private:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    public:
        BinaryTreeNode(T data): data(data), left(nullptr), right(nullptr) {}
        BinaryTreeNode(T data, BinaryTreeNode *left, BinaryTreeNode *right): data(data), left(left), right(right) {}
        T getData() { return this->data;}
        BinaryTreeNode * getLeft() { return this->left;}
        BinaryTreeNode * getRight() { return this->right;}
        void setData(T data) { this->data = data;}
        void setLeft(BinaryTreeNode *node) { this->left = node;}
        void setRight(BinaryTreeNode *node) { this->right = node;}
};
template <class T>
class BinaryTree{
    private:
        int height(BinaryTreeNode<T> *node);
        void preOrderTraversal(BinaryTreeNode<T> *node);
        void postOrderTraversal(BinaryTreeNode<T> *node);
        void inOrderTraversal(BinaryTreeNode<T> *node);
        BinaryTreeNode<T> * find(BinaryTreeNode<T> *node, T key);
        BinaryTreeNode<T> * findBottomRightNode(BinaryTreeNode<T> *node);
        BinaryTreeNode<T> * findParent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *node);
        BinaryTreeNode<T> *root;
    public:
        BinaryTree(): root(nullptr){}
        BinaryTree(BinaryTreeNode<T> *root): root(root){}
        BinaryTreeNode<T> * getRoot() { return this->root;}
        void setRoot(BinaryTreeNode<T> *node) { this->root = node;}
        void insert(T data);
        void print();
        void preOrderTraversal();
        void postOrderTraversal();
        void inOrderTraversal();
        void deleteNode(T key);
        BinaryTreeNode<T> * find(T key);
        int height();
        void print(const std::string& prefix, BinaryTreeNode<T>* node, bool isLeft);
};

void playWithBinaryTree();

#endif
