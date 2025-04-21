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
