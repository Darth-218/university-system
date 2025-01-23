/**
 * @file hash_table.tpp
 * @brief Template file for the HashTable class.
 */

#pragma once

#include "../include/hash_table.h"

template <typename K, typename V> HashTable<K, V>::HashTable(int table_size) {

  /**
   * @brief Constructs an empty HashTable object given a size.
   * @param table_size, the size intended for the table.
   */

  this->table_size = table_size;
  hash_array = new SinglyLinkedList<table_pair<K, V>>[table_size];
}

// FNV-1a
template <typename K, typename V> int HashTable<K, V>::hash(K key) {

  /**
   * @brief A hashing function that is based on the "FNV-1a" Algorithm.
   * @param key, the key to hash
   */

  string byte_string = to_string(key);
  int prime = 31;
  int hash = 1234;

  for (int i = 0; i < byte_string.size(); i++) {
    hash = (hash ^ ((int)byte_string[i])) * prime;
  }

  return hash % table_size;
}

template <typename K, typename V> bool HashTable<K, V>::insert(K key, V value) {

  /**
   * @brief A function that inserts a value into the HashTable object.
   * @param key, the key of the value.
   * @param value, the value to insert.
   */

  table_pair<K, V> entry;

  entry.key = key;
  entry.value = value;

  hash_array[hash(key)].append(entry);
  return true;
}

template <typename K, typename V> V *HashTable<K, V>::get(K key) {
  /**
   * @brief A function that returns a pointer to the value using a key.
   * @param key, the key of the value.
   */

  int hash = this->hash(key);

  try {

    SNode<table_pair<K, V>> *ptr = hash_array[hash].getHead();

    while (ptr != NULL) {

      if (ptr->value.key == key) {
        return &(ptr->value.value);
      }

      ptr = ptr->next;
    }
  }

  catch (exception &e) {
    out_of_range("Object not found.");
  }

  return NULL;
}

template <typename K, typename V> bool HashTable<K, V>::remove(K key) {

  /**
   * @brief A function that removes a value from the HashTable object.
   * @param key, the key of the value to remove.
   */

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
