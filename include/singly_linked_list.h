#pragma once

#include "single_node.h"

using namespace std;

template <typename T> class SinglyLinkedList {
private:
  Node<T> *head, *tail;
  int length;

public:
  SinglyLinkedList();

  bool isEmpty();

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeNode(T node);

  bool removeHead();

  // FIX: Add the `removeTail()` function.

  bool deleteNode(T position);

  void display();

  int getLength();
};
