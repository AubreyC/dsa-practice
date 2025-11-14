#include <algorithm>
#include <iostream>

#include "dsa_heap.hpp"

namespace dsa_practice
{

  void Heap::add(const int value)
  {
    // Logic:
    // - Add node at the end
    // - Iterate: Swap with parent if parent > child
    mVector.push_back(value);
    if (mVector.size() > 1)
    {
      size_t idx = mVector.size() - 1;
      size_t idxParent = getParentIdx(idx);
      while (idx != 0 && mVector[idxParent] > mVector[idx])
      {
        std::swap(mVector[idx], mVector[idxParent]);
        idx = idxParent;
        idxParent = getParentIdx(idx);
      }
    }
  }

  bool Heap::empty()
  {
    return mVector.empty();
  }

  void Heap::pop()
  {
    if (mVector.empty())
    {
      return;
    }

    // Put last element to front:
    mVector.front() = mVector.back();
    mVector.pop_back();

    std::cout << "pop()" << std::endl;

    // Heapify:
    // - Start from root
    // - Check if smallest child if lower than current root -> swap if so
    // - Iterate

    size_t idx = 0;
    while (getLeftChildIdx(idx) < mVector.size())
    {
      size_t idxSmallestChild = getLeftChildIdx(idx);
      if (
        getRightChildIdx(idx) < mVector.size() &&
        mVector[getRightChildIdx(idx)] <= mVector[getLeftChildIdx(idx)])
      {
        idxSmallestChild = getRightChildIdx(idx);
      }

      // If smallest child is smaller than root, swap root with smallest child
      if (mVector[idxSmallestChild] <= mVector[idx])
      {
        std::swap(mVector[idx], mVector[idxSmallestChild]);
        idx = idxSmallestChild;
      }
      else
      {
        break;
      }
    }
  }

  size_t Heap::getParentIdx(size_t idx)
  {
    return (idx - 1) / 2;
  }

  size_t Heap::getLeftChildIdx(size_t idx)
  {
    return (2 * idx) + 1;
  }

  size_t Heap::getRightChildIdx(size_t idx)
  {
    return (2 * idx) + 2;
  }

  std::optional<int> Heap::top()
  {
    if (mVector.empty())
    {
      return {};
    }

    return {mVector[0]};
  }

} // namespace dsa_practice
