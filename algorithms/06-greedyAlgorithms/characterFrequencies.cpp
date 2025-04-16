#include "../utils/hashtable.h"
#include "../main.h"
#include <string>

Hashtable<char, int>* charFreqTable(string message) {
    Hashtable<char, int>* table = createHashTable<char, int>();
    for (size_t i = 0; i < message.length(); ++i) {
        int* repeated = get(table, message[i]);
        if (repeated == NULL) {
            put(table, message[i], 1);
        } else {
            put(table, message[i], (*repeated) + 1);
        }
     }
    return table;
}
