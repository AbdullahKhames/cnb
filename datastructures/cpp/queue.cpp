#include "queue.h"

template <class T>
Queue<T>::Queue() {
    this->list = new GnericDoublyLinkedList<T>();
    this->currentSize = 0;
}

template <class T>
void Queue<T>::enqueue(T data) {
    currentSize++;
    this->list->inserLast(data);
}

template <class T>
T Queue<T>::dequeue() {
    if (this->isEmpty()) {
        throw std::logic_error("Queue is empty!");
    }

    T val = this->list->head->data;
    this->list->deleteHead();
    currentSize--;

    return val;
}

template <class T>
T Queue<T>::peek() {
    return list->head->data;
}

template <class T>
bool Queue<T>::isEmpty() {

    return this->currentSize <= 0;
}


template <class T>
int Queue<T>::size() {
    return this->currentSize;
}


template <class T>
void Queue<T>::print() {
    this->list->printList();
}





void playWithQueue() {
    Queue<int> *queue = new Queue<int>();
    cout << "is empty should be true : " << queue->isEmpty() << endl;

    queue->enqueue(8);
    queue->enqueue(16);
    queue->enqueue(32);
    queue->enqueue(64);
    cout << "is empty should be false : " << queue->isEmpty() << endl;
    cout << "peek : " << queue->peek() << endl;

    queue->print();

    cout << "size before dequeu : " << queue->size() << endl;

    while (!queue->isEmpty())
    {
        cout << "peek : " << queue->peek() << endl;
        cout << "first dequeu : " << queue->dequeue() << endl;
        cout << "size after dequeu : " << queue->size() << endl;    
    }
    
}

template <class T>
QueueArray<T>::QueueArray() {
    this->totalSize = 3;
    this->head = -1;
    this->tail = -1;
    this->currentSize = 0;
    this->list = new T[this->totalSize];
}

template <class T>
bool QueueArray<T>::increaseSizeIfNeeded() {
    if (this->currentSize == this->totalSize)
    {
        this->totalSize *= 2;
        // cout << "increasing the size from " << this->currentSize << " to " << this->totalSize << endl;

        T *newArray = new T[this->totalSize];
        for (int i = 0; i <= this->tail; i++)
        {
            newArray[i] = this->list[i];
        }
        if (this->head > this->tail)
        {
            int j = 1;
            int diff = this->currentSize - j;
            while (diff >= this->head)
            {
                newArray[this->totalSize - j] = this->list[diff];
                j++;
                diff = this->currentSize - j;
            }
            this->head = this->totalSize - this->currentSize + this->head;
        }
        delete [] this->list;
        this->list = newArray;
        // this->debug();
        return true;
    }
    return false;
}
template <class T>
void QueueArray<T>::enqueue(T data) {
    int lastSize = this->totalSize;
    bool increased = this->increaseSizeIfNeeded();
    currentSize++;
    if (this->head == -1 && this->tail == -1) {
        this->head = 0;
        this->tail = 0;
        this->list[0] = data;
        return;
    } else if (this->tail + 1 == this->totalSize)
    {
        // cout << "resetting tail val due to tail is : "<< this->tail  << " and total size is " << this->totalSize << endl;
        this->tail = -1;
    }
    this->list[++this->tail] = data;
    // this->debug();
}

template <class T>
T QueueArray<T>::dequeue() {
    if (this->isEmpty()) {
        throw std::logic_error("Queue is empty!");
    }
    T val = this->list[this->head];
    currentSize--;
    this->list[this->head] = -1;
    if (this->head == this->tail)
    {
        this->head = -1;
        this->tail = -1;
    } else if (this->head + 1 == this->totalSize)
    {
        this->head = 0;
    } else {
        this->head++;
    }
    // this->debug();
    return val;
}

template <class T>
T QueueArray<T>::peek() {
    return this->list[this->head];
}

template <class T>
bool QueueArray<T>::isEmpty() {
    return this->currentSize <= 0;
}


template <class T>
int QueueArray<T>::size() {
    return this->currentSize;
}

template <class T>
void QueueArray<T>::print() {
    if (this->head > this->tail)
    {
        for (int i = this->head; i < this->totalSize; i++)
        {
            cout << this->list[i] << " -> ";
        }
        for (int i = 0; i <= this->tail; i++)
        {
            cout << this->list[i] << " -> ";
        }
    } else {
        for (int i = this->head; i <= this->tail; i++)
        {
            cout << this->list[i] << " -> ";
        }
    }
    cout << " null " << endl;
}
template <class T>
void QueueArray<T>::debug() {
    cout << "debugging logs ";
    cout << "head value is : " << this->head << " and tail value is " <<this->tail  << " array values are : ";
    for (int i = 0; i < this->totalSize; i++)
    {
        cout << this->list[i] << " -> ";
    }
    cout << " null end debugging logs " << endl;
}
void playWithQueueArray() {
    QueueArray<int> queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    // Print the queue
    queue.print();

    // Dequeue an element
    int dequeued = queue.dequeue();
    std::cout << "Dequeued element: " << dequeued << std::endl;

    // Peek at the front element
    int front = queue.peek();
    std::cout << "Front element: " << front << std::endl;

    // Print the queue after dequeue
    queue.print();

    queue.enqueue(78);
    queue.enqueue(25);
    queue.enqueue(41);
    queue.print();
    while (!queue.isEmpty())
    {
        cout << "peek : " << queue.peek() << endl;
        cout << "first dequeu : " << queue.dequeue() << endl;
        cout << "size after dequeu : " << queue.size() << endl;    
    }

}
