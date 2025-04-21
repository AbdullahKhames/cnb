#ifndef QUEUE_H
#define QUEUE_H
#include "genericlinkedlist.h"


template <class T>
class Queue {
    private:
        GnericDoublyLinkedList<T> *list;
        int currentSize;
    public:
        Queue();
        void enqueue(T data);
        T dequeue();
        T peek();
        void print();
        int size();
        bool isEmpty();
};

template <class T>
class QueueArray {
    private:
        T *list;
        int currentSize;
        int totalSize;
        int head;
        int tail;
        bool increaseSizeIfNeeded();
    public:
        QueueArray();
        void enqueue(T data);
        T dequeue();
        T peek();
        void print();
        void debug();
        int size();
        bool isEmpty();
};


void playWithQueue();
void playWithQueueArray();
#endif
