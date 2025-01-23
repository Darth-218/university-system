/**
 * @file binary_tree_node.h
 * @brief Defines the Binary Tree Nodes (TNode) class.
 */

#pragma once

#include "includes.h"

template <typename T> class TNode {
public:
  T value;
  TNode *right, *left;
  bool is_root, is_right, is_left;
  TNode(T value) {
    this->value = value;
    this->right = this->left = NULL;
    this->is_root = this->is_right = this->is_left = false;
  }
};
