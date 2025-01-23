/**
 * @file doubly_linked_list.h
 * @brief Defines the DoublyLinkedList class.
 */

#pragma once

#include "double_node.h"

template <typename T> class DoublyLinkedList {
private:
  DNode<T> *head, *tail;
  int length;

public:
  DoublyLinkedList();

  bool isEmpty();

  int getLength();

  DNode<T> *getHead();

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeHead();

  bool removeTail();

  bool removeNode(DNode<T> *node);

  bool deleteNode(int index);

  void display();
};

#include "../templates/doubly_linked_list.tpp"
