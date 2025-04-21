#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "base.h"
class LinkedListNode {
public:
  int data;
  LinkedListNode *next;
  LinkedListNode(int data);
};

class LinkedListIterator {
private:
  LinkedListNode *current;

public:
  LinkedListIterator();
  LinkedListIterator(LinkedListNode *head);
  int data();
  LinkedListIterator next();
  LinkedListNode *getCurrent();
};

class LinkedList {
public:
  LinkedListNode *head = nullptr;
  LinkedListNode *tail = nullptr;
  void inserLast(int data);
  void insertAfterIdx(int data, int idx);
  void insertAfterValue(int data, int value);
  void insertBeforeIdx(int data, int idx);
  void insertBeforeValue(int data, int value);
  LinkedListIterator begin();
  void printList();
  LinkedListNode *find(int value);
  LinkedListNode *get(int idx);
  void deleteNodeByIdx(int idx);
  void deleteNodeByValue(int val);
};

void playWithLinkedList();
#endif
