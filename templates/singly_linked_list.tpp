#pragma once

#include "../include/singly_linked_list.h"
using namespace std;

template <typename T> SinglyLinkedList<T>::SinglyLinkedList() {
  head = NULL;
  tail = NULL;
}
template <typename T> int SinglyLinkedList<T>::getLength() {
  return length;
}

template <typename T> Node<T> *SinglyLinkedList<T>::getHead() {
  return head;
}

template <typename T> bool SinglyLinkedList<T>::isEmpty() {
  return head == NULL;
}

template <typename T> bool SinglyLinkedList<T>::append(T value) {
  Node<T> *new_node = new Node<T>(value);
  // List is empty
  if (isEmpty()) {
    head = new_node;
    tail = new_node;
    return true;
  }
  // List is not empty
  else {
    tail->next = new_node;
    tail = new_node;
    return true;
  }
  return false;
}

template <typename T> bool SinglyLinkedList<T>::insert(T value, int position) {
  Node<T> *newNode = new Node<T>(value);
  Node<T> *current = head;
  int current_position = 0;

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

  // current != NULL --> didnt reach the end
  // current < position - 1 --> didnt reach the intended position
  Node<T> *prev;
  while (current != NULL && current_position < position - 1) {
    current = current->next;
    prev = current;
    current_position++;
  }
  newNode->next = current;
  prev->next = newNode;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::push(T value) {

  Node<T> *newNode = new Node<T>(value);
  // List is empty.
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }
  // List is not empty.
  else {
    newNode->next = head;
    head = newNode;
  }
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removeHead() {
  Node<T> *current = head;
  if (isEmpty()) {
    return false;
  }
  head = head->next;
  current = NULL;
  return true;
}

template <typename T> bool SinglyLinkedList<T>::removetail() {
  if (isEmpty()) {
    return false;
  }
  Node<T> *prev = NULL;
  while (head->next != NULL) {
    prev = head;
    head = head->next;
  }
  tail = prev;
  tail->next = NULL;
  return true;
}
// TEST:
template <typename T> bool SinglyLinkedList<T>::removeNode(T node) {
  Node<T> *currentNode = node;
  if (node == head || node == tail) {
    return false;
  }
  currentNode = currentNode->next;
  node = NULL;
  return true;
}

// FIX:
template <typename T> bool SinglyLinkedList<T>::deleteNode(int position) {
  Node<T> *currentposition = position;
  if (position < 0) {
    return false;
  }
  if (position > length) {
    return false;
  }
  currentposition = currentposition->next;
  deleteNode(position);
  return true;
}

// TODO: Overload the "<<" operator to use this function.
template <typename T> void SinglyLinkedList<T>::display() {
  if (head == NULL) {
    cout << "List is empty.";
  }
  Node<T> *current = head;
  while (current != NULL) {
    cout << "The list is: ";
    cout << current->value << endl;
    current = current->next;
  }
}
