#ifndef BINARY_TREE_TPP
#define BINARY_TREE_TPP

#include "../include/binary_tree.h"

template <typename T> BinaryTree<T>::BinaryTree() {
  this->root = NULL;
}

template <typename T> bool BinaryTree<T>::isEmpty() {
  return root == NULL;
}

template <typename T> bool BinaryTree<T>::insert(T value) {

  Node<T> *current = root;
  Node<T> *newnode = new Node<T>(value);

  if (isEmpty()) {
    root = newnode;
    return true;
  }

  while (current != NULL) {

    if (current->value < value && !current->right) {
      current->right = newnode;
      return true;
    }

    else if (current->value > value && !current->left) {
      current->left = newnode;
      return true;
    }

    current = (current->value < value) ? current->right : current->left;
  }
  return false;
}

template <typename T> bool BinaryTree<T>::deleteNode(T value) {
  return true;
}

template <typename T> void BinaryTree<T>::display() {

  if (isEmpty()) {
    return;
  }

  return traverse(root);
}

template <typename T> void BinaryTree<T>::traverse(Node<T> *root) {

  if (root == NULL) {
    return;
  }

  traverse(root->left);
  std::cout << root->value << " ";
  traverse(root->right);
}

#endif
