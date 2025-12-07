#ifndef DSA_UNION_FIND_HPP
#define DSA_UNION_FIND_HPP

#include <cstdlib>
#include <optional>
#include <unistd.h>
#include <vector>

namespace dsa_practice
{
  /**
   * @brief Union-Find data structure
   *
   */
  class UnionFind
  {
  public:
    explicit UnionFind(size_t size);

    /**
     * @brief Find the root of the set containing the element
     *
     * @param elmt
     * @return int
     */
    int find(const int elmt);

    /**
     * @brief Union the sets containing the two elements
     *
     * @param elmtA
     * @param elmtB
     * @return void
     */
    void unionSets(const int elmtA, const int elmtB);

  private:
    std::vector<int> mParent;
    std::vector<int> mRank;
  };
} // namespace dsa_practice

#endif
