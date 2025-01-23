/**
 * @file hash_table.h
 * @brief Defines the HashTable and table_pair Classes.
 */

#pragma once

#include "includes.h"
#include "singly_linked_list.h"

/**
 * @class table_pair
 * @brief A container for a key and its value.
 * @tparam K The type of key values.
 * @tparam V The type of values.
 */
template <typename K, typename V> struct table_pair {
  K key;   ///< The key to store.
  V value; ///< The value to store.
};

/**
 * @class HashTable
 * @brief The HashTable class.
 * @tparam K The type of key values.
 * @tparam V The type of values.
 */
template <typename K, typename V> class HashTable {
private:
  int table_size = 0; ///< The HashTable object size.
  SinglyLinkedList<table_pair<K, V>>
      *hash_array; ///< The array used to store values.

  /**
   * @brief A hashing function that is based on the "FNV-1a" Algorithm.
   * @param key The key to hash.
   * @return The index in the hash_array.
   */
  int hash(K key);

public:
  /**
   * @brief Constructs an empty HashTable object given a size.
   * @param table_size The size intended for the table.
   */
  HashTable(int table_size);

  /**
   * @brief A function that inserts a value into the HashTable object.
   * @param key the key of the value.
   * @param value the value to insert.
   * @return boolean.
   */
  bool insert(K key, V value);

  /**
   * @brief A function that returns a pointer to the value using a key.
   * @param key The key of the value.
   * @return A pointer to the value.
   */
  V *get(K key);

  /**
   * @brief A function that removes a value from the HashTable object.
   * @param key The key of the value to remove.
   * @return boolean.
   */
  bool remove(K key);
};

#include "../templates/hash_table.tpp"
