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

  if (current->left == NULL && current->right == NULL) {
    current->value = 9;
    return true;
  }

  if (current->left == NULL ^ current->right == NULL) {
    Node<T> *existing_node;
    if (current->left == NULL) {
      current->value = current->right->value;
      current->right = NULL;
      return true;
    }
    current->value = current->left->value;
    current->left = NULL;
    return true;
  }

  if ((current->left && current->right)) {
    Node<T> *successor = current->right;
    Node<T> *previous = successor;
    while (successor->left != NULL) {
      previous = successor;
      successor = successor->left;
    }
    T new_value = successor->value;
    deleteNode(successor->value);
    current->value = new_value;
    return true;
  }

  return false;
}

template <typename T> void BinaryTree<T>::displayTree() {

  if (isEmpty()) {
    return;
  }

  displayNode(root);
  std::cout << "\n";
  return;
}

template <typename T> void BinaryTree<T>::displayNode(Node<T> *root) {

  if (root == NULL) {
    return;
  }

  displayNode(root->left);
  std::cout << root->value << " ";
  displayNode(root->right);
}
