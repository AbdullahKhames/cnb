#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../main.h"

template <typename KeyType>
unsigned long hashKey(KeyType key, long int size)
{
    hash<KeyType> hasher;
    return hasher(key) % size;
}

template <typename KeyType, typename ValueType>
Hashtable<KeyType, ValueType> *createHashTable()
{
    Hashtable<KeyType, ValueType> *table = (Hashtable<KeyType, ValueType> *)malloc(sizeof(Hashtable<KeyType, ValueType>));
    table->size = ARRAY_SIZE;
    table->count = 0;
    table->array = (Node<HashtableItem<KeyType, ValueType> *> **)calloc(table->size, sizeof(Node<HashtableItem<KeyType, ValueType> *> *));

    for (int i = 0; i < table->size; i++)
        table->array[i] = NULL;

    return table;
}

template <typename KeyType, typename ValueType>
void put(Hashtable<KeyType, ValueType> *table, KeyType key, ValueType value)
{
    if (!table || !table->array || !key)
    {
        return;
    }
    ValueType *val = get(table, key);
    if (val)
    {
        *val = value;
        return;
    }

    unsigned long hash = hashKey<KeyType>(key, table->size);
    HashtableItem<KeyType, ValueType> *item = (HashtableItem<KeyType, ValueType> *)malloc(sizeof(HashtableItem<KeyType, ValueType>));
    item->key = key;
    item->value = value;
    Node<HashtableItem<KeyType, ValueType> *> *newnode = (Node<HashtableItem<KeyType, ValueType> *> *)malloc(sizeof(Node<HashtableItem<KeyType, ValueType> *>));
    newnode->data = item;
    newnode->next = NULL;
    if (table->array[hash] == NULL)
    {
        table->array[hash] = newnode;
        table->count++;
    }
    else
    {
        Node<HashtableItem<KeyType, ValueType> *> *temp = table->array[hash];
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
ValueType *get(Hashtable<KeyType, ValueType> *table, KeyType key)
{
    if (!table || !table->array || !key)
    {
        return NULL;
    }
    unsigned long hash = hashKey<KeyType>(key, table->size);
    if (table->array[hash] == NULL)
    {
        return NULL;
    }
    else
    {
        Node<HashtableItem<KeyType, ValueType> *> *temp = table->array[hash];
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
void print(Hashtable<KeyType, ValueType> *table)
{
    if (!table || !table->array)
    {
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
                cout << "(" << temp->data->key << " -> " << temp->data->value << ")";
                ;
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
void deleteFromHashTable(Hashtable<KeyType, ValueType> *table, KeyType key)
{
    if (!table || !table->array || !key)
    {
        return;
    }
    unsigned long hash = hashKey<KeyType>(key, table->size);
    Node<HashtableItem<KeyType, ValueType> *> *prev = table->array[hash];
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
        Node<HashtableItem<KeyType, ValueType> *> *temp = prev->next;

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
    }
    else if (prev)
    {
        free(prev->data);
        free(prev);
        table->count--;
        table->array[hash] = NULL;
    }
}

template <typename KeyType, typename ValueType>
void deleteHashTable(Hashtable<KeyType, ValueType> *table)
{
    if (!table || !table->array)
    {
        return;
    }
    for (int i = 0; i < table->size; i++)
    {
        Node<HashtableItem<KeyType, ValueType> *> *firstNode = table->array[i];
        if (firstNode)
        {
            Node<HashtableItem<KeyType, ValueType> *> *temp = firstNode->next;
            while (temp)
            {
                Node<HashtableItem<KeyType, ValueType> *> *next = temp->next;
                HashtableItem<KeyType, ValueType> *data = temp->data;
                if (data)
                {
                    delete data;
                }
                delete temp;
                temp = next;
            }
            HashtableItem<KeyType, ValueType> *data = firstNode->data;
            if (data)
            {
                delete data;
            }
            delete firstNode;
        }
    }

    delete table->array;
    delete table;
}

template <typename KeyType, typename ValueType>
int **toIntTwoDimensionsArray(Hashtable<KeyType, ValueType> *table)
{
    if (!table || !table->array)
    {
        return nullptr;
    }
    int **arr = (int **)malloc(table->count * sizeof(int *));
    for (int i = 0; i < table->count; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }
    int arrIdx = 0;
    for (int i = 0; i < table->size; i++)
    {
        Node<HashtableItem<KeyType, ValueType> *> *temp = table->array[i];
        while (temp)
        {
            HashtableItem<KeyType, ValueType> *data = temp->data;
            if (data)
            {
                arr[arrIdx][0] = data->key;
                arr[arrIdx][1] = data->value;
                arrIdx++;
            }
            temp = temp->next;
        }
    }
    return arr;
}

#endif
