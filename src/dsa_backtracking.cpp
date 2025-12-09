#include "dsa_backtracking.hpp"

#include <iostream>
#include <vector>

namespace dsa_practice
{
  namespace
  {
    void getPermutations(
      std::vector<std::vector<int>> &result,
      std::vector<int> &currentNums,
      const int k,
      const int currentIdx)
    {
      // Recursively:
      // - Iterate over candidate [currentIdx; end of nums]
      // - Move the value in front of the vector (so we can't choose it at the next recursive
      // iteration)
      // - Once we reach k iteration: the k first values of the vector is the current permutation
      if (currentIdx >= k)
      {
        std::vector<int> ret(k);
        std::copy(currentNums.begin(), currentNums.begin() + k, ret.begin());
        result.push_back(ret);
        return;
      }

      for (size_t idx = currentIdx; idx < currentNums.size(); idx++)
      {
        std::swap(currentNums[currentIdx], currentNums[idx]);
        getPermutations(result, currentNums, k, currentIdx + 1);
        std::swap(currentNums[currentIdx], currentNums[idx]);
      }

      return;
    }
  } // namespace

  std::vector<std::vector<int>> computePermutation(const std::vector<int> &nums, const int k)
  {
    std::vector<std::vector<int>> resuslt;
    std::vector<int> currentNums = nums;
    getPermutations(resuslt, currentNums, k, 0);
    return resuslt;
  }
} // namespace dsa_practice
