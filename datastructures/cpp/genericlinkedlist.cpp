#include "genericlinkedlist.h"
template <class T>
GnericDoublyLinkedListNode<T>::GnericDoublyLinkedListNode(T value) {
  this->data = value;
  this->next = nullptr;
  this->prev = nullptr;
}
template <class T>
GnericDoublyLinkedListIterator<T>::GnericDoublyLinkedListIterator() { this->current = nullptr; }
template <class T>
T GnericDoublyLinkedListIterator<T>::data() { return this->current->data; }
template <class T>
GnericDoublyLinkedListIterator<T> GnericDoublyLinkedListIterator<T>::next() {
  this->current = this->current->next;
  return *this;
}
template <class T>
GnericDoublyLinkedListNode<T> *GnericDoublyLinkedListIterator<T>::getCurrent() { return this->current; }
template <class T>
GnericDoublyLinkedListIterator<T>::GnericDoublyLinkedListIterator(GnericDoublyLinkedListNode<T> *head) {
  this->current = head;
}
template <class T>
void GnericDoublyLinkedList<T>::inserLast(T value) {
    GnericDoublyLinkedListNode<T> *newNode = new GnericDoublyLinkedListNode(value);
    GnericDoublyLinkedListNode<T> *tail = this->tail;
    if (!this->head)
    {
        this->head = newNode;
        this->tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        this->tail = newNode;
    }
    this->length++;
}

template <class T>
void GnericDoublyLinkedList<T>::inserFirst(T value) {
    GnericDoublyLinkedListNode<T> *newNode = new GnericDoublyLinkedListNode(value);
    if (!this->head)
    {
        this->head = newNode;
        this->head = newNode;
    } else {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    this->length++;
}

template <class T>
GnericDoublyLinkedListNode<T> * GnericDoublyLinkedList<T>::find(T value) {
    GnericDoublyLinkedListNode<T> *current;
    for (GnericDoublyLinkedListIterator<T> it = this->begin();
        it.getCurrent() != nullptr;
        it = it.next())
    {
        current = it.getCurrent();
        if (value == current->data)
        {
            return current;
        }
    }
    return nullptr;
}

template <class T>
GnericDoublyLinkedListNode<T> * GnericDoublyLinkedList<T>::get(int idx) {
    GnericDoublyLinkedListNode<T> *current;
    int count = 0;
    if (idx < 0)
    {
        return nullptr;
    }
    
    for (GnericDoublyLinkedListIterator<T> it = this->begin();
        it.getCurrent() != nullptr;
        it = it.next())
    {
        current = it.getCurrent();
        if (count == idx)
        {
            return current;
        }
        count++;
    }
    return nullptr;
}
template <class T>
void GnericDoublyLinkedList<T>::insertAfterIdx(T data, int idx) {
    GnericDoublyLinkedListNode<T> *newNode = new GnericDoublyLinkedListNode(data);
    GnericDoublyLinkedListNode<T> *targetNode = this->get(idx);
    if (!targetNode)
    {
        this->inserLast(data);
    } else {
        newNode->next = targetNode->next;
        targetNode->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = targetNode;
        if (targetNode == this->tail)
        {
            this->tail = newNode;
        }
    }
    this->length++;
}
template <class T>
void GnericDoublyLinkedList<T>::insertAfterValue(T data, T value) {
    GnericDoublyLinkedListNode<T> *newNode = new GnericDoublyLinkedListNode(data);
    GnericDoublyLinkedListNode<T> *targetNode = this->find(value);
    if (!targetNode)
    {
        this->inserLast(data);
    } else {
        newNode->next = targetNode->next;
        if (targetNode == this->tail)
        {
            this->tail = newNode;
        } else {
            targetNode->next->prev = newNode;
        }
        targetNode->next = newNode;
        newNode->prev = targetNode;
    }
    this->length++;
}

template <class T>
void GnericDoublyLinkedList<T>::insertBeforeIdx(T data, int idx) {
    GnericDoublyLinkedListNode<T> *newNode = new GnericDoublyLinkedListNode(data);
    GnericDoublyLinkedListNode<T> *targetNode = this->get(idx);
    if (!targetNode)
    {
        this->inserFirst(data);
    } else {
        newNode->prev = targetNode->prev;
        if (targetNode == this->head)
        {
            this->head = newNode;
        } else {
            targetNode->prev->next = newNode;
        }
        targetNode->prev = newNode;
        newNode->next = targetNode;
    }
    this->length++;
}
template <class T>
void GnericDoublyLinkedList<T>::insertBeforeValue(T data, T value) {
    GnericDoublyLinkedListNode<T> *newNode = new GnericDoublyLinkedListNode(data);
    GnericDoublyLinkedListNode<T> *targetNode = this->find(value);
    if (!targetNode)
    {
        this->inserFirst(data);
    } else {
        newNode->prev = targetNode->prev;
        if (targetNode == this->head)
        {
            this->head = newNode;
        } else {
            targetNode->prev->next = newNode;
        }
        targetNode->prev = newNode;
        newNode->next = targetNode;
    }
    this->length++;
}
template <class T>
GnericDoublyLinkedListIterator<T> GnericDoublyLinkedList<T>::begin() { return GnericDoublyLinkedListIterator(head); }

template <class T>
void GnericDoublyLinkedList<T>::printList() {
  for (GnericDoublyLinkedListIterator<T> it = begin(); it.getCurrent() != nullptr; it.next()) {
    cout << it.data() << " ";
  }
  cout << endl;
}

template <class T>
void GnericDoublyLinkedList<T>::deleteNodeByValue(T value) {
    GnericDoublyLinkedListNode<T> *targetNode = this->find(value);
    GnericDoublyLinkedListNode<T> *prev;
    GnericDoublyLinkedListNode<T> *next;
    if (!targetNode) {
        return;
    } else if (targetNode == this->head && targetNode == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else if (targetNode == this->head) {
        next = targetNode->next;
        next->prev = nullptr;
        this->head = next;
    } else if (targetNode == this->tail) {
        prev = targetNode->prev;
        prev->next = nullptr;
        this->tail = prev;
    } else {
        prev = targetNode->prev;
        next = targetNode->next;
        prev->next = next;
        next->prev = prev;
    }
    this->length--;
    delete targetNode;
}
template <class T>
void GnericDoublyLinkedList<T>::deleteNodeByIdx(int idx) {
    GnericDoublyLinkedListNode<T> *targetNode = this->get(idx);
    GnericDoublyLinkedListNode<T> *prev;
    GnericDoublyLinkedListNode<T> *next;
    if (!targetNode) {
        return;
    } else if (targetNode == this->head && targetNode == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else if (targetNode == this->head) {
        next = targetNode->next;
        next->prev = nullptr;
        this->head = next;
    } else if (targetNode == this->tail) {
        prev = targetNode->prev;
        prev->next = nullptr;
        this->tail = prev;
    } else {
        prev = targetNode->prev;
        next = targetNode->next;
        prev->next = next;
        next->prev = prev;
    }
    this->length--;
    delete targetNode;
}

template <class T>
int GnericDoublyLinkedList<T>::size() {
    return this->length;
}

template <class T>
void GnericDoublyLinkedList<T>::deleteHead() {
    if (!this->head) {
        throw std::logic_error("List is empty!"); // Throw only if the list is empty
    }

    GnericDoublyLinkedListNode<T> *val = this->head;
    if (this->head->next) {
        this->head->next->prev = nullptr;
    }
    this->head = this->head->next;

    delete val; // Free the memory of the removed node
    this->length--;
}
void playWithGnericDoublyLinkedList() {
    GnericDoublyLinkedList<int> list;

    std::cout << "Initial Doubly Linked List (should be empty):\n";
    list.printList();

    // Insert at last
    std::cout << "\nInserting at last:\n";
    list.inserLast(10);
    list.inserLast(20);
    list.inserLast(30);
    list.printList();

    // Insert at first
    std::cout << "\nInserting at first:\n";
    list.inserFirst(5);
    list.inserFirst(1);
    list.printList();

    // Insert after index
    std::cout << "\nInserting 25 after index 2:\n";
    list.insertAfterIdx(25, 2);
    list.printList();

    // Insert before index
    std::cout << "\nInserting 15 before index 3:\n";
    list.insertBeforeIdx(15, 3);
    list.printList();

    // Insert after value
    std::cout << "\nInserting 35 after value 30:\n";
    list.insertAfterValue(35, 30);
    list.printList();

    // Insert before value
    std::cout << "\nInserting 12 before value 15:\n";
    list.insertBeforeValue(12, 15);
    list.printList();

    // Search by value
    std::cout << "\nSearching for value 25:\n";
    GnericDoublyLinkedListNode<int>* found = list.find(25);
    if (found) {
        std::cout << "Found node with value: " << found->data << "\n";
    } else {
        std::cout << "Value not found!\n";
    }

    // Get by index
    std::cout << "\nGetting node at index 4:\n";
    GnericDoublyLinkedListNode<int>* nodeAt4 = list.get(4);
    if (nodeAt4) {
        std::cout << "Node at index 4 has value: " << nodeAt4->data << "\n";
    } else {
        std::cout << "Invalid index!\n";
    }
    std::cout << "\nsize of linked list is: \n" << list.size();
    std::cout << "\nsize of linked list is: \n" << list.length;

    // Delete head
    std::cout << "\nDeleting head:\n";
    list.deleteHead();
    list.printList();
    
    // Delete node by index
    std::cout << "\nDeleting node at index 3:\n";
    list.deleteNodeByIdx(3);
    list.printList();

    // Delete node by value
    std::cout << "\nDeleting node with value 20:\n";
    list.deleteNodeByValue(20);
    list.printList();

    // Edge cases
    std::cout << "\nTrying to delete node at invalid index 100:\n";
    list.deleteNodeByIdx(100);
    list.printList();

    std::cout << "\nTrying to delete non-existent value 999:\n";
    list.deleteNodeByValue(999);
    list.printList();

    std::cout << "\nClearing the entire list:\n";
    while (list.head != nullptr) {
        list.deleteNodeByIdx(0);
    }
    list.printList();

    std::cout << "\nTrying to delete from an empty list:\n";
    list.deleteNodeByValue(10);
    list.deleteNodeByIdx(0);
}
