#include "main.h"

int main() {
    Node<const char*>* head = createLinkedList("ahmed");
    addToLinkedList(head,("abdullah"));
    addToLinkedList(head,("mohamed"));
    addToLinkedList(head,("amr"));
    addToLinkedList(head,("mahmoud"));
    printLinkedList(head);
    head = deleteFromLinkedList(head, 4);
    printLinkedList(head);
    // Node* node = getFromLinkedList(head, 4);
    // if (node) {
    //     cout << node->data << endl;
    // }
    return (0);
}
