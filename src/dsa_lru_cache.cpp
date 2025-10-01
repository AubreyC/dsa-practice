#include "dsa_lru_cache.hpp"

namespace dsa_practice
{
  LRUCache::LRUCache(int capacity)
  {
    mCache.reserve(capacity);
    mCapacity = capacity;
  }

  void LRUCache::removeNode(NodeDouble *node)
  {
    if (node->prev)
    {
      node->prev->next = node->next;
    }

    if (node->next)
    {
      node->next->prev = node->prev;
    }

    if (mLastNode == node)
    {
      mLastNode = node->prev;
    }

    if (mHeadNode == node)
    {
      mHeadNode = node->next;
    }
  }

  void LRUCache::pushNode(NodeDouble *node)
  {
    if (!mHeadNode)
    {
      mHeadNode = node;
    }
    else
    {
      mHeadNode->prev = node;
      node->next = mHeadNode;
      node->prev = nullptr;
      mHeadNode = node;
    }

    if (!mLastNode)
    {
      mLastNode = node;
    }
  }

  int LRUCache::get(int key)
  {
    int ret = -1;
    if (mCache.count(key) > 0)
    {
      NodeDouble *node = mCache[key];
      removeNode(node);
      pushNode(node);
      ret = node->value;
    }
    return ret;
  }

  void LRUCache::put(int key, int value)
  {
    if (mCache.count(key) > 0)
    {
      NodeDouble *node = mCache[key];
      node->key = key;
      node->value = value;
      removeNode(node);
      pushNode(node);
    }
    else
    {
      NodeDouble *newNode = new NodeDouble(key, value);
      mCache[key] = newNode;
      pushNode(newNode);

      // Delete last node
      if (mCache.size() > mCapacity)
      {
        mCache.erase(mLastNode->key);
        NodeDouble *lastNode = mLastNode;
        removeNode(lastNode);
        delete lastNode;
      }
    }
  }
} // namespace dsa_practice
