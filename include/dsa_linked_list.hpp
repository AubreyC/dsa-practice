#ifndef DSA_LINKED_LIST_HPP
#define DSA_LINKED_LIST_HPP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

namespace dsa_practice
{
  /**
   * @brief Node for singly linked list
   *
   */
  struct NodeSingle
  {
    int value{};
    NodeSingle *next{};

    NodeSingle(int v) :
      value(v)
    {
    }
  };

  /**
   * @brief Node for doubly linked list
   *
   */
  struct NodeDouble
  {
    int key{};
    int value{};
    NodeDouble *next{};
    NodeDouble *prev{};

    NodeDouble(int k, int v) :
      key(k),
      value(v) {};
  };

  /**
   * @brief Reverse linked list
   *
   *
   * @param head
   * @return ListNode*
   */
  NodeSingle *reverseLinkedList(NodeSingle *head);

  /**
   * @brief Detect cycle in a linked-list based on Hare-Tortoise algorithm (Floyd's cycle finding
   * algorithm )
   *
   * @param head
   * @return ListNode*
   */
  NodeSingle *detectCycle(NodeSingle *head);

  /**
   * @brief Add
   *
   * @param l1
   * @param l2
   * @return ListNode*
   */
  NodeSingle *addTwoNumbers(NodeSingle *l1, NodeSingle *l2);

} // namespace dsa_practice

#endif
