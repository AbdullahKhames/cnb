#ifndef GENERICINKEDLIST_H
#define GENERICINKEDLIST_H
#include "base.h"
template <class T>
class GnericDoublyLinkedListNode {
public:
  T data;
  GnericDoublyLinkedListNode<T> *next;
  GnericDoublyLinkedListNode<T> *prev;
  GnericDoublyLinkedListNode(T data);
};
template <class T>
class GnericDoublyLinkedListIterator {
private:
  GnericDoublyLinkedListNode<T> *current;

public:
  GnericDoublyLinkedListIterator();
  GnericDoublyLinkedListIterator(GnericDoublyLinkedListNode<T> *head);
  T data();
  GnericDoublyLinkedListIterator<T> next();
  GnericDoublyLinkedListNode<T> *getCurrent();
};
template <class T>
class GnericDoublyLinkedList {
public:
  GnericDoublyLinkedListNode<T> *head = nullptr;
  GnericDoublyLinkedListNode<T> *tail = nullptr;
  int length;
  int size();
  void inserLast(T data);
  void inserFirst(T data);
  void insertAfterIdx(T data, int idx);
  void insertAfterValue(T data, T value);
  void insertBeforeIdx(T data, int idx);
  void insertBeforeValue(T data, T value);
  GnericDoublyLinkedListIterator<T> begin();
  void printList();
  GnericDoublyLinkedListNode<T> *find(T value);
  GnericDoublyLinkedListNode<T> *get(int idx);
  void deleteNodeByIdx(int idx);
  void deleteNodeByValue(T value);
  void deleteHead();
};
void playWithGnericDoublyLinkedList();
#endif
