/**
 * @file single_node.h
 * @brief Defines the Single Node (SNode) class.
 */

#pragma once

#include "includes.h"

/**
 * @class SNode
 * @brief The nodes for the SinglyLinkedList class.
 * @tparam T The type of values stored inside the SNode object.
 */
template <typename T> class SNode {
public:
  T value;     ///< The value stored in the SNode object.
  SNode *next; ///< A pointer to the next SNode object.

  /**
   * @brief Constructs an empty SNode object.
   * @param value The value to hold inside the SNode object.
   */
  SNode(T value) {
    this->value = value;
    next = NULL;
  }
};
