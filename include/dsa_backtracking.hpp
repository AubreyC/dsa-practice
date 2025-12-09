#ifndef BACKTRACKING_TREE_HPP
#define BACKTRACKING_TREE_HPP

#include <functional>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

namespace dsa_practice
{

  /**
   * @brief Compute all permutation subsets of size k (without repetition)
   *
   * @param nums
   * @param k
   * @return std::vector<std::vector<int>>
   */
  std::vector<std::vector<int>> computePermutation(const std::vector<int> &nums, const int k);

} // namespace dsa_practice

#endif
