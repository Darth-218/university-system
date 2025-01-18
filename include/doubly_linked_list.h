#pragma once

#include "double_node.h"
using namespace std;

template <typename T> class DoublyLinkedList {
private:
  Node<T> *head, *tail;
  int length;

public:
  DoublyLinkedList();

  bool isEmpty();

  int getLength();

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeHead();

  bool removeTail();

  bool removeNode(Node<T> *node);

  bool deleteNode(int index);

  void display();
};

#include "../templates/doubly_linked_list.tpp"
