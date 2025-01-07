#include "../include/double_linked_list.h"

using namespace std;

int main() {
  DoubleLinkedList<int> dll;

  dll.push(4);
  dll.push(5);

  dll.append(9);

  dll.display();
}
