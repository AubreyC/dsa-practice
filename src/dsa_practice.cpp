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
    if (nums.size() == 1)
    {
      return nums;
    }
    else if (nums.size() == 2)
    {
      if (nums[0] <= nums[1])
      {
        return nums;
      }
      else
      {
        std::vector<int> ret = {nums[1], nums[0]};
        return ret;
      }
    }
    else
    {
      const size_t mid = (nums.size() - 1) / 2;

      const std::vector<int> vec1(nums.begin(), nums.begin() + mid);
      const auto ret1 = mergeSort(vec1);

      const std::vector<int> vec2(nums.begin() + mid, nums.end());
      const auto ret2 = mergeSort(vec2);

      return merge(ret1, ret2);
    }
    return {};
  }

  std::optional<int> binarySearch(const std::vector<int> &nums, const int target)
  {
    // Sort array first
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    // Actual binary search
    size_t idxS = 0;
    size_t idxE = sortedNums.size() - 1;
    while (idxS <= idxE)
    {
      size_t mid = (idxE - idxS) / 2 + idxS;
      if (sortedNums[mid] == target)
      {
        return {mid};
      }
      else if (sortedNums[mid] > target)
      {
        idxE = mid - 1;
      }
      else
      {
        idxS = mid + 1;
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

    // ListNode* currentL1 = l1;
    // ListNode* currentL2 = l2;

    ListNode *headRet = nullptr;
    ListNode *headLast = nullptr;

    int reminder = 0;
    int idx = 0;

    while (currentL1 || currentL2)
    {
      std::cout << "idx: " << idx << std::endl;
      idx++;
      // if(idx > 2)
      // {
      //     break;
      // }

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

} // namespace dsa_practice
