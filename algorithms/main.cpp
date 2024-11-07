#include "main.h"

int main() {
    StringNode *head = createStringLinkedList("ahmed");
    addToStringLinkedList(head, "abdullah");
    addToStringLinkedList(head, "mohamed");
    addToStringLinkedList(head, "amr");
    addToStringLinkedList(head, "mahmoud");
    printStringLinkedList(head);
    head = deleteFromStringLinkedList(head, 4);
    printStringLinkedList(head);
    // StringNode* node = getFromStringLinkedList(head, 4);
    // if (node) {
    //     cout << node->data << endl;
    // }
    return (0);
}
