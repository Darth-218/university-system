/**
 * @file doubly_linked_list.h
 * @brief Defines the DoublyLinkedList class.
 */

#pragma once

#include "double_node.h"

/**
 * @class DoublyLinkedList
 * @brief The DoublyLinkedList class.
 * @tparam T The type of values stored inside the DoublyLinkedList object.
 */
template <typename T> class DoublyLinkedList {
private:
  DNode<T> *head,
      *tail;  //< Pointers to the head and tail of the DoublyLinkedList object.
  int length; //< The length of the DoublyLinkedList object.

public:
  /**
   * @brief Constructs an empty DoublyLinkedList object.
   */
  DoublyLinkedList();

  /**
   * @brief A function to check if the list is empty.
   * @return True if the list is empty, false otherwise.
   */
  bool isEmpty();

  /**
   * @brief A function that returns the length of the list.
   * @return List length.
   */
  int getLength();

  /**
   * @brief A function that returns the head of the list.
   * @return A pointer to the head.
   */
  DNode<T> *getHead();

  /**
   * @brief Adds a value to the end of the list.
   * @param value The value to add.
   * @return boolean.
   */
  bool append(T value);

  /**
   * @brief Adds a value to an index in the list.
   * @param value The value to add.
   * @param position The position to add the value at.
   * @return boolean.
   */
  bool insert(T value, int position);

  /**
   * @brief Adds a value to the begining of the list.
   * @param value The value to add.
   * @return boolean.
   */
  bool push(T value);

  /**
   * @brief A function that removes the head of the list.
   * @return boolean.
   */
  bool removeHead();

  /**
   * @brief a function that removes the tail of the list.
   * @return boolean.
   */
  bool removeTail();

  /**
   * @brief A function that removes a specific node.
   * @param node The pointer to the node to delete.
   * @return boolean.
   */
  bool removeNode(DNode<T> *node);

  /**
   * @brief A wrapper function that removes a node from anywhere in the list.
   * @param index The index of the node to remove.
   * @return boolean.
   */
  bool deleteNode(int index);

  /**
   * @brief A function that displays the list.
   */
  void display();
};

#include "../templates/doubly_linked_list.tpp"
