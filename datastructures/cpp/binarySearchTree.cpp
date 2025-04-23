#include "binarySearchTree.h"

template <class T>
void BinarySearchTree<T>::insert(T data) {
    BinarySearchTreeNode<T> *temp = this->getRoot();
    BinarySearchTreeNode<T> *newNode = new BinarySearchTreeNode(data);
    if (!temp)
    {
        this->setRoot(newNode);
        return;
    }
    
    while (temp)
    {
        if (data < temp->getData())
        {
            if (temp->getLeft() != nullptr)
            {
                temp = temp->getLeft();
            } else {
                temp->setLeft(newNode);
                break;
            }
            
        } else {
            if (temp->getRight() != nullptr)
            {
                temp = temp->getRight();
            } else {
                temp->setRight(newNode);
                break;
            }
        }
        
    }
    
}

template <class T>
int BinarySearchTree<T>::height() {
    return this->height(this->root);
}

template <class T>
int BinarySearchTree<T>::height(BinarySearchTreeNode<T>* node) {
    if (!node)
    {
        return 0;
    }
    return 1 + max(height(node->getLeft()), height(node->getRight())); 
    
}

template <class T>
// i copied this from stackoverflow for demonstration!
void BinarySearchTree<T>::print(const std::string& prefix, BinarySearchTreeNode<T>* node, bool isLeft)
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
void BinarySearchTree<T>::print() 
{
    print("", this->root, false);
}




template <class T>
void BinarySearchTree<T>::preOrderTraversal() {
    cout << "---------------pre order traversal------------------" << endl;
    this->preOrderTraversal(this->root);
    cout << "\n---------------pre order traversal------------------" << endl;

}


template <class T>
void BinarySearchTree<T>::preOrderTraversal(BinarySearchTreeNode<T>* node) {
    if (!node)
    {
        return;
    }
    cout << node->getData() << " ";
    preOrderTraversal(node->getLeft());
    preOrderTraversal(node->getRight());
}

template <class T>
void BinarySearchTree<T>::postOrderTraversal() {
    cout << "---------------post order traversal------------------" << endl;
    this->postOrderTraversal(this->root);
    cout << "\n---------------post order traversal------------------" << endl;

}


template <class T>
void BinarySearchTree<T>::postOrderTraversal(BinarySearchTreeNode<T>* node) {
    if (!node)
    {
        return;
    }
    postOrderTraversal(node->getLeft());
    postOrderTraversal(node->getRight());
    cout << node->getData() << " ";
}

template <class T>
void BinarySearchTree<T>::inOrderTraversal() {
    cout << "---------------in order traversal------------------" << endl;
    this->inOrderTraversal(this->root);
    cout << "\n---------------in order traversal------------------" << endl;

}


template <class T>
void BinarySearchTree<T>::inOrderTraversal(BinarySearchTreeNode<T>* node) {
    if (!node)
    {
        return;
    }
    inOrderTraversal(node->getLeft());
    cout << node->getData() << " ";
    inOrderTraversal(node->getRight());
}

template <class T>
BinarySearchTreeNode<T> * BinarySearchTree<T>::find(T key) {
    return this->find(this->root, key);
}
template <class T>
BinarySearchTreeNode<T> * BinarySearchTree<T>::findIterative(T key) {
    BinarySearchTreeNode<T> *temp = this->root;
    while (temp)
    {
        if (key == temp->getData())
        {
            return temp;
        } else if (key > temp->getData()) {
            temp = temp->getRight();
        } else {
            temp = temp->getLeft();
        }
    }
    return temp;
    
}


template <class T>
BinarySearchTreeNode<T> * BinarySearchTree<T>::find(BinarySearchTreeNode<T>* node, T key) {
    BinarySearchTreeNode<T>* temp;
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
ParentAndNode<T> * BinarySearchTree<T>::findParentAndNode(T key) {
    BinarySearchTreeNode<T>* temp = this->getRoot();
    BinarySearchTreeNode<T>* parent = nullptr;
    bool isLeft = false;
    ParentAndNode<T>* result = nullptr;
    while (temp)
    {
        if (key == temp->getData())
        {
            result = new ParentAndNode(isLeft, parent, temp);
            break;
        } else if (key < temp->getData())
        {
            parent = temp;
            isLeft = true;
            temp = temp->getLeft();
        } else {
            parent = temp;
            isLeft = false;
            temp = temp->getRight();
        }
    }
    return result;
}

template <class T>
BinarySearchTreeNode<T> * BinarySearchTree<T>::findBottomRightNode(BinarySearchTreeNode<T> *node) {
    if (!node)
    {
        return nullptr;
    }
    queue<BinarySearchTreeNode<T> *> queue;
    BinarySearchTreeNode<T> *temp = nullptr;
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
ParentAndNode<T> * BinarySearchTree<T>::inOrderSuccessor(BinarySearchTreeNode<T> *node) {
    BinarySearchTreeNode<T> *temp = node;
    BinarySearchTreeNode<T> *parent = nullptr;
    bool isLeft = false;
    if (!temp)
    {
        return nullptr;
    }
    
    while (temp->getLeft())
    {
        parent = temp;
        isLeft = true;
        temp = temp->getLeft();
    }
    return new ParentAndNode(isLeft, parent, temp);
    
    
}

template <class T>
BinarySearchTreeNode<T> * BinarySearchTree<T>::findParent(BinarySearchTreeNode<T> *root, BinarySearchTreeNode<T> *node) {
    if (!node || !root)
    {
        return nullptr;
    }
    queue<BinarySearchTreeNode<T> *> queue;
    BinarySearchTreeNode<T> *temp = nullptr;
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
void BinarySearchTree<T>::deleteNode(T key) {
    BinarySearchTreeNode<T> *nodeToDelete = this->find(this->root, key);
    BinarySearchTreeNode<T> *rightBottomNode = this->findBottomRightNode(this->root);
    BinarySearchTreeNode<T> *rightBottomParentNode = this->findParent(this->root, rightBottomNode);

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


template <class T>
void BinarySearchTree<T>::deleteNodeBST(T data) {
    ParentAndNode<T> *foundParentAndNode = this->findParentAndNode(data);
    if (!foundParentAndNode || !foundParentAndNode->node)
    {
        return;
    }
    if (foundParentAndNode->node->getLeft() != nullptr &&
    foundParentAndNode->node->getRight() != nullptr)
    {
        this->deleteNodeBST_TwoChilds(foundParentAndNode->node);
    } else if (foundParentAndNode->node->getLeft() != nullptr ^
    foundParentAndNode->node->getRight() != nullptr) {
        this->deleteNodeBST_OneChilds(foundParentAndNode->node);
    } else {
        this->deleteNodeBST_ZeroChilds(foundParentAndNode);

    }
    
}

template <class T>
void BinarySearchTree<T>::deleteNodeBST_TwoChilds(BinarySearchTreeNode<T> *nodeToDelete) {

    ParentAndNode<T> *inOrderSucc = this->inOrderSuccessor(nodeToDelete->getRight());
    if (inOrderSucc)
    {
        cout << "found parent and node : " 
            << inOrderSucc->parent->getData()
            << " "
            << inOrderSucc->node->getData()
            << " "
            << inOrderSucc->isLeft
            << endl;
        if (inOrderSucc->parent != nullptr)
        {
            inOrderSucc->parent->setLeft(inOrderSucc->node->getRight());
        } else {
            nodeToDelete->setRight(inOrderSucc->node->getRight());
        }
        nodeToDelete->setData(inOrderSucc->node->getData());
        delete inOrderSucc->node;
    }

    
}
template <class T>
void BinarySearchTree<T>::deleteNodeBST_OneChilds(BinarySearchTreeNode<T> *nodeToDelete) {
    BinarySearchTreeNode<T> *nodeToReplace;

    if (nodeToDelete->getLeft())
    {
        nodeToReplace = nodeToDelete->getLeft();
    } else {
        nodeToReplace = nodeToDelete->getRight();
    }
    nodeToDelete->setLeft(nodeToReplace->getLeft());
    nodeToDelete->setRight(nodeToReplace->getRight());
    nodeToDelete->setData(nodeToReplace->getData());
    delete nodeToReplace;
}
template <class T>
void BinarySearchTree<T>::deleteNodeBST_ZeroChilds(ParentAndNode<T> *foundParentAndNode) {
    if (foundParentAndNode)
    {
        if (foundParentAndNode->parent && foundParentAndNode->isLeft)
        {
            foundParentAndNode->parent->setLeft(nullptr);
        } else if (foundParentAndNode->parent && !foundParentAndNode->isLeft)
        {
            foundParentAndNode->parent->setRight(nullptr);
        } else {
            this->setRoot(nullptr);
        }
    } else {
        this->setRoot(nullptr);
    }
    delete foundParentAndNode->node;
}

template <class T>
void BinarySearchTree<T>::Balance() {
    vector<T> nodes;
    InOrderToArray(this->getRoot(), nodes);
    this->setRoot(RecursiveBalance(0, nodes.size() - 1, nodes));
}
template <class T>
void BinarySearchTree<T>::InOrderToArray(BinarySearchTreeNode<T> *node, vector<T> &nodes) {
    if (node == nullptr)
    {
        return;
    }
    InOrderToArray(node->getLeft(), nodes);
    nodes.push_back(node->getData());
    InOrderToArray(node->getRight(), nodes);
}
template <class T>
BinarySearchTreeNode<T> *BinarySearchTree<T>::RecursiveBalance(int start, int end, vector<T> &nodes) {
    if (start > end)
    {
        return nullptr;
    }
    int mid = (start + end) / 2;
    BinarySearchTreeNode<T> *newNode = new BinarySearchTreeNode(nodes[mid]);
    newNode->setLeft(RecursiveBalance(start, mid - 1, nodes));
    newNode->setRight(RecursiveBalance(mid + 1, end, nodes));
    return newNode;
}

void playWithBinarySearchTree() {
    BinarySearchTree<int> *tree = new BinarySearchTree<int>();
        // tree->insert(4);
        // tree->insert(6);
        // tree->insert(7);
        // tree->insert(5);
        // tree->insert(2);
        // tree->insert(1);
        // tree->insert(3);

        // tree->print();
        // cout << "tree height is " << tree->height() << endl;
        // tree->preOrderTraversal();
        // tree->inOrderTraversal();
        // tree->postOrderTraversal();
        // BinarySearchTreeNode<int> *found = tree->findIterative(4);
        // if (found)
        // {
        //     cout << "found node with data 17 : " << found->getData() << endl;
        // } else {
        //     cout << "not found node with data 17 : " << endl;
        // }
        // ParentAndNode<int> *inOrderSucc = tree->inOrderSuccessor(found->getRight());
        // if (inOrderSucc)
        // {
        //     cout << "inOrderSucc node with data 17 : " << inOrderSucc->node->getData() << endl;
        // } else {
        //     cout << "not found inOrderSucc with data 17 : " << endl;
        // }
        // BinarySearchTreeNode<int> *notfound = tree->findIterative(30);
        // if (notfound)
        // {
        //     cout << "notfound node with data 30 : " << notfound->getData() << endl;
        // } else {
        //     cout << "not notfound node with data 30 : " << endl;
        // }

        // ParentAndNode<int> *foundParentAndNode = tree->findParentAndNode(17); 
        // if (foundParentAndNode)
        // {
        //     cout << "found parent and node with data 17 : " 
        //     << foundParentAndNode->parent->getData()
        //     << " "
        //     << foundParentAndNode->node->getData()
        //     << " "
        //     << foundParentAndNode->isLeft
        //     << endl;
        // } else {
        //     cout << "not notfound node with data 17 : " << endl;
        // }
        // tree->deleteNodeBST(4);
        // tree->print();
        // tree->deleteNodeBST(6);
        // tree->print();
        // tree->deleteNodeBST(3);
        // tree->print();

        
        tree->insert(1);
        tree->insert(2);
        tree->insert(3);
        tree->insert(4);
        tree->insert(5);
        tree->insert(6);
        tree->insert(7);
      
        tree->inOrderTraversal();
        tree->print();
        tree->Balance();
        tree->print();
        tree->inOrderTraversal();
        
}
