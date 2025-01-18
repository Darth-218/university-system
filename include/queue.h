#pragma once

#include "single_node.h"
using namespace std;

template <typename T> class Queue {
private:
  Node<T> *rear, *front;
  int size;

public:
  Queue();

  bool isEmpty();

  bool enqueue(T value);

  int getSize();

  bool dequeue();

  void peek();
};

#include "../templates/queue.tpp"
