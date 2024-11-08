#include "main.h"

int main() {
    Node<string>* head = createLinkedList(string("ahmed"));
    addToLinkedList(head,string("abdullah"));
    addToLinkedList(head,string("mohamed"));
    addToLinkedList(head,string("amr"));
    addToLinkedList(head,string("mahmoud"));
    printLinkedList(head);
    head = deleteFromLinkedList(head, 4);
    printLinkedList(head);
    // Node* node = getFromLinkedList(head, 4);
    // if (node) {
    //     cout << node->data << endl;
    // }
    return (0);
}
