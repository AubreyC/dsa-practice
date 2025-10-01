#ifndef DSA_LRU_CACHE_HPP
#define DSA_LRU_CACHE_HPP

#include <cstdlib>
#include <unistd.h>
#include <unordered_map>

#include "dsa_linked_list.hpp"

namespace dsa_practice
{
  /**
   * @brief Implement the Least Recently Used (LRU) cache class LRUCache:
   * - Initialize the LRU cache of size capacity.
   * - int get(int key) Return the value corresponding to the key if the key exists, otherwise
   * return -1.
   * - void put(int key, int value): Update the value of the key if the key exists. Otherwise, add
   * the key-value pair to the cache.
   * - If the introduction of the new pair causes the cache to
   * exceed its capacity, remove the least recently used key.
   * - A key is considered used if a get or a put operation is called on it. Ensure that get and put
   * each run in O(1)O(1) average time complexity.
   *
   * Ref: https://neetcode.io/problems/lru-cache?list=neetcode150
   */

  class LRUCache
  {
  public:
    LRUCache(int capacity);

    void removeNode(NodeDouble *node);
    void pushNode(NodeDouble *node);
    int get(int key);
    void put(int key, int value);

  private:
    size_t mCapacity;
    std::unordered_map<int, NodeDouble *> mCache;
    NodeDouble *mHeadNode{};
    NodeDouble *mLastNode{};
  };
} // namespace dsa_practice

#endif
