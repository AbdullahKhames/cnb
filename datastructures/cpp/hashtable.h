#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hash.h"
template <class T, class V>
class HashTable {
    private:
        Hash hasher;
        class KeyValuePair {
            private:
                T key;
                V value;
                bool valid;

                friend class HashTable<T, V>; 

            public:
                T getKey() const { return this->key; } 
                V getValue() const { return this->value; }
                void setValue(V newVal) { this->value = newVal; }
                bool isValid() const { return valid; }

                KeyValuePair() : key(), value(), valid(false) {} 

                KeyValuePair(T key, V value) : key(key), value(value), valid(true) {}
        };

        KeyValuePair** entries;
        int totalSize;
        int currentSize;

        void increaseSizeIfNeeded();

    public:
        HashTable() {
            this->currentSize = 0;
            this->totalSize = 21;

            // 1. Allocate the array of pointers (size = totalSize)
            entries = new KeyValuePair*[this->totalSize]; 

            // 2. Initialize each pointer in the array to nullptr
            //    This indicates that no KeyValuePair object is currently 
            //    allocated at this index.
            for (int i = 0; i < this->totalSize; ++i) {
                entries[i] = nullptr; 
            }
        }

        // --- Destructor ---
        ~HashTable() {
            for (int i = 0; i < this->totalSize; ++i) {
                if (entries[i] != nullptr) { 
                    delete entries[i];
                    entries[i] = nullptr;
                }
            }
            delete[] entries; 
            entries = nullptr;
        }

        int size() const;
        void set(T key, V value);
        void addToEntries(T key, V value);
        std::optional<V> get(T key);
        bool remove(T key);
        void print() const;
        int hash(T key);
        int collisionHandling(T key, int hash, bool set);
};

void playWithHashTable();
#endif
