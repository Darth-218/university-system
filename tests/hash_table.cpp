#include "../include/hash_table.h"

int main() {
  HashTable<int, int> ht(20);

  std::cout << ht.insert(5, 10) << std::endl;
  std::cout << ht.insert(25, 11) << std::endl;

  std::cout << ht.get(5) << std::endl;
  std::cout << ht.get(25) << std::endl;

  std::cout << ht.remove(5) << std::endl;

  std::cout << ht.get(25) << std::endl;
  std::cout << ht.get(5) << std::endl;

  return 0;
}
