#include "../include/doubly_linked_list.h"

using namespace std;

int main() {
  DoublyLinkedList<int> dll;

  dll.push(4);
  dll.push(5);
  dll.push(6);
  dll.push(7);
  dll.push(8);

  dll.append(9);

  dll.display();

  dll.insert(25, 2);
  dll.display();

  dll.deleteNode(25);
  dll.display();

  dll.removeHead();
  dll.display();

  dll.removeHead();
  dll.display();

  dll.removeTail();
  dll.display();

  dll.deleteNode(4);
  dll.display();
}
