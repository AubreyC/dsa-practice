#ifndef DSA_SEARCH_SORT_HPP
#define DSA_SEARCH_SORT_HPP

#include <functional>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

namespace dsa_practice
{
  /**
   * @brief Merge two sorted vector
   *
   * @param lhs
   * @param rhs
   * @return std::vector<int>
   */
  std::vector<int> mergeSorted(const std::vector<int> &lhs, const std::vector<int> &rhs);

  /**
   * @brief Merge Sort algorithm
   *
   * @param nums
   * @return std::vector<int>
   */
  std::vector<int> mergeSort(const std::vector<int> &nums);

  /**
   * @brief Simple binary search algorithm
   *
   * @param nums
   * @param target
   * @return std::optional<int>
   */
  std::optional<int> binarySearch(const std::vector<int> &nums, const int target);

} // namespace dsa_practice

#endif
