#ifndef DSA_PRACTICE_HPP
#define DSA_PRACTICE_HPP

#include <optional>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

namespace dsa_practice
{

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

} // namespace dsa_practice

#endif
