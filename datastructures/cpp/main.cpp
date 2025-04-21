#include "main.h"

int main() {
  // LinkedList *numbers = new LinkedList();
  // numbers->inserLast(1);
  // numbers->inserLast(2);
  // numbers->inserLast(3);
  // numbers->inserLast(4);
  // numbers->insertAfterIdx(47, 1);
  // numbers->insertBeforeIdx(50, 1);
  // numbers->deleteNodeByIdx(1);
  // numbers->deleteNodeByValue(4);
  // numbers->printList();
  LinkedList list;

  cout << "Initial list (should be empty):\n";
  list.printList();

  // Insert at last
  cout << "\nInserting at last:\n";
  list.inserLast(10);
  list.inserLast(20);
  list.inserLast(30);
  list.printList();

  // Insert after index
  cout << "\nInserting 25 after index 1:\n";
  list.insertAfterIdx(25, 1);
  list.printList();

  // Insert before index
  cout << "\nInserting 5 before index 0:\n";
  list.insertBeforeIdx(5, 0);
  list.printList();

  // Insert after value
  cout << "\nInserting 35 after value 30:\n";
  list.insertAfterValue(35, 30);
  list.printList();

  // Insert before value
  cout << "\nInserting 15 before value 20:\n";
  list.insertBeforeValue(15, 20);
  list.printList();

  // Search by value
  cout << "\nSearching for value 25:\n";
  LinkedListNode* found = list.find(25);
  if (found) {
      cout << "Found node with value: " << found->data << "\n";
  } else {
      cout << "Value not found!\n";
  }

  // Get by index
  cout << "\nGetting node at index 3:\n";
  LinkedListNode* nodeAt3 = list.get(3);
  if (nodeAt3) {
      cout << "Node at index 3 has value: " << nodeAt3->data << "\n";
  } else {
      cout << "Invalid index!\n";
  }

  // Delete node by index
  cout << "\nDeleting node at index 2:\n";
  list.deleteNodeByIdx(2);
  list.printList();

  // Delete node by value
  cout << "\nDeleting node with value 20:\n";
  list.deleteNodeByValue(20);
  list.printList();

  // Edge cases
  cout << "\nTrying to delete node at invalid index 100:\n";
  list.deleteNodeByIdx(100);
  list.printList();

  cout << "\nTrying to delete non-existent value 999:\n";
  list.deleteNodeByValue(999);
  list.printList();

  cout << "\nClearing the entire list:\n";
  while (list.head != nullptr) {
      list.deleteNodeByIdx(0);
  }
  list.printList();

  cout << "\nTrying to delete from an empty list:\n";
  list.deleteNodeByValue(10);  // Should handle gracefully.
  list.deleteNodeByIdx(0);     // Should handle gracefully.
  return (0);
}
