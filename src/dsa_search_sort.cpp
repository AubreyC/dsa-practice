#include "dsa_search_sort.hpp"
#include <algorithm>
#include <iostream>

namespace dsa_practice
{

  std::vector<int> mergeSorted(const std::vector<int> &lhs, const std::vector<int> &rhs)
  {
    auto itLhs = lhs.begin();
    auto itRhs = rhs.begin();

    std::vector<int> ret(lhs.size() + rhs.size(), 0);
    auto itRet = ret.begin();
    while (itLhs != lhs.end() || itRhs != rhs.end())
    {
      if (itLhs == lhs.end())
      {
        *itRet = *itRhs;
        itRhs++;
        itRet++;
      }
      else if (itRhs == rhs.end())
      {
        *itRet = *itLhs;
        itLhs++;
        itRet++;
      }
      else
      {
        if (*itLhs <= *itRhs)
        {
          *itRet = *itLhs;
          itLhs++;
          itRet++;
        }
        else
        {
          *itRet = *itRhs;
          itRhs++;
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

    return mergeSorted(ret1, ret2);
  }

  std::optional<int> binarySearch(const std::vector<int> &numsSorted, const int target)
  {
    if (numsSorted.empty())
    {
      return {};
    }

    int lowdIdx = 0;
    int upperIdx = numsSorted.size() - 1;

    std::optional<int> result;
    while (lowdIdx <= upperIdx)
    {
      int idx = lowdIdx + (upperIdx - lowdIdx) / 2;
      if (numsSorted[idx] == target)
      {
        result = {idx};
        break;
      }
      else if (numsSorted[idx] > target)
      {
        upperIdx = idx - 1;
      }
      else
      {
        lowdIdx = idx + 1;
      }
    }

    return result;
  }

} // namespace dsa_practice
