#pragma once

#include "../include/binary_tree.h"

template <typename T> BinaryTree<T>::BinaryTree() {
  this->root = NULL;
}

template <typename T> bool BinaryTree<T>::isEmpty() {
  return root == NULL;
}

template <typename T> bool BinaryTree<T>::insert(T value) {

  Node<T> *current = root;
  Node<T> *new_node = new Node<T>(value);

  if (isEmpty()) {
    root = new_node;
    return true;
  }

  while (current != NULL) {

    if (current->value < value && !current->right) {
      current->right = new_node;
      return true;
    }

    else if (current->value > value && !current->left) {
      current->left = new_node;
      return true;
    }

    current = (current->value < value) ? current->right : current->left;
  }
  return false;
}

// TODO: The case of two children

template <typename T> bool BinaryTree<T>::deleteNode(T value) {

  if (isEmpty()) {
    return false;
  }

  Node<T> *current = this->root;

  while (current != NULL && current->value != value) {

    if (current->value < value) {
      current = current->right;
      continue;
    }

    if (current->value > value) {
      current = current->left;
    }
  }

  if (current->left == current->right == NULL) {
    delete current;
    return true;
  }

  if (current->left ^ current->right) {
    Node<T> *existing_node =
        (current->left == NULL) ? current->right : current->left;
    current->value = existing_node->value;
    delete existing_node;
    return true;
  }

  if ((current->left && current->right) != NULL) {
  }

  return false;
}

template <typename T> void BinaryTree<T>::displayTree() {

  if (isEmpty()) {
    return;
  }

  return displayNode(root);
}

template <typename T> void BinaryTree<T>::displayNode(Node<T> *root) {

  if (root == NULL) {
    return;
  }

  displayNode(root->left);
  std::cout << root->value << " ";
  displayNode(root->right);
}
