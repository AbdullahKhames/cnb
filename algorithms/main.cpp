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
    primsMST();
    return (0);
}
