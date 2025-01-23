/**
 * @file singly_linked_list.tpp
 * @brief Template file for the SinglyLinkedList class.
 */

#pragma once

#include "../include/singly_linked_list.h"

template <typename T> SinglyLinkedList<T>::SinglyLinkedList() {

  /**
   * @brief Constructs an empty SinglyLinkedList object.
   */

  head = NULL;
  tail = NULL;
  length = 0;
}

template <typename T> bool SinglyLinkedList<T>::isEmpty() {

  /**
   * @brief A function to check if the list is empty.
   * @return True if the list is empty, false otherwise.
   */

  return head == NULL;
}

template <typename T> int SinglyLinkedList<T>::getLength() {

  /**
   * @brief A function to get the length of the list.
   * @return The length of the list
   */

  return length;
}

template <typename T> SNode<T> *SinglyLinkedList<T>::getHead() {

  /**
   * @brief A function that returns the head of the list.
   * @return A pointer to the head.
   */

  return head;
}

template <typename T> bool SinglyLinkedList<T>::push(T value) {

  /**
   * @brief Adds a value to the begining of the list.
   * @param value The value to add.
   * @return boolean for debugging purposes.
   */

  SNode<T> *new_node = new SNode<T>(value);

  if (isEmpty()) {
    head = new_node;
    tail = new_node;

    length++;
  }

  else {
    new_node->next = head;
    head = new_node;

    length++;
  }

  return true;
}

template <typename T> bool SinglyLinkedList<T>::append(T value) {

  /**
   * @brief Adds a value to the end of the list.
   * @param value The value to add.
   * @return boolean for debugging purposes.
   */

  SNode<T> *new_node = new SNode<T>(value);

  if (isEmpty()) {
    head = new_node;
    tail = new_node;

    length++;
    return true;
  }

  else {
    tail->next = new_node;
    tail = new_node;

    length++;
    return true;
  }
  return false;
}

template <typename T> bool SinglyLinkedList<T>::insert(T value, int position) {

  /**
   * @brief Adds a value to an index in the list.
   * @param value The value to add.
   * @param position The position to add the value at.
   * @return boolean for debugging purposes.
   */

  if (position < 0 || position > length) {
    return false;
  }

  if (position == 0) {
    push(value);
    return true;
  }

  if (position == this->length - 1) {
    append(value);
    return true;
  }

  SNode<T> *prev;
  SNode<T> *current = head;
  SNode<T> *new_node = new SNode<T>(value);
  int current_position = 0;

  while (current != NULL && current_position < position) {

    prev = current;
    current = current->next;

    current_position++;
  }

  prev->next = new_node;
  new_node->next = current;

  length++;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeHead() {

  /**
   * @brief A function that removes the head of the list.
   * @return boolean for debugging purposes.
   */

  if (isEmpty()) {
    return false;
  }

  head = head->next;

  length--;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeTail() {

  /**
   * @brief a function that removes the tail of the list.
   * @return boolean for debugging purposes.
   */

  if (isEmpty()) {
    return false;
  }

  SNode<T> *prev;
  SNode<T> *current = head;

  while (current->next != NULL) {

    prev = current;
    current = current->next;
  }

  tail = prev;
  tail->next = NULL;

  length--;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeNode(SNode<T> *node) {

  /**
   * @brief A function that removes a specific node.
   * @param node A pointer to the node to delete.
   * @return boolean for debugging purposes.
   */

  SNode<T> *target = node->next;
  node->next = target->next;

  delete target;

  length--;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::deleteNode(int position) {

  /**
   * @brief A wrapper function that removes a node from anywhere in the list.
   * @param index The index of the node to remove.
   * @return boolean for debugging purposes.
   */

  if (position < 0 || position > length) {
    return false;
  }

  if (position == 0) {
    return removeHead();
  }

  if (position + 1 == length) {
    return removeTail();
  }

  else {

    SNode<T> *current = head;
    int current_position = 0;

    while (current_position < position - 1) {
      current_position = current_position + 1;
      current = current->next;
    }

    return removeNode(current);
  }
}

template <typename T> void SinglyLinkedList<T>::display() {

  /**
   * @brief A function that displays the list.
   */

  if (head == NULL) {
    return;
  }

  SNode<T> *current = head;

  while (current != NULL) {
    cout << current->value << " ";
    current = current->next;
  }

  cout << endl;
}
