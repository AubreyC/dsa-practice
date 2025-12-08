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

TEST_CASE("Binary Tree - Serialize Level Order", "[dsa_practice]")
{
  // Test empty tree
  dsa_practice::BinaryNode *root = nullptr;
  auto result = dsa_practice::serializeLevelOrder(root);
  REQUIRE(result.empty());

  // Test single node
  root = new dsa_practice::BinaryNode(42);
  result = dsa_practice::serializeLevelOrder(root);
  std::vector<std::optional<int>> expected = {{42}};
  REQUIRE(result == expected);
  delete root;

  // Test complete binary tree: [1, 2, 3, 4, 5, 6, 7]
  // Expected structure:
  //       1
  //      / \
  //     2   3
  //    / \ / \
  //   4  5 6  7
  std::vector<std::optional<int>> treeValues = {{1}, {2}, {3}, {4}, {5}, {6}, {7}};
  root = dsa_practice::deserializeLevelOrder(treeValues);
  result = dsa_practice::serializeLevelOrder(root);
  REQUIRE(result == treeValues);

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  // Test unbalanced tree with nulls: [1, 2, null, 4]
  // Expected structure:
  //     1
  //    /
  //   2
  //  /
  // 4
  treeValues = {{1}, {2}, {}, {4}};
  root = dsa_practice::deserializeLevelOrder(treeValues);
  result = dsa_practice::serializeLevelOrder(root);
  expected = {{1}, {2}, {}, {4}};
  REQUIRE(result == expected);

  // Clean up memory
  delete root->left->left;
  delete root->left;
  delete root;
}

TEST_CASE("Binary Tree - Deserialize Level Order", "[dsa_practice]")
{
  // Test empty input
  std::vector<std::optional<int>> input = {};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(input);
  REQUIRE(root == nullptr);

  // Test null root
  input = {{}};
  root = dsa_practice::deserializeLevelOrder(input);
  REQUIRE(root == nullptr);

  // Test single node
  input = {{42}};
  root = dsa_practice::deserializeLevelOrder(input);
  REQUIRE(root != nullptr);
  REQUIRE(root->value == 42);
  REQUIRE(root->left == nullptr);
  REQUIRE(root->right == nullptr);
  delete root;

  // Test complete binary tree: [1, 2, 3, 4, 5, 6, 7]
  input = {{1}, {2}, {3}, {4}, {5}, {6}, {7}};
  root = dsa_practice::deserializeLevelOrder(input);
  REQUIRE(root != nullptr);
  REQUIRE(root->value == 1);
  REQUIRE(root->left != nullptr);
  REQUIRE(root->left->value == 2);
  REQUIRE(root->right != nullptr);
  REQUIRE(root->right->value == 3);
  REQUIRE(root->left->left != nullptr);
  REQUIRE(root->left->left->value == 4);
  REQUIRE(root->left->right != nullptr);
  REQUIRE(root->left->right->value == 5);
  REQUIRE(root->right->left != nullptr);
  REQUIRE(root->right->left->value == 6);
  REQUIRE(root->right->right != nullptr);
  REQUIRE(root->right->right->value == 7);

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;
}

TEST_CASE("Binary Tree - Serialize/Deserialize Round Trip", "[dsa_practice]")
{
  // Test various tree structures for round-trip consistency

  // Test 1: Complete binary tree
  std::vector<std::optional<int>> original = {{1}, {2}, {3}, {4}, {5}, {6}, {7}};
  dsa_practice::BinaryNode *root = dsa_practice::deserializeLevelOrder(original);
  auto serialized = dsa_practice::serializeLevelOrder(root);
  REQUIRE(serialized == original);

  // Clean up
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  // Test 2: Unbalanced tree
  original = {{1}, {2}, {}, {4}};
  root = dsa_practice::deserializeLevelOrder(original);
  serialized = dsa_practice::serializeLevelOrder(root);
  REQUIRE(serialized == original);

  // Clean up
  delete root->left->left;
  delete root->left;
  delete root;

  // Test 3: Single node
  original = {{42}};
  root = dsa_practice::deserializeLevelOrder(original);
  serialized = dsa_practice::serializeLevelOrder(root);
  REQUIRE(serialized == original);

  // Clean up
  delete root;
}
