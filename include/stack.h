/**
 * @file stack.h
 * @brief Defines the Stack class.
 */

#pragma once

#include "includes.h"
#include "single_node.h"

/**
 * @class Stack
 * @brief The Stack class.
 * @tparam T The type of value stored in the stack.
 */
template <typename T> class Stack {
private:
  SNode<T> *stack_top; //< A pointer to the top of the Stack object.
  int size;            //< The size of the Stack object.

public:
  /**
   * @brief Constructs an empty Stack object.
   */
  Stack();

  /**
   * @brief A function to check if the stack is empty.
   * @return True if the list is empty, false otherwise.
   */
  bool isEmpty();

  /**
   * @brief A function to get the size of the stack.
   * @return The size of the stack.
   */
  int getSize();

  /**
   * @brief A function that pushes values into the stack.
   * @param object The value to add to the stack.
   * @return boolean.
   */
  bool push(T object);

  /**
   * @brief A function that removes the top value of the stack.
   * @return boolean.
   */
  bool pop();

  /**
   * @brief A function that returns the top value of the stack.
   * @return T The top of the stack.
   */
  T peek();
};

#include "../templates/stack.tpp"
