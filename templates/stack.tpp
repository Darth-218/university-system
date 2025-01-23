/**
 * @file stack.tpp
 * @brief Template file for the Stack class.
 */

#pragma once

#include "../include/stack.h"

template <typename T> Stack<T>::Stack() {

  /**
   * @brief Constructs an empty Stack object.
   */

  stack_top = NULL;
  size = 0;
}

template <typename T> bool Stack<T>::isEmpty() {

  /**
   * @brief A function to check if the stack is empty.
   * @return True if the list is empty, false otherwise.
   */

  return stack_top == NULL;
}

template <typename T> int Stack<T>::getSize() {

  /**
   * @brief A function to get the size of the stack.
   * @return The size of the stack.
   */

  return size;
}

template <typename T> bool Stack<T>::push(T value) {

  /**
   * @brief A function that pushes values into the stack.
   * @param value The value to push.
   */

  SNode<T> *new_node = new SNode<T>(value);

  new_node->next = stack_top;
  stack_top = new_node;

  size++;
  return true;
}

template <typename T> bool Stack<T>::pop() {

  /**
   * @brief A function that removes the top value of the stack.
   * @return boolean.
   */

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

  /**
   * @brief A function that returns the top value of the stack.
   * @return T The top of the stack.
   */

  if (isEmpty()) {
    return T();
  }

  return stack_top->value;
}
