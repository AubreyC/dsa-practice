#include "dsa_search_sort.hpp"
#include <algorithm>

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
        // Prevent size_t underflow
        if (mid == 0)
        {
          break;
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

} // namespace dsa_practice
