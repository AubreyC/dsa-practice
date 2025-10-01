#include "dsa_tree.hpp"

namespace dsa_practice
{

  /**
   * @brief In-order traversal means to "visit" (often, print) the left branch, then the current
   * node, and finally, the right branch. When performed on a binary search tree, it visits the
   * nodes in ascending order (hence the name "in-order").
   *
   * @param rootNode
   * @param fun
   */
  void binaryTreeInOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun)
  {
    if (!node)
    {
      binaryTreeInOrderTransversal(node->left, fun);
      fun(node->value);
      binaryTreeInOrderTransversal(node->right, fun);
    }
  };

  /**
   * @brief Pre-order traversal visits the current node before its child nodes (hence the name
   * "pre-order"). In a pre-order traversal, the root is always the first node visited.
   *
   * @param rootNode
   * @param fun
   */
  void binaryTreePreOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun)
  {
    if (!node)
    {
      fun(node->value);
      binaryTreeInOrderTransversal(node->left, fun);
      binaryTreeInOrderTransversal(node->right, fun);
    }
  }

  /**
   * @brief Post-order traversal visits the current node after its child nodes (hence the name
   * "post-order"). In a post-order traversal, the root is always the last node visited.
   *
   * @param rootNode
   * @param fun
   */
  void binaryTreePostOrderTransversal(BinaryNode *node, const std::function<void(int)> &fun)
  {
    if (!node)
    {
      binaryTreeInOrderTransversal(node->left, fun);
      binaryTreeInOrderTransversal(node->right, fun);
      fun(node->value);
    }
  }

} // namespace dsa_practice
