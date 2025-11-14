#ifndef DSA_HEAP_HPP
#define DSA_HEAP_HPP

#include <functional>
#include <list>
#include <stdlib.h>
#include <unistd.h>

namespace dsa_practice
{

  class Heap
  {
  public:
    void add(const int value);
    std::optional<int> top();
    void pop();
    bool empty();

    std::vector<int> mVector;

  private:
    size_t mSize{};

    // Complete binary tree
    size_t getParentIdx(size_t idx);
    size_t getLeftChildIdx(size_t idx);
    size_t getRightChildIdx(size_t idx);
  };

} // namespace dsa_practice

#endif
