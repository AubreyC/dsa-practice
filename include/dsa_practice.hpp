#ifndef DSA_PRACTICE_HPP
#define DSA_PRACTICE_HPP

#include <optional>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

namespace dsa_practice
{
  // Algorithm:
  // - Binary search
  //

  // Structure:

  // Algorithm
  std::vector<int> merge(const std::vector<int> &ret1, const std::vector<int> &ret2);
  std::vector<int> mergeSort(const std::vector<int> &nums);
  std::optional<int> binarySearch(const std::vector<int> &nums, const int target);

  // Datastructure
  struct ListNode
  {
    int value{};
    ListNode *next{};

    ListNode(int v) :
      value(v)
    {
    }
  };

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
  ListNode *detectCycle(ListNode *head); // Declaration of detectCycle function

  class LRUCache
  {
    // https://neetcode.io/problems/lru-cache?list=neetcode150
    // Implement the Least Recently Used (LRU) cache class LRUCache. The class should support the
    // following operations
    // - LRUCache(int capacity) Initialize the LRU cache of size capacity.
    // - int get(int key) Return the value corresponding to the key if the key exists, otherwise
    // return -1.
    // - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add
    // the key-value pair to the cache. If the introduction of the new pair causes the cache to
    // exceed its capacity, remove the least recently used key. A key is considered used if a get or
    // a put operation is called on it. Ensure that get and put each run in O(1)O(1) average time
    // complexity.
  public:
    struct Node
    {
      int key{};
      int value{};
      Node *next{};
      Node *prev{};

      Node(int k, int v) :
        key(k),
        value(v) {};
    };

    LRUCache(int capacity);

    void removeNode(Node *node);
    void pushNode(Node *node);
    int get(int key);
    void put(int key, int value);

  private:
    size_t mCapacity;
    std::unordered_map<int, Node *> mCache;
    Node *mHeadNode{};
    Node *mLastNode{};
  };

} // namespace dsa_practice

#endif
