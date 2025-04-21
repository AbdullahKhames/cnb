#include "stack.h"

template <class T>
Stack<T>::Stack() {
    this->totalLength = 3;
    this->data = new T[this->totalLength];
    this->top = -1;
    this->currentSize = 0;
}

template <class T>
void Stack<T>::increaseIfNeeded() {
    if (this->currentSize == this->totalLength)
    {
        cout << "increasing size !" << endl;
        this->totalLength *= 2;
        T *newArray = new T[this->totalLength];
        // copy to new array
        std::copy(this->data,
            this->data + this->currentSize,
            newArray);
        this->data = newArray;
    }
    
}

template <class T>
void Stack<T>::push(T data) {
    this->increaseIfNeeded();
    this->data[++this->top] = data;
    this->currentSize++;
}

template <class T>
T Stack<T>::pop() {
    T data = this->data[this->top--];
    this->currentSize--;
    return data;
}

template <class T>
T Stack<T>::peek() {
    T data = this->data[this->top];
    return data;
}

template <class T>
bool Stack<T>::isEmpty() {
    return this->top <= 0;
}


template <class T>
int Stack<T>::size() {
    return this->currentSize;
}


template <class T>
void Stack<T>::print() {
    for (int i = this->top; i >= 0; i--)
    {
        cout << this->data[i] << " -> ";
    }
    cout << "null" << endl;
}


void playWithStack() {
    Stack<int> *st = new Stack<int>();
    cout << "is it empty ? " << st->isEmpty() << endl;
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    cout << "is it empty ? " << st->isEmpty() << endl;
    st->print();
    cout << "size before first pop : " << st->size() << endl;
    cout << "poped value is : " << st->pop() << endl;
    cout << "size after first pop : " << st->size() << endl;
    st->print();

}
