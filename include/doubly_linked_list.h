#pragma once

#include "double_node.h"
using namespace std;

template <typename T> class DoublyLinkedList {
private:
  Node<T> *head, *tail;
  // FIX: Add a length attribute.

public:
  DoublyLinkedList();

  bool isEmpty();

  // FIX: Add the function `getLength()`.

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeHead();

  bool removeTail();

  // FIX: Add the function `removeNode()`.

  bool deleteNode(T value);

  void display();
};

#include "../templates/doubly_linked_list.tpp"
