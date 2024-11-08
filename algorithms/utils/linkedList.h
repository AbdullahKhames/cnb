#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* createLinkedList(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
Node<T>* addToLinkedList(Node<T>* head, T data) {
    if (!head)
    {
        return NULL;
    }
    
    Node<T>* newNode = createLinkedList(data);
    Node<T>* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    return newNode;
}

template <typename T>
Node<T>* getFromLinkedList(Node<T>* head, int index) {
    if (!head)
    {
        return NULL;
    }
    
    int count = 0;
    Node<T>* temp = head;
    while (temp)
    {
        if (index == count)
        {
            return temp;
        }
        temp = temp->next;
        count++;
    }
    return NULL;
}

template <typename T>
Node<T>* deleteFromLinkedList(Node<T>* head, int index) {
    // while (current->next != nullptr) {
    //     if (count == index - 1) {
    //         Node<T>* temp = current->next;
    //         current->next = current->next->next;
    //         delete temp;
    //         return head;
    //     }
    //     count++;
    //     current = current->next;
    // }

    if (!head || index < 0)
    {
        return NULL;
    }
    Node<T>* temp = head;
    if (index == 0)
    {
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node<T>* prev = temp;
    temp = temp->next;
    while (prev && temp)
    {
        if (index - 1 == count )
        {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        temp = temp->next;
        prev = prev->next;
        count++;
    }
    cout << "index is higher than count "  << index << " " << count << endl;
    return head;
}

template <typename T>
void printLinkedList(Node<T>* head) {
    if (!head)
    {
        return;
    }
    cout<<"in print" << endl;
    Node<T>* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
#endif
