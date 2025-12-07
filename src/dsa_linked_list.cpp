#include <algorithm>
#include <iostream>

#include "dsa_linked_list.hpp"

namespace dsa_practice
{

  NodeSingle *reverseLinkedList(NodeSingle *head)
  {
    NodeSingle *currentNode = head;
    NodeSingle *previousNode = nullptr;
    while (currentNode)
    {
      NodeSingle *temp = currentNode->next;
      currentNode->next = previousNode;
      previousNode = currentNode;
      currentNode = temp;
    }

    return previousNode;
  }

  NodeSingle *addTwoNumbers(NodeSingle *l1, NodeSingle *l2)
  {
    NodeSingle *currentL1 = new NodeSingle(0);
    NodeSingle *currentL2 = new NodeSingle(0);

    // Algo:
    // - iterate over the linked list (digits)
    // - compute new digit: sum of the digits from linked lists + reminder
    // - set new digit as sum % 10 and set reminder = sum / 10

    NodeSingle *headRet = nullptr;
    NodeSingle *headLast = nullptr;

    int reminder = 0;
    while (currentL1 || currentL2)
    {
      int sum = reminder + (currentL1 ? currentL1->value : 0) + (currentL2 ? currentL2->value : 0);
      reminder = sum / 10;

      NodeSingle *current = new NodeSingle(sum % 10);
      if (!headRet)
      {
        headRet = current;
        headLast = current;
      }
      else
      {
        headLast->next = current;
        headLast = headLast->next;
      }

      if (currentL1)
      {
        currentL1 = currentL1->next;
      }
      if (currentL2)
      {
        currentL2 = currentL2->next;
      }
    }

    if (reminder > 0)
    {
      NodeSingle *current = new NodeSingle(reminder);
      headLast->next = current;
    }

    return headRet;
  }

  // Implementation of detectCycle function
  NodeSingle *detectCycle(NodeSingle *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return nullptr;
    }

    NodeSingle *tortoise = head;
    NodeSingle *hare = head;

    // Phase 1: Finding the meeting point
    while (hare != nullptr && hare->next != nullptr)
    {
      tortoise = tortoise->next; // Move one step
      hare = hare->next->next;   // Move two steps

      if (tortoise == hare)
      {
        break;
      }
    }

    // If there is no cycle, return nullptr
    if (tortoise != hare)
    {
      return nullptr;
    }

    // Phase 2: Finding the starting point of the cycle
    tortoise = head;
    while (tortoise != hare)
    {
      tortoise = tortoise->next; // Move one step
      hare = hare->next;         // Move one step
    }

    return tortoise; // The meeting point is the start of the cycle
  }

} // namespace dsa_practice
