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

  dll.insert(25, 6);
  cout << dll << endl;

  dll.deleteNode(0);
  cout << dll << endl;

  dll.deleteNode(6);
  cout << dll << endl;

  dll.deleteNode(5);
  cout << dll << endl;

  dll.deleteNode(3);
  cout << dll << endl;

  dll.removeTail();
  cout << dll << endl;
}
