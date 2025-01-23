/**
 * @file binary_tree.h
 * @brief Defines the BinaryTree class
 */

#pragma once

#include "binary_tree_node.h"
#include "includes.h"

/**
 * @class BinaryTree
 * @brief Definition of the BinaryTree class.
 * @tparam T the type of values stored in the BinaryTree object.
 */
template <typename T> class BinaryTree {
private:
  TNode<T> *root; //< A pointer to the BinaryTree's root.
  int size;       //< The size of the tree

public:
  /**
   * @brief Constructs an empty tree.
   */
  BinaryTree();

  /**
   * @brief A function to check if the tree is empty.
   * @return True if the tree is empty, false otherwise.
   */
  bool isEmpty();

  /**
   * @brief A function that returns the size of the tree.
   * @return Tree size.
   */
  int getSize();

  /**
   * @brief A function that inserts a value in the correct node in the tree.
   * @param value The value to store.
   * @return boolean.
   */
  bool insert(T value);

  /**
   * @brief A function that removes a certain value from the tree.
   * @param value The value to delete.
   * @return boolean.
   */
  bool deleteNode(T value);

  /**
   * @brief A function that displays the tree in-order.
   */
  void displayTree();

  /**
   * @brief A function that traverses nodes in an in-order traversal.
   * @param *root A pointer to the starting node.
   */
  void displayNode(TNode<T> *root);
};

#include "../templates/binary_tree.tpp"
