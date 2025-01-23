/**
 * @file queue.tpp
 * @brief Template file for the Queue class.
 */

#pragma once

#include "../include/queue.h"

template <typename T> Queue<T>::Queue() {

  /**
   * @brief Constructs an empty Queue object.
   */

  front = NULL;
  rear = NULL;
  size = 0;
}

template <typename T> bool Queue<T>::isEmpty() {

  /**
   * @brief A function to check if the queue is empty.
   * @return True if the list is empty, false otherwise.
   */

  return front == NULL;
}

template <typename T> int Queue<T>::getSize() {

  /**
   * @brief A function that returns the length of the queue.
   * @return queue size.
   */

  return size;
}

template <typename T> bool Queue<T>::enqueue(T value) {

  /**
   * @brief A function that adds a value to the end of the queue.
   * @param value, the value to add.
   */

  SNode<T> *new_node = new SNode<T>(value);

  if (isEmpty()) {
    front = new_node;
    rear = new_node;
  }

  else {
    rear->next = new_node;
    rear = new_node;
  }

  size++;
  return true;
}

template <typename T> bool Queue<T>::dequeue() {
  /**
   * @brief A function that removes the first value in the queue.
   */

  if (isEmpty()) {
    return false;
  }

  SNode<T> *tmp = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }

  delete tmp;

  size--;
  return true;
}

template <typename T> T *Queue<T>::peek() {

  /**
   * @brief A function that returns the first element in the queue.
   */

  if (isEmpty()) {
    return NULL;
  }

  return &(front->value);
}
