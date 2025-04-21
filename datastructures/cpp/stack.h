#ifndef STACK_H
#define STACK_H

#include "base.h"

template <class T>
class Stack {
    private:
        T *data;
        int top;
        int totalLength;
        int currentSize;
        void increaseIfNeeded();
    public:
        Stack();
        void push(T data);
        T pop();
        T peek();
        bool isEmpty();
        int size();
        void print();
};

void playWithStack();
#endif
