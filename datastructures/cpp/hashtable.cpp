#include "hashtable.h"

template <class T, class V>
void HashTable<T, V>::increaseSizeIfNeeded() {
    if (this->currentSize != this->totalSize)
    {
        return;
    }
    int current = this->currentSize;
    KeyValuePair **copyArray = new KeyValuePair*[this->currentSize];
    for (int i = 0; i < this->currentSize; ++i) {
        copyArray[i] = this->entries[i]; 
    }
    this->totalSize *= 2;
    cout << "resize from " << this->currentSize << " to " << this->totalSize << endl;
    KeyValuePair **newArray = new KeyValuePair*[this->totalSize];
    for (int i = 0; i < this->totalSize; ++i) {
        newArray[i] = nullptr; 
    }
    this->entries = newArray;
    this->currentSize = 0;
    for (int i = 0; i < current; i++)
    {
        if (copyArray[i] != nullptr)
        {
            this->addToEntries(copyArray[i]->key, copyArray[i]->value);
        }
        
    }
}

template<class T, class V>
int HashTable<T, V>::hash(T key) {
    uint32_t  hashVal = this->hasher.hash32(key);
    return hashVal % this->totalSize;
}
template<class T, class V>
int HashTable<T, V>::collisionHandling(T key, int hash, bool set) {

    cout << " collision occured old hash value ! " << hash << endl; 
    int newHash = -1;
    for (int i = 1; i < this->totalSize; i++) {
        newHash = (hash + i) % this->totalSize;
  
        if (set && (
            (this->entries[newHash] == nullptr) ||
                    this->entries[newHash]->key == key
                )) {
        cout << " collision occured newHash value ! " << newHash << endl; 
          return newHash;
        } else if (!set && this->entries[newHash] && this->entries[newHash]->key == key) {
            cout << " collision occured newHash value ! " << newHash << endl; 
            return newHash;
        }
    }

    return -1;
    
}

template<class T, class V>
int HashTable<T, V>::size() const{
    return this->currentSize;
}

template <class T, class V>
void HashTable<T, V>::addToEntries(T key, V value) {
    int hash = this->hash(key);
    if (this->entries[hash] != nullptr && this->entries[hash]->key != key)
    {
        hash = this->collisionHandling(key, hash, true);
    }
    if (hash == -1)
    {
        throw new runtime_error("invalid hashtable!");
    }
    if (this->entries[hash] == nullptr)
    {
        KeyValuePair *newPair = new KeyValuePair(key, value);
        this->entries[hash] = newPair;
        this->currentSize++;
    } else if (this->entries[hash]->key == key)
    {
        this->entries[hash]->value = value;
    } else {
        throw new runtime_error("invalid hashtable!");
    }
}

template <class T, class V>
void HashTable<T, V>::set(T key, V value) {
    this->increaseSizeIfNeeded();
    this->addToEntries(key, value);
}

template <class T, class V>
optional<V> HashTable<T, V>::get(T key) {
    int hash = this->hash(key);
    if (this->entries[hash] == nullptr)
    {
        return std::nullopt;
    }
    if (this->entries[hash]->key != key)
    {
        hash = this->collisionHandling(key, hash, false);
    }
    if (hash == -1)
    {
        return std::nullopt;
    }
    
    return this->entries[hash]->value;
}

template <class T, class V>
bool HashTable<T, V>::remove(T key) {
    int hash = this->hash(key);
    if (this->entries[hash] == nullptr)
    {
        return false;
    }
    if (this->entries[hash]->key != key)
    {
        hash = this->collisionHandling(key, hash, false);
    }
    if (hash == -1)
    {
        return false;
    }
    if (this->entries[hash] != nullptr && 
        this->entries[hash]->key == key)
    {
        KeyValuePair *temp = this->entries[hash];
        this->entries[hash] = nullptr;
        delete temp;
        this->currentSize--;
        return true;
    }
    return false;
}

template <class T, class V>
void HashTable<T, V>::print() const {
    cout << "----------------------" << endl;
    cout << "size : " << this->currentSize << endl;

    for (int i = 0; i < this->totalSize; i++)
    {
        if (this->entries[i] != nullptr)
        {
            cout  << "[ " << i  << " ] : "
            << "( "
            << this->entries[i]->getKey() 
            << " : " 
            << this->entries[i]->getValue() 
            << " )"
            << endl ;
        } else {
            cout  << "[ " << i  << " ] : null"
            << endl ;
        }
        
    }
    cout << "----------------------" << endl;


}

void playWithHashTable() {
    HashTable<string, string> *table = new HashTable<string, string>();
    table->print();
    table->set("Sinar", "sinar@gmail.com");
    table->set("Elvis", "elvis@gmail.com");
    table->set("Tane", "tane@gmail.com");
    table->print();
    auto val = table->get("Sinar");
    if (val.has_value())
    {
        cout << "get key found: " << val.value() << endl;
    }
    else
    {
        cout << "get key 12 not found" << endl;
    }

    table->set("Gerti", "gerti@gmail.com");
    table->set("Arist", "arist@gmail.com");
    table->print();
    table->remove("Sinar");
    val = table->get("Sinar");
    if (val.has_value())
    {
        cout << "get key found: " << val.value() << endl;
    }
    else
    {
        cout << "get key 12 not found" << endl;
    }
    table->print();
}
