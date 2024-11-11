#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../main.h"

template <typename KeyType>
unsigned long hashKey(KeyType key, long int size) {
    hash<KeyType> hasher;
    return hasher(key) % size;
}

template <typename KeyType, typename ValueType>
Hashtable<KeyType, ValueType>* createHashTable() {
    Hashtable<KeyType, ValueType>* table = (Hashtable<KeyType, ValueType>*) malloc(sizeof(Hashtable<KeyType, ValueType>));
    table->size = ARRAY_SIZE;
    table->count = 0;
    table->array = (Node<HashtableItem<KeyType, ValueType>*>**) calloc(table->size, sizeof(Node<HashtableItem<KeyType, ValueType>*>*));

    for (int i = 0; i < table->size; i++)
        table->array[i] = NULL;

    return table;

}

template <typename KeyType, typename ValueType>
void put(Hashtable<KeyType, ValueType> *table, KeyType key, ValueType value) {
    if (!table || !table->array || !key) {
        return;
    }
    unsigned long hash  = hashKey<KeyType>(key, table->size);
    HashtableItem<KeyType, ValueType> *item = (HashtableItem<KeyType, ValueType>*) malloc(sizeof(HashtableItem<KeyType, ValueType>));
    item->key = key;
    item->value = value;
    Node<HashtableItem<KeyType, ValueType>*> *newnode = (Node<HashtableItem<KeyType, ValueType>*>*)malloc(sizeof(Node<HashtableItem<KeyType, ValueType>*>));
    newnode->data = item;
    newnode->next = NULL;
    if (table->array[hash] == NULL)
    {
        table->array[hash] = newnode;
        table->count++;
    }else {
        Node<HashtableItem<KeyType, ValueType>*> *temp = table->array[hash];
        while (temp->next)
        {
            if (temp->data->key == key)
            {
                temp->data->value == value;
                free(item);
                free(newnode);
                return;
            }
            temp = temp->next;
        }

        if (temp->data->key == key)
        {
            temp->data->value == value;
            free(item);
            free(newnode);
            return;
        }
        temp->next = newnode;
        table->count++;
    }
}

template <typename KeyType, typename ValueType>
ValueType* get(Hashtable<KeyType, ValueType> *table,  KeyType key){
    if (!table || !table->array || !key) {
        return NULL;
    }
    unsigned long hash  = hashKey<KeyType>(key, table->size);
    if (table->array[hash] == NULL)
    {
        return NULL;
    }else {
        Node<HashtableItem<KeyType, ValueType>*> *temp = table->array[hash];
        while (temp)
        {
            if (temp->data->key == key)
            {
                return &temp->data->value;
            }
            
            temp = temp->next;
        }
        return NULL;
    }
    return NULL;
}

template <typename KeyType, typename ValueType>
void print(Hashtable<KeyType, ValueType> *table) {
    if (!table || !table->array) {
        return;
    }

    for (int i = 0; i < table->size; i++)
    {
        if (table->array[i] != NULL)
        {
            Node<HashtableItem<KeyType, ValueType> *> *temp = table->array[i];
            cout << "index " << i << " node contains  (key -> value) pairs : ";
            while (temp)
            {
                cout << "(" << temp->data->key << " -> " << temp->data->value  << ")";;
                if (temp->next)
                {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

template <typename KeyType, typename ValueType>
void deleteFromHashTable(Hashtable<KeyType, ValueType> *table, KeyType key) {
    if (!table || !table->array || !key) {
        return;
    }
    unsigned long hash = hashKey<KeyType>(key, table->size);
    Node<HashtableItem<KeyType, ValueType>*> *prev = table->array[hash];
    if (prev && prev->next)
    {
        if (prev->data->key == key)
        {
            table->array[hash] = prev->next;
            free(prev->data);
            free(prev);
            table->count--;
            return;
        }
        Node<HashtableItem<KeyType, ValueType>*> *temp = prev->next;
        
        while (prev && temp)
        {
            if (temp->data->key == key)
            {
                prev->next = temp->next;
                free(temp->data);
                free(temp);
                table->count--;
                return;
            }
            temp = temp->next;
            prev = prev->next;
        }
    }else if (prev)
    {
        free(prev->data);
        free(prev);
        table->count--;
        table->array[hash] = NULL;
    }
    
}

#endif
