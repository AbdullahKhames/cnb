#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "base.h"
class DoublyLinkedListNode {
public:
  int data;
  DoublyLinkedListNode *next;
  DoublyLinkedListNode *prev;
  DoublyLinkedListNode(int data);
};

class DoublyLinkedListIterator {
private:
  DoublyLinkedListNode *current;

public:
  DoublyLinkedListIterator();
  DoublyLinkedListIterator(DoublyLinkedListNode *head);
  int data();
  DoublyLinkedListIterator next();
  DoublyLinkedListNode *getCurrent();
};

class DoublyLinkedList {
public:
  DoublyLinkedListNode *head = nullptr;
  DoublyLinkedListNode *tail = nullptr;
  void inserLast(int data);
  void inserFirst(int data);
  void insertAfterIdx(int data, int idx);
  void insertAfterValue(int data, int value);
  void insertBeforeIdx(int data, int idx);
  void insertBeforeValue(int data, int value);
  DoublyLinkedListIterator begin();
  void printList();
  DoublyLinkedListNode *find(int value);
  DoublyLinkedListNode *get(int idx);
  void deleteNodeByIdx(int idx);
  void deleteNodeByValue(int val);
};
void playWithDoublyLinkedList();
#endif
