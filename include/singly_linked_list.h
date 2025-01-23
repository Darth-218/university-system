/**
 * @file single_node.h
 * @brief Defines the SinglyLinkedList class.
 */

#pragma once

#include "single_node.h"

/**
 * @class SinglyLinkedList
 * @brief The SinglyLinkedList class.
 * @tparam T The type of values stored inside the SinglyLinkedList object.
 */
template <typename T> class SinglyLinkedList {
private:
  SNode<T> *head,
      *tail;  //< Pointers to the head and tail of the SinglyLinkedList object;
  int length; //< The length of the SinglyLinkedList object;

public:
  /**
   * @brief Constructs an empty SinglyLinkedList object.
   */
  SinglyLinkedList();

  /**
   * @brief A function that returns the head of the list.
   * @return A pointer to the head.
   */
  SNode<T> *getHead();

  /**
   * @brief A function to check if the list is empty.
   * @return True if the list is empty, false otherwise.
   */
  bool isEmpty();

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
   * @brief A function that removes a specific node.
   * @param node The pointer to the previous node to the target to delete.
   * @return boolean.
   */
  bool removeNode(SNode<T> *node);

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
   * @brief A wrapper function that removes a node from anywhere in the list.
   * @param position The index of the node to remove.
   * @return boolean.
   */
  bool deleteNode(int position);

  /**
   * @brief A function that displays the list.
   */
  void display();

  /**
   * @brief A function that returns the length of the list.
   * @return List length.
   */
  int getLength();
};

#include "../templates/singly_linked_list.tpp"
