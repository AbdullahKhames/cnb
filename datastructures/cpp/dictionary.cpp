#include "dictionary.h"

template <class T, class V>
void Dictionary<T, V>::increaseSizeIfNeeded() {
    if (this->currentSize != this->totalSize)
    {
        return;
    }
    this->totalSize += this->currentSize;
    KeyValuePair **newArray = new KeyValuePair*[this->totalSize];
    for (int i = 0; i < this->totalSize; ++i) {
        newArray[i] = nullptr; 
    }
    std::copy(this->entries, this->entries + this->currentSize, newArray);
    this->entries = newArray;
}


template<class T, class V>
int Dictionary<T, V>::size() const{
    return this->currentSize;
}

template <class T, class V>
void Dictionary<T, V>::set(T key, V value) {
    this->increaseSizeIfNeeded();
    for (int i = 0; i < this->totalSize; i++)
    {
        if (this->entries[i] && key == this->entries[i]->getKey())
        {
            this->entries[i]->setValue(value);
            return;
        }
    }
    KeyValuePair *newPair = new KeyValuePair(key, value);
    this->entries[this->currentSize++] = newPair;
}

template <class T, class V>
optional<V> Dictionary<T, V>::get(T key) const {
    for (int i = 0; i < this->totalSize; i++)
    {
        if (this->entries[i] && key == this->entries[i]->getKey())
        {
            return this->entries[i]->getValue();
        }
    }
    return std::nullopt;
}

template <class T, class V>
bool Dictionary<T, V>::remove(T key) {
    for (int i = 0; i < this->totalSize; i++)
    {
        if (this->entries[i] && key == this->entries[i]->getKey())
        {
            int lastIndex = this->currentSize - 1;
            this->entries[i] = this->entries[lastIndex];
            // if constexpr (std::is_pointer_v<V>) {
            //     this->entries[lastIndex] = nullptr;
            // } else if constexpr (std::is_class_v<V>) {
            //     this->entries[lastIndex] = KeyValuePair();
            // } else {
            //     this->entries[lastIndex] = KeyValuePair();
            // }
            this->entries[lastIndex] = nullptr;
            this->currentSize--;
            return true;
        }
    }
    return false;
}

template <class T, class V>
void Dictionary<T, V>::print() const {
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

void playWithDictionary() {
    Dictionary<int, string> *dict = new Dictionary<int, string>();
    dict->set(10, "hamada");
    cout << "size is : " << dict->size() << endl;
    cout << "get key found should be hamada : " << dict->get(10).value() << endl;
    auto val = dict->get(12);
    if (val.has_value())
    {
        cout << "get key found: " << val.value() << endl;
    }
    else
    {
        cout << "get key 12 not found" << endl;
    }
    dict->set(11, "hamada1");
    dict->set(12, "hamada2");
    dict->set(13, "hamada3");
    dict->set(14, "hamada4");
    dict->set(15, "hamada5");
    dict->print();

    dict->remove(10);
    dict->remove(11);
    dict->remove(12);
    dict->remove(13);
    dict->remove(14);
    dict->remove(15);
    dict->print();
    
    dict->set(15, "hamada5");
    dict->print();
}
