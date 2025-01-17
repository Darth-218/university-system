#pragma once

#include "../include/queue.h"

using namespace std;

template <typename T> Queue<T>::Queue() {
  front = NULL;
  rear = NULL;
  size = 0;
}

template <typename T> bool Queue<T>::isEmpty() {
  return front == NULL;
}

template <typename T> int Queue<T>::getSize() {
  return size;
}

template <typename T> bool Queue<T>::enqueue(T value) {
  Node<T> *newNode = new Node<T>(value);
  // case 1: Queue is empty
  if (isEmpty()) {
    front = newNode;
    rear = newNode;
  }

  // case 2: Queue is not empty (insert node at the edn)
  else {
    rear->next = newNode;
    rear = newNode;
  }

  size++;
  return true;
}

template <typename T> bool Queue<T>::dequeue() {
  // case 1: Queue is empty
  if (isEmpty()) {
    return false;
  }

  // case 2: Queue is not empty (delete first node)
  Node<T> *tmp = front;
  front = front->next;

  // Check if the queue becomes empty after dequeue(error if it happens)
  if (front == NULL) {
    rear = NULL;
  }

  delete tmp;
  size--;
  return true;
}

template <typename T> void Queue<T>::peek() {
  if (isEmpty()) {
    cout << "Queue is empty!" << endl;
  }
  cout << front->value << endl;
}
