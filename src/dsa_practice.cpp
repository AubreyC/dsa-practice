#include <algorithm>
#include <iostream>

#include "dsa_practice.hpp"

namespace dsa_practice
{
  std::vector<int> merge(const std::vector<int> &ret1, const std::vector<int> &ret2)
  {
    // Merge two sorted vectors with double pointer (iterator) logic
    auto itRet1 = ret1.begin();
    auto itRet2 = ret2.begin();

    std::vector<int> ret(ret1.size() + ret2.size(), 0);
    auto itRet = ret.begin();
    while (itRet1 != ret1.end() || itRet2 != ret2.end())
    {
      if (itRet1 == ret1.end())
      {
        *itRet = *itRet2;
        itRet2++;
        itRet++;
      }
      else if (itRet2 == ret2.end())
      {
        *itRet = *itRet1;
        itRet1++;
        itRet++;
      }
      else
      {
        if (*itRet1 <= *itRet2)
        {
          *itRet = *itRet1;
          itRet1++;
          itRet++;
        }
        else
        {
          *itRet = *itRet2;
          itRet2++;
          itRet++;
        }
      }
    }
    return ret;
  }

  std::vector<int> mergeSort(const std::vector<int> &nums)
  {
    if (nums.size() <= 1)
    {
      return nums;
    }

    const size_t mid = nums.size() / 2;

    const std::vector<int> vec1(nums.begin(), nums.begin() + mid);
    const auto ret1 = mergeSort(vec1);

    const std::vector<int> vec2(nums.begin() + mid, nums.end());
    const auto ret2 = mergeSort(vec2);

    return merge(ret1, ret2);
  }

  std::optional<int> binarySearch(const std::vector<int> &nums, const int target)
  {
    // Handle empty input
    if (nums.empty())
    {
      return {};
    }

    // Sort array first
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    // Actual binary search (inclusive bounds)
    size_t idxStart = 0;
    size_t idxEnd = sortedNums.size() - 1;
    while (idxStart <= idxEnd)
    {
      size_t mid = (idxEnd - idxStart) / 2 + idxStart;
      if (sortedNums[mid] == target)
      {
        return {static_cast<int>(mid)};
      }
      else if (sortedNums[mid] > target)
      {
        if (mid == 0)
        {
          break; // Prevent size_t underflow
        }
        idxEnd = mid - 1;
      }
      else
      {
        idxStart = mid + 1;
      }
    }

    return {};
  }

  ListNode *inverse(ListNode *head)
  {
    return head;
  }

  ListNode *deepCopy(ListNode *head)
  {
    return head;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *currentL1 = new ListNode(0);
    ListNode *currentL2 = new ListNode(0);

    // Algo:
    // - iterate over the linked list (digits)
    // - compute new digit: sum of the digits from linked lists + reminder
    // - set new digit as sum % 10 and set reminder = sum / 10

    ListNode *headRet = nullptr;
    ListNode *headLast = nullptr;

    int reminder = 0;
    while (currentL1 || currentL2)
    {
      int sum = reminder + (currentL1 ? currentL1->value : 0) + (currentL2 ? currentL2->value : 0);
      reminder = sum / 10;

      ListNode *current = new ListNode(sum % 10);
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
      ListNode *current = new ListNode(reminder);
      headLast->next = current;
    }

    return headRet;
  }

  // Implementation of detectCycle function
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return nullptr;
    }

    ListNode *tortoise = head;
    ListNode *hare = head;

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
