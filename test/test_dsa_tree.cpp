#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include "dsa_tree.hpp"

TEST_CASE("Binary Tree In-Order Traversal", "[dsa_practice]")
{
  // Create a binary tree: [1, 2, 3, 4, 5]
  // Expected structure:
  //     1
  //    / \
  //   2   3
  //  / \
  // 4   5
  std::vector<std::optional<int>> treeValues = {{1}, {2}, {3}, {4}, {5}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);

  std::vector<int> result;
  auto collectValues = [&result](int value) { result.push_back(value); };

  dsa_practice::binaryTreeInOrderTransversal(root, collectValues);

  // In-order: left, root, right -> [4, 2, 5, 1, 3]
  std::vector<int> expected = {4, 2, 5, 1, 3};
  REQUIRE(result == expected);

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
}

TEST_CASE("Binary Tree Pre-Order Traversal", "[dsa_practice]")
{
  // Create a binary tree: [1, 2, 3, 4, 5]
  // Expected structure:
  //     1
  //    / \
  //   2   3
  //  / \
  // 4   5
  std::vector<std::optional<int>> treeValues = {{1}, {2}, {3}, {4}, {5}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);

  std::vector<int> result;
  auto collectValues = [&result](int value) { result.push_back(value); };

  dsa_practice::binaryTreePreOrderTransversal(root, collectValues);

  // Pre-order: root, left, right -> [1, 2, 4, 5, 3]
  std::vector<int> expected = {1, 2, 4, 5, 3};
  REQUIRE(result == expected);

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
}

TEST_CASE("Binary Tree Post-Order Traversal", "[dsa_practice]")
{
  // Create a binary tree: [1, 2, 3, 4, 5]
  // Expected structure:
  //     1
  //    / \
  //   2   3
  //  / \
  // 4   5
  std::vector<std::optional<int>> treeValues = {{1}, {2}, {3}, {4}, {5}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);

  std::vector<int> result;
  auto collectValues = [&result](int value) { result.push_back(value); };

  dsa_practice::binaryTreePostOrderTransversal(root, collectValues);

  // Post-order: left, right, root -> [4, 5, 2, 3, 1]
  std::vector<int> expected = {4, 5, 2, 3, 1};
  REQUIRE(result == expected);

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
}

TEST_CASE("Binary Tree Traversals - Empty Tree", "[dsa_practice]")
{
  dsa_practice::BinaryNode *root = nullptr;

  std::vector<int> result;
  auto collectValues = [&result](int value) { result.push_back(value); };

  // All traversals should handle null root gracefully
  dsa_practice::binaryTreeInOrderTransversal(root, collectValues);
  REQUIRE(result.empty());

  result.clear();
  dsa_practice::binaryTreePreOrderTransversal(root, collectValues);
  REQUIRE(result.empty());

  result.clear();
  dsa_practice::binaryTreePostOrderTransversal(root, collectValues);
  REQUIRE(result.empty());
}

TEST_CASE("Binary Tree Traversals - Single Node", "[dsa_practice]")
{
  std::vector<std::optional<int>> treeValues = {{42}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);

  std::vector<int> result;
  auto collectValues = [&result](int value) { result.push_back(value); };

  // All traversals should return [42] for a single node
  dsa_practice::binaryTreeInOrderTransversal(root, collectValues);
  REQUIRE(result == std::vector<int>{42});

  result.clear();
  dsa_practice::binaryTreePreOrderTransversal(root, collectValues);
  REQUIRE(result == std::vector<int>{42});

  result.clear();
  dsa_practice::binaryTreePostOrderTransversal(root, collectValues);
  REQUIRE(result == std::vector<int>{42});

  // Clean up memory
  delete root;
}

TEST_CASE("Binary Tree Breadth First Search", "[dsa_practice]")
{
  // Create a binary tree: [1, 2, 3, 4, 5]
  // Expected structure:
  //     1
  //    / \
  //   2   3
  //  / \
  // 4   5
  std::vector<std::optional<int>> treeValues = {{1}, {2}, {3}, {4}, {5}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);

  auto result = dsa_practice::binaryTreeBreadthFirstSearch(root);

  // BFS/level-order: level by level from left to right
  // Level 0: [1]
  // Level 1: [2, 3]
  // Level 2: [4, 5]
  std::vector<std::vector<int>> expected = {
    {1},
    {2, 3},
    {4, 5}
  };
  REQUIRE(result == expected);

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
}

TEST_CASE("Binary Tree Breadth First Search - Empty Tree", "[dsa_practice]")
{
  dsa_practice::BinaryNode *root = nullptr;

  auto result = dsa_practice::binaryTreeBreadthFirstSearch(root);

  // Should return empty vector for null root
  REQUIRE(result.empty());
}

TEST_CASE("Binary Tree Breadth First Search - Single Node", "[dsa_practice]")
{
  std::vector<std::optional<int>> treeValues = {{42}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);

  auto result = dsa_practice::binaryTreeBreadthFirstSearch(root);

  // Should return single level with single node
  std::vector<std::vector<int>> expected = {{42}};
  REQUIRE(result == expected);

  // Clean up memory
  delete root;
}

TEST_CASE("Binary Tree - Is Valid BST", "[dsa_practice]")
{
  // root = [5,4,6,null,null,3,7] -> false
  std::vector<std::optional<int>> treeValues = {{5}, {4}, {6}, {}, {}, {3}, {7}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(treeValues);
  REQUIRE(dsa_practice::isValidBST(root) == false);

  // root=[2,1,3] -> true
  treeValues = {{2}, {1}, {3}};
  root = dsa_practice::deserializeLevelOrder(treeValues);
  REQUIRE(dsa_practice::isValidBST(root) == true);

  // root=[1,2,3] -> false
  treeValues = {{1}, {2}, {3}};
  root = dsa_practice::deserializeLevelOrder(treeValues);
  REQUIRE(dsa_practice::isValidBST(root) == false);

  // Clean up memory
  delete root;
}
