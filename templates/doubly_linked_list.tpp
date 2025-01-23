/**
 * @file doubly_linked_list.tpp
 * @brief Template file for the DoublyLinkedList class.
 */

#pragma once

#include "../include/doubly_linked_list.h"

using namespace std;

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {

  /**
   * @brief Constructs an empty DoublyLinkedList object.
   */

  head = NULL;
  tail = NULL;
  length = 0;
}

template <typename T> bool DoublyLinkedList<T>::isEmpty() {

  /**
   * @brief A function to check if the list is empty.
   * @return True if the list is empty, false otherwise.
   */

  return head == NULL;
}

template <typename T> int DoublyLinkedList<T>::getLength() {

  /**
   * @brief A function that returns the length of the list.
   * @return List length.
   */

  return length;
}

template <typename T> DNode<T> *DoublyLinkedList<T>::getHead() {

  /**
   * @brief A function that returns the head of the list.
   * @return A pointer to the head.
   */

  return head;
}

template <typename T> bool DoublyLinkedList<T>::push(T value) {

  /**
   * @brief Adds a value to the begining of the list.
   * @param value, the value to add.
   * @return boolean for debugging purposes.
   */

  DNode<T> *new_node = new DNode<T>(value);

  if (isEmpty()) {
    head = new_node;
    tail = new_node;
  }

  else {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }

  length++;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::append(T value) {

  /**
   * @brief Adds a value to the end of the list.
   * @param value, the value to add.
   * @return boolean for debugging purposes.
   */

  DNode<T> *new_node = new DNode<T>(value);

  if (isEmpty()) {
    head = new_node;
    tail = new_node;
  }

  else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

  length++;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::insert(T value, int position) {

  /**
   * @brief Adds a value to an index in the list.
   * @param value, the value to add.
   * @param position, the position to add the value at.
   * @return boolean for debugging purposes.
   */

  DNode<T> *new_node = new DNode<T>(value);
  DNode<T> *tmp = head;
  int current_position = 0;

  if (position < 0 || position > length) {
    return false;
  }

  if (position == 0) {
    push(value);
    return true;
  }

  if (position == length) {
    append(value);
    return true;
  }

  while (tmp != NULL && current_position < position - 1) {
    tmp = tmp->next;
    current_position++;
  }

  if (tmp != NULL) {
    new_node->next = tmp->next;

    if (tmp->next != NULL) {
      tmp->next->prev = new_node;
    }

    tmp->next = new_node;
    new_node->prev = tmp;

    length++;
    return true;
  }

  return false;
}

template <typename T> bool DoublyLinkedList<T>::removeHead() {

  /**
   * @brief A function that removes the head of the list.
   * @return boolean for debugging purposes.
   */

  head = head->next;
  head->prev = NULL;

  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::removeTail() {

  /**
   * @brief a function that removes the tail of the list.
   * @return boolean for debugging purposes.
   */

  tail = tail->prev;
  tail->next = NULL;

  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::removeNode(DNode<T> *node) {

  /**
   * @brief A function that removes a specific node.
   * @param node, a pointer to the node to delete.
   * @return boolean for debugging purposes.
   */

  node->next->prev = node->prev;
  node->prev->next = node->next;

  delete node;

  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::deleteNode(int index) {

  /**
   * @brief A wrapper function that removes a node from anywhere in the list.
   * @param index, the index of the node to remove.
   * @return boolean for debugging purposes.
   */

  int current_position = 0;

  if (isEmpty()) {
    return false;
  }

  if (index > length - 1 && index >= 0) {
    return false;
  }

  if (index == 0) {
    return removeHead();
  }

  if (index == length - 1) {
    return removeTail();
  }

  else {

    DNode<T> *tmp = head;

    while (current_position < index) {
      tmp = tmp->next;
      current_position++;
    }

    return removeNode(tmp);
  }

  return false;
}

template <typename T> void DoublyLinkedList<T>::display() {

  /**
   * @brief A function that displays the list.
   */

  if (isEmpty()) {
    return;
  }

  DNode<T> *tmp = head;

  while (tmp != NULL) {
    cout << tmp->value << " ";
    tmp = tmp->next;
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, DoublyLinkedList<T> &list) {

  /**
   * @brief An overload for the operator "<<".
   */

  list.display();
  return os;
}
