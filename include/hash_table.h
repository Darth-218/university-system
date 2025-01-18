#pragma once

#include "singly_linked_list.h"

template <typename K, typename V> struct table_pair {
  K key;
  V value;
};

template <typename K, typename V> class HashTable {
private:
  int table_size = 0;
  SinglyLinkedList<table_pair<K, V>> *hash_array;
  int hash(K key);

public:
  HashTable(int table_size);

  bool insert(K key, V value);

  V get(K key);

  bool remove(K key);
};

#include "../templates/hash_table.tpp"
