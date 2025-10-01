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

  void binaryTreeInOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun);
  void binaryTreePreOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun);
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
