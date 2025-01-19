#pragma once

#include "../include/binary_tree.h"

template <typename T> BinaryTree<T>::BinaryTree() {
  this->root = NULL;
  this->size = 0;
}

template <typename T> bool BinaryTree<T>::isEmpty() {
  return this->root == NULL;
}

template <typename T> int BinaryTree<T>::getSize() {
  return this->size;
}

template <typename T> bool BinaryTree<T>::insert(T value) {
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
    } else if (current->value > value && !current->left) {
      current->left = new_node;
      new_node->is_left = true;
      return true, this->size++;
    }
    current = (current->value < value) ? current->right : current->left;
  }
  return false;
}

template <typename T> bool BinaryTree<T>::deleteNode(T value) {
  if (isEmpty()) {
    return false;
  }
  if (root->value == value) {
    root = NULL;
    return true;
  }
  TNode<T> *current = this->root;
  TNode<T> *previous;
  T new_value;
  while (current != NULL && current->value != value) {
    previous = current;
    if (current->value < value) {
      current = current->right;
    } else if (current->value > value) {
      current = current->left;
    }
  }
  if (current->left == NULL && current->right == NULL) {
    if (current->is_right) {
      previous->right = NULL;
    } else {
      previous->left = NULL;
    }
    return true, this->size--;
  }
  if (current->left == NULL ^ current->right == NULL) {
    TNode<T> *existing_node;
    if (current->left == NULL) {
      new_value = current->right->value;
    } else {
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
  displayNode(this->root);
  cout << endl;
  return;
}

template <typename T> void BinaryTree<T>::displayNode(TNode<T> *root) {
  if (root == NULL) {
    return;
  }
  displayNode(root->left);
  std::cout << root->value << " ";
  displayNode(root->right);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, BinaryTree<T> &tree) {
  tree.displayTree();
  return os;
}
