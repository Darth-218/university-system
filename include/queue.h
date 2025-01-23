/**
 * @file queue.h
 * @brief Defines the Queue class.
 */

#pragma once

#include "includes.h"
#include "single_node.h"

template <typename T> class Queue {
private:
  SNode<T> *rear, *front;
  int size;

public:
  Queue();

  bool isEmpty();

  bool enqueue(T value);

  int getSize();

  bool dequeue();

  T *peek();
};

#include "../templates/queue.tpp"
