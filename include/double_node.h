/**
 * @file double_node.h
 * @brief Defines the Double Node (DNode) class.
 */

#pragma once

#include "includes.h"

/**
 * @class DNode
 * @brief The nodes for the DoublyLinkedList class.
 * @tparam T The type of values stored inside the DNode object.
 */
template <typename T> class DNode {
public:
  T value;     ///< The stored value.
  DNode *prev; ///< Pointers to the previous DNode object.
  DNode *next; ///< Pointers to the next DNode object.

  DNode(T value) {

    /**
     * @brief Constructs an empty DNode object.
     * @param value The value to store inside the DNode object.
     */

    this->value = value;
    prev = NULL;
    next = NULL;
  }
};
