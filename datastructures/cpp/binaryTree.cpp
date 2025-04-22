#include "binaryTree.h"

template <class T>
void BinaryTree<T>::insert(T data) {
    BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
    BinaryTreeNode<T> *temp;
    BinaryTreeNode<T> *leftPtr;
    BinaryTreeNode<T> *rightPtr;
    queue<BinaryTreeNode<T> *> queue;
    if (this->getRoot() == nullptr)
    {
        this->setRoot(newNode);
        return;
    }
    queue.push(this->getRoot());
    while (!queue.empty())
    {
        temp = queue.front();
        queue.pop();
        leftPtr = temp->getLeft();
        rightPtr = temp->getRight();
        if (leftPtr == nullptr)
        {
            temp->setLeft(newNode);
            break;
        } else {
            queue.push(leftPtr);
        }
        if (rightPtr == nullptr)
        {
            temp->setRight(newNode);
            break;
        } else {
            queue.push(rightPtr);
        }
    }
}

template <class T>
int BinaryTree<T>::height() {
    return this->height(this->root);
}

template <class T>
int BinaryTree<T>::height(BinaryTreeNode<T>* node) {
    if (!node)
    {
        return 0;
    }
    return 1 + max(height(node->getLeft()), height(node->getRight())); 
    
}

template <class T>
// i copied this from stackoverflow for demonstration!
void BinaryTree<T>::print(const std::string& prefix, BinaryTreeNode<T>* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << node->getData() << std::endl;
        // enter the next tree level - left and right branch
        print(prefix + (isLeft ? "|   " : "    "), node->getRight(), true);
        print(prefix + (isLeft ? "|   " : "    "), node->getLeft(), false);
    }
}

template <class T>
void BinaryTree<T>::print() 
{
    print("", this->root, false);
}




template <class T>
void BinaryTree<T>::preOrderTraversal() {
    cout << "---------------pre order traversal------------------" << endl;
    this->preOrderTraversal(this->root);
    cout << "\n---------------pre order traversal------------------" << endl;

}


template <class T>
void BinaryTree<T>::preOrderTraversal(BinaryTreeNode<T>* node) {
    if (!node)
    {
        return;
    }
    cout << node->getData() << " ";
    preOrderTraversal(node->getLeft());
    preOrderTraversal(node->getRight());
}

template <class T>
void BinaryTree<T>::postOrderTraversal() {
    cout << "---------------post order traversal------------------" << endl;
    this->postOrderTraversal(this->root);
    cout << "\n---------------post order traversal------------------" << endl;

}


template <class T>
void BinaryTree<T>::postOrderTraversal(BinaryTreeNode<T>* node) {
    if (!node)
    {
        return;
    }
    postOrderTraversal(node->getLeft());
    postOrderTraversal(node->getRight());
    cout << node->getData() << " ";
}

template <class T>
void BinaryTree<T>::inOrderTraversal() {
    cout << "---------------in order traversal------------------" << endl;
    this->inOrderTraversal(this->root);
    cout << "\n---------------in order traversal------------------" << endl;

}


template <class T>
void BinaryTree<T>::inOrderTraversal(BinaryTreeNode<T>* node) {
    if (!node)
    {
        return;
    }
    inOrderTraversal(node->getLeft());
    cout << node->getData() << " ";
    inOrderTraversal(node->getRight());
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::find(T key) {
    return this->find(this->root, key);
}


template <class T>
BinaryTreeNode<T> * BinaryTree<T>::find(BinaryTreeNode<T>* node, T key) {
    BinaryTreeNode<T>* temp;
    if (!node)
    {
        return nullptr;
    }
    if (node->getData() == key)
    {
        return node;
    } else {
        temp = this->find(node->getLeft(), key);
        if (temp)
        {
            return temp;
        }
        return this->find(node->getRight(), key);
    }
    

}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::findBottomRightNode(BinaryTreeNode<T> *node) {
    if (!node)
    {
        return nullptr;
    }
    queue<BinaryTreeNode<T> *> queue;
    BinaryTreeNode<T> *temp = nullptr;
    queue.push(node);
    while (!queue.empty())
    {
        temp = queue.front();
        queue.pop();
        if (temp->getRight())
        {
            queue.push(temp->getRight());
        }
    }
    return temp;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::findParent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *node) {
    if (!node || !root)
    {
        return nullptr;
    }
    queue<BinaryTreeNode<T> *> queue;
    BinaryTreeNode<T> *temp = nullptr;
    queue.push(root);
    while (!queue.empty())
    {
        temp = queue.front();
        queue.pop();
        if (temp->getRight() == node)
        {
            return temp;
        } else {
            queue.push(temp->getRight());
        }
        // if (temp->getLeft() == node)
        // {
        //     return temp;
        // } else {
        //     queue.push(temp->getLeft());
        // }
    }
    return temp;
}


template <class T>
void BinaryTree<T>::deleteNode(T key) {
    BinaryTreeNode<T> *nodeToDelete = this->find(this->root, key);
    BinaryTreeNode<T> *rightBottomNode = this->findBottomRightNode(this->root);
    BinaryTreeNode<T> *rightBottomParentNode = this->findParent(this->root, rightBottomNode);

    if (nodeToDelete != nullptr && rightBottomNode != nullptr && rightBottomParentNode != nullptr)
    {
        nodeToDelete->setData(rightBottomNode->getData());
        rightBottomParentNode->setRight(nullptr);
        // if (rightBottomParentNode->getRight() == rightBottomNode)
        // {
        //     /* code */
        // } else if (rightBottomParentNode->getLeft() == rightBottomNode)
        // {
        //     /* code */
        // }
        delete rightBottomNode;
    }
}




void playWithBinaryTree() {
    BinaryTree<char> *tree = new BinaryTree<char>();
        tree->insert('A');
        tree->insert('B');
        tree->insert('C');
        tree->insert('D');
        tree->insert('E');
        tree->insert('F');
        tree->insert('G');
        tree->insert('H');
        tree->insert('I');
        tree->print();
        cout << "tree height is " << tree->height() << endl;
        tree->preOrderTraversal();
        tree->inOrderTraversal();
        tree->postOrderTraversal();
        BinaryTreeNode<char> *found = tree->find('H');
        if (found)
        {
            cout << "found node with data H : " << found->getData() << endl;
        } else {
            cout << "not found node with data H : " << endl;
        }
        BinaryTreeNode<char> *notfound = tree->find('Z');
        if (notfound)
        {
            cout << "notfound node with data Z : " << notfound->getData() << endl;
        } else {
            cout << "not notfound node with data Z : " << endl;
        }

        tree->deleteNode('H');
        tree->print();



}
