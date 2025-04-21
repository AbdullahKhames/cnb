#include "doublylinkedlist.h"

DoublyLinkedListNode::DoublyLinkedListNode(int value) {
  this->data = value;
  this->next = nullptr;
  this->prev = nullptr;
}

DoublyLinkedListIterator::DoublyLinkedListIterator() { this->current = nullptr; }

int DoublyLinkedListIterator::data() { return this->current->data; }

DoublyLinkedListIterator DoublyLinkedListIterator::next() {
  this->current = this->current->next;
  return *this;
}
DoublyLinkedListNode *DoublyLinkedListIterator::getCurrent() { return this->current; }
DoublyLinkedListIterator::DoublyLinkedListIterator(DoublyLinkedListNode *head) {
  this->current = head;
}
void DoublyLinkedList::inserLast(int value) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(value);
    DoublyLinkedListNode *tail = this->tail;
    if (!this->head)
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    this->tail = newNode;
}

void DoublyLinkedList::inserFirst(int value) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(value);
    if (!this->head)
    {
        this->head = newNode;
        this->head = newNode;
        return;
    }
    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
}

DoublyLinkedListNode * DoublyLinkedList::find(int value) {
    DoublyLinkedListNode *current;
    for (DoublyLinkedListIterator it = this->begin();
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

DoublyLinkedListNode * DoublyLinkedList::get(int idx) {
    DoublyLinkedListNode *current;
    int count = 0;
    if (idx < 0)
    {
        return nullptr;
    }
    
    for (DoublyLinkedListIterator it = this->begin();
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
void DoublyLinkedList::insertAfterIdx(int data, int idx) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *targetNode = this->get(idx);
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
}
void DoublyLinkedList::insertAfterValue(int data, int value) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *targetNode = this->find(value);
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
}

void DoublyLinkedList::insertBeforeIdx(int data, int idx) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *targetNode = this->get(idx);
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
}
void DoublyLinkedList::insertBeforeValue(int data, int value) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *targetNode = this->find(value);
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
}
DoublyLinkedListIterator DoublyLinkedList::begin() { return DoublyLinkedListIterator(head); }

void DoublyLinkedList::printList() {
  for (DoublyLinkedListIterator it = begin(); it.getCurrent() != nullptr; it.next()) {
    cout << it.data() << " ";
  }
  cout << endl;
}

void DoublyLinkedList::deleteNodeByValue(int value) {
    DoublyLinkedListNode *targetNode = this->find(value);
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;
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
    delete targetNode;
}
void DoublyLinkedList::deleteNodeByIdx(int idx) {
    DoublyLinkedListNode *targetNode = this->get(idx);
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;
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
    delete targetNode;
}

void playWithDoublyLinkedList() {
    DoublyLinkedList list;

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
    DoublyLinkedListNode* found = list.find(25);
    if (found) {
        std::cout << "Found node with value: " << found->data << "\n";
    } else {
        std::cout << "Value not found!\n";
    }

    // Get by index
    std::cout << "\nGetting node at index 4:\n";
    DoublyLinkedListNode* nodeAt4 = list.get(4);
    if (nodeAt4) {
        std::cout << "Node at index 4 has value: " << nodeAt4->data << "\n";
    } else {
        std::cout << "Invalid index!\n";
    }

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
