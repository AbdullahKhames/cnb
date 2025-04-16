#include "main.h"

// void testStringHashhTAble(){
//     StringHashtable *table = createStringHashTable();
//     putStringHashTable(table, "abdullah", "thhhe bestt");
//     putStringHashTable(table, "abdullah1", "thhhe bestt1");
//     putStringHashTable(table, "abdullah2", "thhhe bestt2");
//     putStringHashTable(table, "mohamed", "thhhe bestt1");
//     putStringHashTable(table, "ahmed", "thhhe bestt2");
//     cout << table->count << endl;
//     // const char *def = get(table, "abdullah");
//     // if (def)
//     // {
//     //     cout << def << endl;
//     // }
//     // const char *def1 = get(table, "abdullah1");
//     // if (def1)
//     // {
//     //     cout << def1 << endl;
//     // }
//     printStringHashtable(table);
//     deleteFromStringHashTable(table, "abdullah");
//     printStringHashtable(table);
//     cout << table->count << endl;
// }

void testIntHashhTAble(){
    Hashtable<char, int> *intTable = createHashTable<char, int> ();
    put<char, int>(intTable, 'a', 1);
    put<char, int>(intTable, 'b', 2);
    put<char, int>(intTable, 'c', 3);
    put<char, int>(intTable, 'd', 4);
    cout << intTable->count << endl;

    int *foundVal = get<char, int>(intTable, 'a');
    if (foundVal)
    {
        cout << "value of key a is : " << *foundVal << endl;
    }
    
    int *notFoundVal = get<char, int>(intTable, 'z');
    if (notFoundVal)
    {
        cout << "value of key z is : " << *notFoundVal << endl;
    }
    
    
    print<char, int>(intTable);
    deleteFromHashTable<char, int>(intTable, 'a');
    cout << "after delete" << endl;
    print<char, int>(intTable);
    cout << intTable->count << endl;
}


int main() {
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
    return (0);
}
