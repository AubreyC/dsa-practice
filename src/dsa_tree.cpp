#include "dsa_tree.hpp"
#include <queue>

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

  std::vector<std::vector<int>>
  mergeLevels(const std::vector<std::vector<int>> &lhs, const std::vector<std::vector<int>> &rhs)
  {
    int s = std::max(rhs.size(), lhs.size());
    std::vector<std::vector<int>> ret(s, std::vector<int>());
    for (int idx = 0; idx < s; idx++)
    {
      if (idx < lhs.size())
      {
        ret[idx].insert(ret[idx].end(), lhs[idx].begin(), lhs[idx].end());
      }
      if (idx < rhs.size())
      {
        ret[idx].insert(ret[idx].end(), rhs[idx].begin(), rhs[idx].end());
      }
    }
    return ret;
  }

  /**
   * @brief Given a binary tree root, return the level order traversal of it as a nested list, where
   * each sublist contains the values of nodes at a particular level in the tree, from left to
   * right.
   *
   * @param root
   * @return std::vector<std::vector<int>>
   */
  std::vector<std::vector<int>> computeLevelOrder(BinaryNode *root)
  {
    std::vector<std::vector<int>> ret;
    if (root)
    {
      ret.push_back({root->value});
      auto leftOrder = computeLevelOrder(root->left);
      auto rightOrder = computeLevelOrder(root->right);
      auto temp = mergeLevels(leftOrder, rightOrder);
      ret.insert(ret.end(), temp.begin(), temp.end());
    }
    return ret;
  }

  /**
   * @brief Visit tree Post Order Transversal (left node -> right node -> current node)
   *
   * @param node
   * @param fun
   */

  std::vector<std::vector<int>> binaryTreeBreadthFirstSearch(BinaryNode *root)
  {
    // Logic:
    // - Recursive logic with a queue
    // - Start with root node in the queue
    // - Iterate over the queue:
    //   - When processing node from queue, add its children to the queue
    //   - So nodes in the queue are in transversal order, and therfore are processed in transversal
    //   order

    std::vector<std::vector<int>> ret;
    if (!root)
    {
      return ret;
    }

    std::queue<BinaryNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
      std::vector<int> levelVect;
      size_t levelSize = queue.size();
      for (size_t l = 0; l < levelSize; l++)
      {
        BinaryNode *node = queue.front();
        queue.pop();

        if (node->left)
        {
          queue.push(node->left);
        }
        if (node->right)
        {
          queue.push(node->right);
        }
        levelVect.push_back(node->value);
      }
      ret.push_back(levelVect);
    }
    return ret;
  }

  BinaryNode *createBinaryTree(const std::vector<int> &nodeValues)
  {
    if (nodeValues.size() == 0)
    {
      return nullptr;
    }

    std::queue<BinaryNode *> queue;

    size_t idx = 0;
    BinaryNode *root = new BinaryNode(nodeValues[idx++]);

    queue.push(root);
    while (idx < nodeValues.size())
    {
      BinaryNode *node = queue.front();

      if (idx < nodeValues.size())
      {
        node->left = new BinaryNode(nodeValues[idx++]);
        queue.push(node->left);
      }

      if (idx < nodeValues.size())
      {
        node->right = new BinaryNode(nodeValues[idx++]);
        queue.push(node->left);
      }
    }

    return root;
  }

  bool isValidBST(BinaryNode *root, std::optional<int> min, std::optional<int> max)
  {
    if (!root)
    {
      return true;
    }

    if (min && root->value <= min.value())
    {
      return false;
    }

    if (max && root->value >= max.value())
    {
      return false;
    }

    std::optional<int> minLeft = min;
    std::optional<int> maxLeft = {
      max.has_value() ? std::min(max.value(), root->value) : root->value};

    std::optional<int> minRight = {
      min.has_value() ? std::max(min.value(), root->value) : root->value};
    std::optional<int> maxRight = max;

    return isValidBST(root->left, minLeft, maxLeft) && isValidBST(root->right, minRight, maxRight);
  }

} // namespace dsa_practice
