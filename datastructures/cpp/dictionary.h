#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "base.h"
template <class T, class V>
class Dictionary {
    private:
        class KeyValuePair {
            private:
                T key;
                V value;
                bool valid;

                // Grant Dictionary access to private members
                friend class Dictionary<T, V>; 

            public:
                // Making getters const is good practice
                T getKey() const { return this->key; } 
                V getValue() const { return this->value; }
                void setValue(V newVal) { this->value = newVal; }
                bool isValid() const { return valid; }
                void invalidate() { valid = false; }
                void validate() { valid = true; } // Added for convenience maybe?

                // Default constructor: initializes key/value with their defaults, invalid
                KeyValuePair() : key(), value(), valid(false) {} 

                // Parameterized constructor: initializes with given key/value, valid
                KeyValuePair(T key, V value) : key(key), value(value), valid(true) {}
            };

        KeyValuePair** entries; // Pointer to (an array of) pointers to KeyValuePair
        int totalSize;          // Capacity of the 'entries' array
        int currentSize;        // Number of actual items stored

        void increaseSizeIfNeeded(); // Declaration ok

    public:
        // Constructor
        Dictionary() {
            this->currentSize = 0;
            this->totalSize = 2; // Initial capacity

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
        // REQUIRED to prevent memory leaks when using raw pointers and 'new'
        ~Dictionary() {
            // 1. Delete each KeyValuePair object pointed to by the pointers in the array
            for (int i = 0; i < this->totalSize; ++i) {
                // Only delete if the pointer is not null
                if (entries[i] != nullptr) { 
                    delete entries[i];
                    entries[i] = nullptr; // Optional: good practice to null dangling pointers
                }
            }
            // 2. Delete the array of pointers itself
            delete[] entries; 
            entries = nullptr; // Optional: good practice
        }

        // --- Other Member Functions (Declarations) ---
        int size() const; // Mark const if it doesn't modify the dictionary
        void set(T key, V value);
        std::optional<V> get(T key) const; // Mark const if it doesn't modify
        bool remove(T key);
        void print() const; // Mark const if it doesn't modify

        // --- Rule of Three/Five/Zero ---
        // If you manage raw resources (like memory with new/delete), you often need:
        // 1. Destructor (already added)
        // 2. Copy Constructor
        // 3. Copy Assignment Operator
        // (And potentially Move Constructor/Move Assignment Operator in C++11 onwards)
        // For simplicity, let's disable copying/assignment for now:
        Dictionary(const Dictionary&) = delete; // Disallow copy construction
        Dictionary& operator=(const Dictionary&) = delete; // Disallow copy assignment
        // Add move operations if needed later:
        // Dictionary(Dictionary&&) noexcept;      // Move constructor
        // Dictionary& operator=(Dictionary&&) noexcept; // Move assignment
};

void playWithDictionary();
#endif
