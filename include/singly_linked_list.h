
#include "single_node.h"
#include <iostream>
using namespace std;


template <typename T> class SingleLinkedList {
private:
  Node<T> *head, *tail;

public:
  SingleLinkedList();

  bool isEmpty();

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeHead();

  bool deleteNode(T value);

  void display();
};
