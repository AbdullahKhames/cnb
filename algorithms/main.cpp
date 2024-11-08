#include "main.h"

int main() {
    StringHashtable *table = createHashTable();
    put(table, "abdullah", "thhhe bestt");
    put(table, "abdullah1", "thhhe bestt1");
    put(table, "abdullah2", "thhhe bestt2");
    put(table, "mohamed", "thhhe bestt1");
    put(table, "ahmed", "thhhe bestt2");
    cout << table->count << endl;
    // const char *def = get(table, "abdullah");
    // if (def)
    // {
    //     cout << def << endl;
    // }
    // const char *def1 = get(table, "abdullah1");
    // if (def1)
    // {
    //     cout << def1 << endl;
    // }
    printStringHashtable(table);
    deleteFromStringHashTable(table, "abdullah");
    printStringHashtable(table);
    return (0);
}
