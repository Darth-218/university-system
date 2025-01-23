/**
 * @file single_node.h
 * @brief Defines the Single Node (SNode) class.
 */

#pragma once

#include "includes.h"

template <typename T> class SNode {
public:
  T value;
  SNode *next;
  SNode(T value) {
    this->value = value;
    next = NULL;
  }
};
