#pragma once

#include "single_node.h"

using namespace std;

template <typename T> class SinglyLinkedList {
private:
  Node<T> *head, *tail;
  int length;

public:
  SinglyLinkedList();

  Node<T> *getHead();

  bool isEmpty();

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeNode(Node<T> *node);

  bool removeHead();

  bool removeTail();

  bool deleteNode(int position);

  void display();

  int getLength();
};

#include "../templates/singly_linked_list.tpp"
