#pragma once

#include "../include/singly_linked_list.h"
using namespace std;

template <typename T> SinglyLinkedList<T>::SinglyLinkedList() {
  head = NULL;
  tail = NULL;
  length = 0;
}
template <typename T> int SinglyLinkedList<T>::getLength() {
  return length;
}

template <typename T> SNode<T> *SinglyLinkedList<T>::getHead() {
  return head;
}

template <typename T> bool SinglyLinkedList<T>::isEmpty() {
  return head == NULL;
}

template <typename T> bool SinglyLinkedList<T>::append(T value) {
  SNode<T> *new_node = new SNode<T>(value);
  // List is empty
  if (isEmpty()) {
    head = new_node;
    tail = new_node;
    length++;
    return true;
  }
  // List is not empty
  else {
    tail->next = new_node;
    tail = new_node;
    length++;
    return true;
  }
  return false;
}

template <typename T> bool SinglyLinkedList<T>::push(T value) {
  SNode<T> *newNode = new SNode<T>(value);
  // List is empty.
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
    length++;
  }
  // List is not empty.
  else {
    newNode->next = head;
    head = newNode;
    length++;
  }
  return true;
}

template <typename T> bool SinglyLinkedList<T>::insert(T value, int position) {

  // position does not exist
  if (position < 0) {
    return false;
  }

  if (position == 0) {
    push(value);
    return true;
  }

  if (position == this->length - 1) {
    append(value);
    return true;
  }

  SNode<T> *prev;
  SNode<T> *current = head;
  SNode<T> *newNode = new SNode<T>(value);
  int current_position = 0;
  while (current != NULL && current_position < position) {
    prev = current;
    current = current->next;
    current_position++;
  }
  prev->next = newNode;
  newNode->next = current;
  length++;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeHead() {
  if (isEmpty()) {
    return false;
  }
  head = head->next;
  length--;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeTail() {
  SNode<T> *current = head;
  if (isEmpty()) {
    return false;
  }
  SNode<T> *prev;
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }
  tail = prev;
  tail->next = NULL;
  length--;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeNode(SNode<T> *node) {
  SNode<T> *target = node->next;
  node->next = target->next;
  delete target;
  length--;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::deleteNode(int position) {
  if (position < 0) {
    return false;
  }
  if (position > length) {
    return false;
  }
  if (position == 0) {
    return removeHead();
  }
  if (position + 1 == length) {
    return removeTail();
  } else {
    SNode<T> *current = head;
    int current_position = 0;
    while (current_position < position - 1) {
      current_position = current_position + 1;
      current = current->next;
    }
    return removeNode(current);
  }
}

// TODO: Overload the "<<" operator to use this function.
template <typename T> void SinglyLinkedList<T>::display() {
  if (head == NULL) {
    return;
  }
  SNode<T> *current = head;
  while (current != NULL) {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
}
