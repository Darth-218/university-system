/**
 * @file binary_tree.tpp
 * @brief Template file for the BinaryTree class.
 * @tparam T, the type of value stored in the tree.
 */

#pragma once

#include "../include/binary_tree.h"

template <typename T> BinaryTree<T>::BinaryTree() {

  /**
   * @brief Constructs an empty tree.
   */

  this->root = NULL;
  this->size = 0;
}

template <typename T> bool BinaryTree<T>::isEmpty() {

  /**
   * @brief A function to check if the tree is empty.
   * @return True if the tree is empty, false otherwise.
   */

  return this->root == NULL;
}

template <typename T> int BinaryTree<T>::getSize() {

  /**
   * @brief A function that returns the size of the tree.
   * @return Tree size.
   */

  return this->size;
}

template <typename T> bool BinaryTree<T>::insert(T value) {

  /**
   * @brief A function that inserts a value in the correct node in the tree.
   * @param value, the value to store.
   * @return boolean for debugging purposes.
   */

  TNode<T> *current = this->root;
  TNode<T> *new_node = new TNode<T>(value);

  if (isEmpty()) {
    this->root = new_node;
    this->root->is_root = true;
    return true, this->size++;
  }

  while (current != NULL) {

    if (current->value < value && !current->right) {
      current->right = new_node;
      new_node->is_right = true;
      return true, this->size++;
    }

    else if (current->value > value && !current->left) {
      current->left = new_node;
      new_node->is_left = true;
      return true, this->size++;
    }

    current = (current->value < value) ? current->right : current->left;
  }
  return false;
}

template <typename T> bool BinaryTree<T>::deleteNode(T value) {

  /**
   * @brief A function that removes a certain value from the tree.
   * @param value, the value to delete.
   * @return boolean for debugging purposes.
   */

  if (isEmpty()) {
    return false;
  }

  TNode<T> *current = this->root;
  TNode<T> *previous;
  T new_value;

  while (current != NULL && current->value != value) {

    previous = current;

    if (current->value < value) {
      current = current->right;
    }

    else if (current->value > value) {
      current = current->left;
    }
  }

  if (current->left == NULL && current->right == NULL) {

    if (current->value == this->root->value) {
      root = NULL;
      return true, this->size--;
    }

    if (current->is_right) {
      previous->right = NULL;
    }

    else {
      previous->left = NULL;
    }

    return true, this->size--;
  }

  if (current->left == NULL ^ current->right == NULL) {

    TNode<T> *existing_node;

    if (current->left == NULL) {
      new_value = current->right->value;
    }

    else {
      new_value = current->left->value;
    }

    deleteNode(new_value);
    current->value = new_value;

    return true, this->size--;
  }

  if ((current->left && current->right)) {

    TNode<T> *successor = current->left;
    TNode<T> *previous;

    while (successor->right != NULL) {
      previous = successor;
      successor = successor->right;
    }

    T new_value = successor->value;
    deleteNode(new_value);
    current->value = new_value;

    return true, this->size--;
  }
  return false;
}

template <typename T> void BinaryTree<T>::displayTree() {

  /**
   * @brief A function that displays the tree in-order.
   */

  displayNode(this->root), cout << endl;

  return;
}

template <typename T> void BinaryTree<T>::displayNode(TNode<T> *root) {

  /**
   * @brief A function that traverses nodes in an in-order traversal.
   */

  if (root == NULL) {
    return;
  }

  displayNode(root->left);
  std::cout << root->value << " ";
  displayNode(root->right);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, BinaryTree<T> &tree) {

  /**
   * @brief An overload for the operator "<<".
   */

  tree.displayTree();
  return os;
}
