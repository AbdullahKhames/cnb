#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "linkedList.h"
#include <iostream>

const long int ARRAY_SIZE = 1024;

struct StringHashtableItem {
    const char* key;
    const char* value;
};
struct StringHashtable {
    Node<StringHashtableItem*> **array;
    long int size;
    int count;
};


unsigned long hash_djb2(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

unsigned long hashString(const char* key, long int size) {
    return hash_djb2(key) % size;
}


StringHashtable* createHashTable() {
    StringHashtable* table = (StringHashtable*) malloc(sizeof(StringHashtable));
    table->size = ARRAY_SIZE;
    table->count = 0;
    table->array = (Node<StringHashtableItem*>**) calloc(table->size, sizeof(Node<StringHashtableItem*>*));

    for (int i = 0; i < table->size; i++)
        table->array[i] = NULL;

    return table;

}

void put(StringHashtable *table, const char* key, const char* value) {
    if (!table || !table->array || !key) {
        return;
    }
    long int hash  = hashString(key, table->size);
    StringHashtableItem *item = (StringHashtableItem*) malloc(sizeof(StringHashtableItem));
    item->key = key;
    item->value = value;
    Node<StringHashtableItem*> *newnode = (Node<StringHashtableItem*>*)malloc(sizeof(Node<StringHashtableItem*>));
    newnode->data = item;
    newnode->next = NULL;
    if (table->array[hash] == NULL)
    {
        table->array[hash] = newnode;
        table->count++;
    }else {
        Node<StringHashtableItem*> *temp = table->array[hash];
        while (temp->next)
        {
            if (temp->data->key == key)
            {
                temp->data->value == value;
                table->count++;
                return;
            }
            temp = temp->next;
        }

        if (temp->data->key == key)
        {
            temp->data->value == value;
            table->count++;
            return;
        }
        temp->next = newnode;
        table->count++;
    }
}

const char* get(StringHashtable *table, const char* key){
    if (!table || !table->array || !key) {
        return NULL;
    }
    long int hash  = hashString(key, table->size);
    if (table->array[hash] == NULL)
    {
        return NULL;
    }else {
        Node<StringHashtableItem*> *temp = table->array[hash];
        while (temp)
        {
            if (temp->data->key == key)
            {
                return temp->data->value;
            }
            
            temp = temp->next;
        }
        return NULL;
    }
    return NULL;
}

void print(StringHashtable *table) {
    if (!table || !table->array) {
        return;
    }

    for (int i = 0; i < table->size; i++)
    {
        if (table->array[i] != NULL)
        {
            Node<StringHashtableItem *> *temp = table->array[i];
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
void printStringHashtable(StringHashtable *table) {
    if (!table || !table->array) {
        return;
    }
    cout << "{";
    bool firstItem = true;
    for (int i = 0; i < table->size; i++)
    {
        Node<StringHashtableItem *> *temp = table->array[i];
        while (temp)
        {
            if (!firstItem)
            {
                cout << ", ";
            }
            cout << "'" << temp->data->key << "': '" << temp->data->value  << "'";
            firstItem = false;
            temp = temp->next;
        }
    }
    cout << "}" << endl;
}

void deleteFromStringHashTable(StringHashtable *table, const char * key) {
    if (!table || !table->array || !key) {
        return;
    }
    long int hash = hashString(key, table->size);
    Node<StringHashtableItem*> *prev = table->array[hash];
    if (prev && prev->next)
    {
        if (prev->data->key == key)
        {
            table->array[hash] = prev->next;
            free(prev->data);
            free(prev);
            return;
        }
        Node<StringHashtableItem*> *temp = prev->next;
        
        while (prev && temp)
        {
            if (temp->data->key == key)
            {
                prev->next = temp->next;
                free(temp->data);
                free(temp);
                return;
            }
            temp = temp->next;
            prev = prev->next;
        }
    }else if (prev)
    {
        free(prev->data);
        free(prev);
        table->array[hash] = NULL;
    }
    
}
#endif
