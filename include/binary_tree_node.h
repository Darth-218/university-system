/**
 * @file binary_tree_node.h
 * @brief Defines the Binary Tree Nodes (TNode) class.
 */

#pragma once

#include "includes.h"

/**
 * @class TNode
 * @brief The nodes for the BinaryTree class
 */
template <typename T> class TNode {
public:
  T value;       ///< The value stored inside the TNode object.
  TNode *right;  ///< The pointer to the right TNode object.
  TNode *left;   ///< The pointer to the left TNode object.
  bool is_root;  ///< True when the object is the root.
  bool is_right; ///< True when the object is the right child.
  bool is_left;  ///< True when the object is the left child.
  TNode(T value) {

    /**
     * @brief Constructs an empty TNode object.
     * @param value The value stored inside the TNode object.
     */

    this->value = value;
    this->right = this->left = NULL;
    this->is_root = this->is_right = this->is_left = false;
  }
};
