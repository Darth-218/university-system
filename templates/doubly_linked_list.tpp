#pragma once

#include "../include/doubly_linked_list.h"

using namespace std;

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
  length = 0;
}

template <typename T> bool DoublyLinkedList<T>::isEmpty() {
  return head == NULL;
}

template <typename T> int DoublyLinkedList<T>::getLength() {
  return length;
}

template <typename T> DNode<T> *DoublyLinkedList<T>::getHead() {
  return head;
}

template <typename T> bool DoublyLinkedList<T>::push(T value) {

  DNode<T> *newNode = new DNode<T>(value);
  // case 1: List is empty.
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }
  // case 2: List is not empty.
  else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  length++;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::append(T value) {
  DNode<T> *newNode = new DNode<T>(value);
  // case 1: List is empty.
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }
  // case 2: List is not empty.
  else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  length++;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::insert(T value, int position) {
  DNode<T> *newNode = new DNode<T>(value);
  DNode<T> *tmp = head;
  int current_position = 0;

  // case 0: position doesn't exist
  if (position < 0 || position > length) {
    return false;
  }
  if (position == 0) {
    push(value);
    return true;
  }
  if (position == length) {
    append(value);
    return true;
  }

  // case 1: position is at middle.
  while (tmp != NULL && current_position < position - 1) {
    tmp = tmp->next;
    current_position++;
  }
  if (tmp != NULL) {
    newNode->next = tmp->next;
    // Check if there is a node after
    if (tmp->next != NULL) {
      tmp->next->prev = newNode;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    length++;
    return true;
  }
  return false;
}

template <typename T> bool DoublyLinkedList<T>::removeHead() {
  head = head->next;
  head->prev = NULL;
  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::removeTail() {
  tail = tail->prev;
  tail->next = NULL;
  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::removeNode(DNode<T> *node) {
  node->next->prev = node->prev;
  node->prev->next = node->next;
  delete node;
  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::deleteNode(int index) {
  int current_position = 0;

  // check if list is empty first
  if (isEmpty()) {
    return false;
  }
  if (index > length - 1 && index >= 0) {
    return false;
  }
  // case 1: node is at head
  if (index == 0) {
    return removeHead();
  }

  // case 2: node is at tail
  if (index == length - 1) {
    return removeTail();
  }

  // case 3: node is in the middle
  else {
    DNode<T> *tmp = head;
    while (current_position < index) {
      tmp = tmp->next;
      current_position++;
    }
    return removeNode(tmp);
  }
  return false;
}

template <typename T> void DoublyLinkedList<T>::display() {
  if (head == NULL) {
    return;
  }
  DNode<T> *tmp = head;
  while (tmp != NULL) {
    cout << tmp->value << " ";
    tmp = tmp->next;
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, DoublyLinkedList<T> &list) {
  list.display();
  return os;
}
