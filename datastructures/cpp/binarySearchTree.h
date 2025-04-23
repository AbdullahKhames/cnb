#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "queue"
#include "base.h"
template <class T>
class BinarySearchTreeNode{
    private:
        T data;
        BinarySearchTreeNode *left;
        BinarySearchTreeNode *right;
    public:
        BinarySearchTreeNode(T data): data(data), left(nullptr), right(nullptr) {}
        BinarySearchTreeNode(T data, BinarySearchTreeNode *left, BinarySearchTreeNode *right): data(data), left(left), right(right) {}
        T getData() { return this->data;}
        BinarySearchTreeNode * getLeft() { return this->left;}
        BinarySearchTreeNode * getRight() { return this->right;}
        void setData(T data) { this->data = data;}
        void setLeft(BinarySearchTreeNode *node) { this->left = node;}
        void setRight(BinarySearchTreeNode *node) { this->right = node;}
};

template <class T>
class ParentAndNode{
    public:
        ParentAndNode(BinarySearchTreeNode<T> *node): node(node), parent(nullptr), isLeft(false) {}
        ParentAndNode(bool left, BinarySearchTreeNode<T> *parent, BinarySearchTreeNode<T> *node): isLeft(left), parent(parent), node(node) {}
        BinarySearchTreeNode<T> *parent;
        BinarySearchTreeNode<T> *node;
        bool isLeft;
};

template <class T>
class BinarySearchTree{
    private:
        int height(BinarySearchTreeNode<T> *node);
        void preOrderTraversal(BinarySearchTreeNode<T> *node);
        void postOrderTraversal(BinarySearchTreeNode<T> *node);
        void inOrderTraversal(BinarySearchTreeNode<T> *node);
        BinarySearchTreeNode<T> * find(BinarySearchTreeNode<T> *node, T key);
        BinarySearchTreeNode<T> * findBottomRightNode(BinarySearchTreeNode<T> *node);
        BinarySearchTreeNode<T> * findParent(BinarySearchTreeNode<T> *root, BinarySearchTreeNode<T> *node);
        void deleteNodeBST_TwoChilds(BinarySearchTreeNode<T> *nodeToDelete);
        void deleteNodeBST_OneChilds(BinarySearchTreeNode<T> *nodeToDelete);
        void deleteNodeBST_ZeroChilds(ParentAndNode<T> *foundParentAndNode);
        BinarySearchTreeNode<T> *root;
    public:
        void Balance();
        void InOrderToArray(BinarySearchTreeNode<T> *node, vector<T> &nodes);
        BinarySearchTreeNode<T> *RecursiveBalance(int start, int end, vector<T> &nodes);
        ParentAndNode<T> * findParentAndNode(T key);
        BinarySearchTree(): root(nullptr){}
        BinarySearchTree(BinarySearchTreeNode<T> *root): root(root){}
        BinarySearchTreeNode<T> * getRoot() { return this->root;}
        void setRoot(BinarySearchTreeNode<T> *node) { this->root = node;}
        void insert(T data);
        void print();
        void preOrderTraversal();
        void postOrderTraversal();
        void inOrderTraversal();
        void deleteNode(T key);
        void deleteNodeBST(T key);
        ParentAndNode<T> * inOrderSuccessor(BinarySearchTreeNode<T> *node);
        BinarySearchTreeNode<T> * find(T key);
        BinarySearchTreeNode<T> * findIterative(T key);
        int height();
        void print(const std::string& prefix, BinarySearchTreeNode<T>* node, bool isLeft);
};

void playWithBinarySearchTree();

#endif
