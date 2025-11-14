#ifndef DSA_STACK_QUEUE_HPP
#define DSA_STACK_QUEUE_HPP

#include "dsa_linked_list.hpp"
#include <array>

namespace dsa_practice
{

  /**
   * @brief Design a stack class that supports the push, pop, top, and getMin operations.
   * - MinStack() initializes the stack object.
   * - void push(int val) pushes the element val onto the stack.
   * - void pop() removes the element on the top of the stack.
   * - int top() gets the top element of the stack.
   * - int getMin() retrieves the minimum element in the stack.
   *   Each function should run in O(1)O(1) time.
   */
  class Stack
  {
  private:
    NodeSingle *mNode = nullptr;
  };

} // namespace dsa_practice

#endif
