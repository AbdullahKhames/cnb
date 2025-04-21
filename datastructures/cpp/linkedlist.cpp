#include "linkedlist.h"

LinkedListNode::LinkedListNode(int value) {
  this->data = value;
  this->next = nullptr;
}

LinkedListIterator::LinkedListIterator() { this->current = nullptr; }

int LinkedListIterator::data() { return this->current->data; }

LinkedListIterator LinkedListIterator::next() {
  this->current = this->current->next;
  return *this;
}
LinkedListNode *LinkedListIterator::getCurrent() { return this->current; }
LinkedListIterator::LinkedListIterator(LinkedListNode *head) {
  this->current = head;
}
void LinkedList::inserLast(int value) {
  LinkedListNode *newNode = new LinkedListNode(value);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void LinkedList::insertAfterIdx(int data, int idx) {
    int count = 0;
    LinkedListNode *newNode = new LinkedListNode(data);
    LinkedListNode *curr;
    LinkedListNode *next;
    LinkedListIterator it = this->begin();
    if (idx < 0)
    {
        return;
    }
    if (idx == 0)
    {
        curr = it.getCurrent();
        next = curr->next;
        curr->next = newNode;
        newNode->next = next;
        return;
    }
    while (it.getCurrent() != nullptr)
    {
        if (count == idx)
        {
            curr = it.getCurrent();
            next = curr->next;
            curr->next = newNode;
            newNode->next = next;
            if (curr == tail)
            {
                tail = newNode;
            }
            
        }
        count++;
        it = it.next();
    }
}
void LinkedList::insertAfterValue(int data, int value) {
    LinkedListNode *newNode = new LinkedListNode(data);
    LinkedListNode *curr = this->find(value);
    LinkedListNode *next;
    if (curr)
    {
        next = curr->next;
        curr->next = newNode;
        newNode->next = next;
        if (this->tail == curr)
        {
            this->tail = newNode;
        }
    }
}

void LinkedList::insertBeforeIdx(int data, int idx) {
    int count = 0;
    LinkedListNode *newNode = new LinkedListNode(data);
    LinkedListNode *curr = head;
    LinkedListNode *prev = nullptr;
    if (idx < 0)
    {
        return;
    }
    if (!head)
    {
        return;
    }
    
    if (idx == 0)
    {
        head = newNode;
        newNode->next = curr;
        return;
    }
    while (curr)
    {
        if (idx == count)
        {
            prev->next = newNode;
            newNode->next = curr;
            break;
        }
        
        count++;
        prev = curr;
        curr = curr->next;
    }
}
void LinkedList::insertBeforeValue(int data, int value) {
    LinkedListNode *newNode = new LinkedListNode(data);
    LinkedListNode *curr = this->head;
    LinkedListNode *prev = nullptr;
    while (curr)
    {
        if (curr->data == value)
        {
            // i.e first node!
            if (!prev)
            {
                head = newNode;
                newNode->next = curr;
                return;
            }

            prev->next = newNode;
            newNode->next = curr;
            break;
        }
        
        prev = curr;
        curr = curr->next;
    }
}
LinkedListIterator LinkedList::begin() { return LinkedListIterator(head); }

void LinkedList::printList() {
  for (LinkedListIterator it = begin(); it.getCurrent() != nullptr; it.next()) {
    cout << it.data() << " ";
  }
  cout << endl;
}


LinkedListNode * LinkedList::find(int value) {
    LinkedListNode *curr;
    for (LinkedListIterator it = this->begin(); it.getCurrent() != nullptr; it = it.next())
    {
        curr = it.getCurrent();
        if (value == curr->data)
        {
            return curr;
        }
    }
    return nullptr;
}
LinkedListNode * LinkedList::get(int idx) {
    int count = 0;
    if (idx < 0)
    {
        return nullptr;
    }
    
    for (LinkedListIterator it = this->begin(); it.getCurrent() != nullptr; it = it.next())
    {
        if (idx == count)
        {
            return it.getCurrent();
        }
        count++;
    }
    return nullptr;
}
void LinkedList::deleteNodeByValue(int value) {
    LinkedListNode *curr;
    LinkedListNode * prev = nullptr;
    for (LinkedListIterator it = this->begin(); it.getCurrent() != nullptr; it = it.next())
    {
        curr = it.getCurrent();
        if (curr->data == value)
        {
            if (this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
                delete curr;
                break;
            } else if (!prev) {
                head = curr->next;
                delete curr;
                break;
            } else if (curr == this->tail)
            {
                this->tail = prev;
                prev->next = nullptr;
                delete curr;
                break;
            } else {
                prev->next = curr->next;
                delete curr;
            }
        }
        prev = curr;
    }
    return;
}
void LinkedList::deleteNodeByIdx(int idx) {
    LinkedListNode * curr;
    LinkedListNode * prev = nullptr;
    int count = 0;
    if (idx < 0)
    {
        return;
    }
    
    for (LinkedListIterator it = this->begin(); it.getCurrent() != nullptr; it = it.next())
    {
        curr = it.getCurrent();
        if (idx == count) {
            if (this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
                delete curr;
                break;
            } else if (!prev) {
                head = curr->next;
                delete curr;
                break;
            } else if (curr == this->tail)
            {
                this->tail = prev;
                prev->next = nullptr;
                delete curr;
                break;
            } else {
                prev->next = curr->next;
                delete curr;
            }
        }
        count++;
        prev = curr;
    }
    return;
}


void playWithLinkedList() {
      // LinkedList *numbers = new LinkedList();
  // numbers->inserLast(1);
  // numbers->inserLast(2);
  // numbers->inserLast(3);
  // numbers->inserLast(4);
  // numbers->insertAfterIdx(47, 1);
  // numbers->insertBeforeIdx(50, 1);
  // numbers->deleteNodeByIdx(1);
  // numbers->deleteNodeByValue(4);
  // numbers->printList();
  LinkedList list;

  cout << "Initial list (should be empty):\n";
  list.printList();

  // Insert at last
  cout << "\nInserting at last:\n";
  list.inserLast(10);
  list.inserLast(20);
  list.inserLast(30);
  list.printList();

  // Insert after index
  cout << "\nInserting 25 after index 1:\n";
  list.insertAfterIdx(25, 1);
  list.printList();

  // Insert before index
  cout << "\nInserting 5 before index 0:\n";
  list.insertBeforeIdx(5, 0);
  list.printList();

  // Insert after value
  cout << "\nInserting 35 after value 30:\n";
  list.insertAfterValue(35, 30);
  list.printList();

  // Insert before value
  cout << "\nInserting 15 before value 20:\n";
  list.insertBeforeValue(15, 20);
  list.printList();

  // Search by value
  cout << "\nSearching for value 25:\n";
  LinkedListNode* found = list.find(25);
  if (found) {
      cout << "Found node with value: " << found->data << "\n";
  } else {
      cout << "Value not found!\n";
  }

  // Get by index
  cout << "\nGetting node at index 3:\n";
  LinkedListNode* nodeAt3 = list.get(3);
  if (nodeAt3) {
      cout << "Node at index 3 has value: " << nodeAt3->data << "\n";
  } else {
      cout << "Invalid index!\n";
  }

  // Delete node by index
  cout << "\nDeleting node at index 2:\n";
  list.deleteNodeByIdx(2);
  list.printList();

  // Delete node by value
  cout << "\nDeleting node with value 20:\n";
  list.deleteNodeByValue(20);
  list.printList();

  // Edge cases
  cout << "\nTrying to delete node at invalid index 100:\n";
  list.deleteNodeByIdx(100);
  list.printList();

  cout << "\nTrying to delete non-existent value 999:\n";
  list.deleteNodeByValue(999);
  list.printList();

  cout << "\nClearing the entire list:\n";
  while (list.head != nullptr) {
      list.deleteNodeByIdx(0);
  }
  list.printList();

  cout << "\nTrying to delete from an empty list:\n";
  list.deleteNodeByValue(10);  // Should handle gracefully.
  list.deleteNodeByIdx(0);     // Should handle gracefully.
}
