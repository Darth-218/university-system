#pragma once

#include "../include/stack.h"

template <typename T> Stack<T>::Stack() {
  stack_top = NULL;
  size = 0;
}

template <typename T> bool Stack<T>::isEmpty() {
  return stack_top == NULL;
}

template <typename T> int Stack<T>::getSize() {
  return size;
}

template <typename T> bool Stack<T>::push(T object) {
  SNode<T> *newNode = new SNode<T>(object);
  newNode->next = stack_top;
  stack_top = newNode;
  size++;
  return true;
}

template <typename T> bool Stack<T>::pop() {
  if (isEmpty()) {
    return false;
  }

  SNode<T> *prev = stack_top;
  stack_top = stack_top->next;
  delete prev;
  size--;
  return true;
}

template <typename T> T Stack<T>::peek() {
  if (isEmpty()) {
    return false;
  }
  return stack_top->object;
}
