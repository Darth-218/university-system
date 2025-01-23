/**
 * @file single_node.h
 * @brief Defines the SinglyLinkedList class.
 */

#pragma once

#include "single_node.h"

using namespace std;

template <typename T> class SinglyLinkedList {
private:
  SNode<T> *head, *tail;
  int length;

public:
  SinglyLinkedList();

  SNode<T> *getHead();

  bool isEmpty();

  bool append(T value);

  bool insert(T value, int position);

  bool push(T value);

  bool removeNode(SNode<T> *node);

  bool removeHead();

  bool removeTail();

  bool deleteNode(int position);

  void display();

  int getLength();
};

#include "../templates/singly_linked_list.tpp"
