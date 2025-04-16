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

void sortedCharacterFrequencies() {
    Hashtable<char, int>* table = charFreqTable("The output from Huffman's algorithm can be viewed as a variable length code table for encoding a source symbol. The algorithm derives this table from the estimated probability or frequency of occurrence for each possible value of the source symbol. as in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. Huffman's method can be efficiently implemented, finding a code in time linear to the number of input weights if these weights are sorted. However, although optimal among methods encoding symbols separately, Huffman coding is not always optimal among all compression methods it is replaced with arithmetic coding or asymmetric numeral systems if better compression ratio is required.");
    int size = table->count;
    int **arr = toIntTwoDimensionsArray(table);
    print<char, int>(table);
    deleteHashTable<char, int>(table);
    for (size_t i = 0; i < size; i++)
    {
        cout << "key " << (char)arr[i][0] << " value is : " << arr[i][1] << endl;
    }
    mergeSortTwoDimension(arr, size);
    for (size_t i = 0; i < size; i++)
    {
        cout << "key " << (char)arr[i][0] << " value is : " << arr[i][1] << endl;
    }
}
