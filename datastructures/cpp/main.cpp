#include "main.h"

int main() {
  LinkedList *numbers = new LinkedList();
  numbers->inserLast(1);
  numbers->inserLast(2);
  numbers->inserLast(3);
  numbers->inserLast(4);
  numbers->insertAfterIdx(47, 1);
  numbers->insertBeforeIdx(50, 1);
  numbers->deleteNodeByIdx(1);
  numbers->deleteNodeByValue(4);
  numbers->printList();
  
  return (0);
}
