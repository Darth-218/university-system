#pragma once

#include "../include/hash_table.h"

template <typename K, typename V> HashTable<K, V>::HashTable(int table_size) {
  this->table_size = table_size;
  hash_array = new SinglyLinkedList<table_pair<K, V>>[table_size];
}

// FNV-1a
template <typename K, typename V> int HashTable<K, V>::hash(K key) {
  string byte_string = to_string(key);
  int prime = 31;
  int hash = 1234;
  for (int i = 0; i < byte_string.size(); i++) {
    hash = (hash ^ ((int)byte_string[i])) * prime;
  }
  return hash % table_size;
}

template <typename K, typename V> bool HashTable<K, V>::insert(K key, V value) {
  table_pair<K, V> entry;
  entry.key = key;
  entry.value = value;
  hash_array[hash(key)].append(entry);
  return true;
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
  int hash = this->hash(key);
  try {
    SNode<table_pair<K, V>> *ptr = hash_array[hash].getHead();
    while (ptr != NULL) {
      if (ptr->value.key == key) {
        return ptr->value.value;
      }
      ptr = ptr->next;
    }
  } catch (exception &e) {
    out_of_range("Object not found.");
  }
  return V();
}

// TEST:
template <typename K, typename V> bool HashTable<K, V>::remove(K key) {
  int hash = this->hash(key);
  int postition = 0;
  SNode<table_pair<K, V>> *ptr = hash_array[hash].getHead();
  while (ptr != NULL) {
    if (ptr->value.key == key) {
      return hash_array[hash].deleteNode(postition);
    }
    ptr = ptr->next;
    postition++;
  }
  return false;
}
