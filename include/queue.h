/**
 * @file queue.h
 * @brief Defines the Queue class.
 */

#pragma once

#include "includes.h"
#include "single_node.h"

/**
 * @class Queue
 * @brief The Queue class.
 * @tparam T The type of values store in the Queue object.
 */
template <typename T> class Queue {
private:
  SNode<T> *rear,
      *front; //< Pointers to the front and rear of the Queue object.
  int size;   //< The size of the Queue object.

public:
  /**
   * @brief Constructs an empty Queue object.
   */
  Queue();

  /**
   * @brief A function to check if the queue is empty.
   * @return True if the list is empty, false otherwise.
   */
  bool isEmpty();

  /**
   * @brief A function that returns the length of the queue.
   * @return queue size.
   */
  int getSize();

  /**
   * @brief A function that adds a value to the end of the queue.
   * @param value The value to add.
   * @return boolean.
   */
  bool enqueue(T value);

  /**
   * @brief A function that removes the first value in the queue.
   * @return boolean.
   */
  bool dequeue();

  /**
   * @brief A function that returns a pointer to the first element in the queue.
   * @return Pointer to the stack top value.
   */
  T *peek();
};

#include "../templates/queue.tpp"
