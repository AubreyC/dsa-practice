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

  /**
   * @brief Visit tree Post Order Transversal (left node -> right node -> current node)
   *
   * @param node
   * @param fun
   */
  std::vector<std::vector<int>> binaryTreeBreadthFirstSearch(BinaryNode *root);

  /**
   * @brief Given a binary tree root, return the level order traversal of it as a nested list, where
   * each sublist contains the values of nodes at a particular level in the tree, from left to
   * right.
   *
   * @param root
   * @return std::vector<std::vector<int>>
   */
  std::vector<std::vector<int>> serializeLevelOrder(BinaryNode *root);

  /**
   * @brief Create a Binary Tree structure from a input level order list
   *
   * @param nodeValues
   * @return BinaryNode*
   */

  BinaryNode *deserializeLevelOrder(const std::vector<std::optional<int>> &nodeValues);

  /**
   * @brief Check if a Binary Search Tree is valid
   *        - root = [5,4,6,null,null,3,7] -> false
   *        - root=[2,1,3] -> true
   *        - root=[1,2,3] -> false
   * @param root
   * @param min
   * @param max
   * @return true
   * @return false
   */
  bool isValidBST(BinaryNode *root, std::optional<int> min = {}, std::optional<int> max = {});

} // namespace dsa_practice

#endif
