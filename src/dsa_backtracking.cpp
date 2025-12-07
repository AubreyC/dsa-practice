#include "backtracking.hpp"

namespace dsa_practice
{
  namespace
  {
    void getPermutations(
      const std::vector<int> &nums,
      const int k,
      std::vector<std::vector<int>> &currentPermutation,
      const int currentIdx)
    {
      if (nums.empty() || k > nums.size())
      {
        return;
      }

      for (const int idx = currentIdx; idx < nums.size(); i++)
      {
        std::vector<std::vector<int>> newPermuations = currentPermutation;
        newPermuations.push_back(n);
        getPermutations(nums, k, newPermuations);
      }
    }
  } // namespace

  std::vector<std::vector<int>> computePermutation(const std::vector<int> &nums, const int k)
  {
    std::vector<std::vector<int>> ret;
    if (nums.empty() || k > nums.size())
    {
      return ret;
    }
  }
} // namespace dsa_practice
