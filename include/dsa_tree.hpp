#ifndef DSA_TREE_HPP
#define DSA_TREE_HPP

#include <functional>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

namespace dsa_practice
{

  struct BinaryNode
  {
    int value{};
    BinaryNode *left{};
    BinaryNode *right{};

    explicit BinaryNode(const int val) :
      value(val) {};
  };

  /**
   * @brief Visit tree In-Order Transversal (left branch -> current node -> right branch)
   *
   * @param node
   * @param fun
   */
  void binaryTreeInOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun);

  /**
   * @brief Visit tree Pre-Order Transversal (current node -> left branch -> right branch)
   *
   * @param node
   * @param fun
   */
  void binaryTreePreOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun);

  /**
   * @brief Visit tree Post Order Transversal (left node -> right node -> current node)
   *
   * @param node
   * @param fun
   */
  void binaryTreePostOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun);

  // Generic graph
  class Graph
  {
    Graph(const int numberNodes) :
      mAdjacentList(numberNodes, std::vector<int>()) {};

  private:
    std::vector<std::vector<int>> mAdjacentList;
  };

} // namespace dsa_practice

#endif
