#pragma once

#include "includes.h"
#include "single_node.h"

template <typename T> class Stack {
private:
  SNode<T> *stack_top;
  int size;

public:
  Stack();

  bool isEmpty();

  int getSize();

  bool push(T object);

  bool pop();

  T peek();
};

#include "../templates/stack.tpp"
