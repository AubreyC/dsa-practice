#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include "dsa_linked_list.hpp"

// Test cases for detectCycle function
TEST_CASE("Detect Cycle in Linked List", "[dsa_practice]")
{
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  dsa_practice::NodeSingle *node1 = new dsa_practice::NodeSingle(1);
  dsa_practice::NodeSingle *node2 = new dsa_practice::NodeSingle(2);
  dsa_practice::NodeSingle *node3 = new dsa_practice::NodeSingle(3);
  dsa_practice::NodeSingle *node4 = new dsa_practice::NodeSingle(4);
  dsa_practice::NodeSingle *node5 = new dsa_practice::NodeSingle(5);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  // No cycle
  REQUIRE(dsa_practice::detectCycle(node1) == nullptr);

  // Create a cycle: 5 -> 3 -> ...
  node5->next = node3;

  // Cycle detected at node with value 3
  dsa_practice::NodeSingle *cycleNode = dsa_practice::detectCycle(node1);
  REQUIRE(cycleNode != nullptr);
  REQUIRE(cycleNode->value == 3);

  // Clean up
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
}

TEST_CASE("Detect Cycle in Single Node", "[dsa_practice]")
{
  // Create a linked list with a single node: 1
  dsa_practice::NodeSingle *node = new dsa_practice::NodeSingle(1);
  node->next = node; // Cycle

  // Cycle detected at the only node
  dsa_practice::NodeSingle *cycleNode = dsa_practice::detectCycle(node);
  REQUIRE(cycleNode != nullptr);
  REQUIRE(cycleNode->value == 1);

  // Clean up
  delete node;
}

TEST_CASE("Detect No Cycle in Empty List", "[dsa_practice]")
{
  // Create an empty list
  dsa_practice::NodeSingle *head = nullptr;

  // No cycle detected
  dsa_practice::NodeSingle *cycleNode = dsa_practice::detectCycle(head);
  REQUIRE(cycleNode == nullptr);
}

// Test cases for reverseLinkedList function
TEST_CASE("Reverse Linked List - Normal Case", "[dsa_practice]")
{
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  dsa_practice::NodeSingle *node1 = new dsa_practice::NodeSingle(1);
  dsa_practice::NodeSingle *node2 = new dsa_practice::NodeSingle(2);
  dsa_practice::NodeSingle *node3 = new dsa_practice::NodeSingle(3);
  dsa_practice::NodeSingle *node4 = new dsa_practice::NodeSingle(4);
  dsa_practice::NodeSingle *node5 = new dsa_practice::NodeSingle(5);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  // Reverse the list: should become 5 -> 4 -> 3 -> 2 -> 1
  dsa_practice::NodeSingle *reversedHead = dsa_practice::reverseLinkedList(node1);

  // Check that the new head is node5
  REQUIRE(reversedHead == node5);
  REQUIRE(reversedHead->value == 5);

  // Check the order of nodes
  REQUIRE(reversedHead->next == node4);
  REQUIRE(reversedHead->next->value == 4);

  REQUIRE(reversedHead->next->next == node3);
  REQUIRE(reversedHead->next->next->value == 3);

  REQUIRE(reversedHead->next->next->next == node2);
  REQUIRE(reversedHead->next->next->next->value == 2);

  REQUIRE(reversedHead->next->next->next->next == node1);
  REQUIRE(reversedHead->next->next->next->next->value == 1);

  // Check that the last node points to nullptr
  REQUIRE(reversedHead->next->next->next->next->next == nullptr);

  // Clean up
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
}

TEST_CASE("Reverse Linked List - Two Nodes", "[dsa_practice]")
{
  // Create a linked list: 1 -> 2
  dsa_practice::NodeSingle *node1 = new dsa_practice::NodeSingle(1);
  dsa_practice::NodeSingle *node2 = new dsa_practice::NodeSingle(2);

  node1->next = node2;

  // Reverse the list: should become 2 -> 1
  dsa_practice::NodeSingle *reversedHead = dsa_practice::reverseLinkedList(node1);

  // Check that the new head is node2
  REQUIRE(reversedHead == node2);
  REQUIRE(reversedHead->value == 2);

  // Check that node2 now points to node1
  REQUIRE(reversedHead->next == node1);
  REQUIRE(reversedHead->next->value == 1);

  // Check that the last node points to nullptr
  REQUIRE(reversedHead->next->next == nullptr);

  // Clean up
  delete node1;
  delete node2;
}

TEST_CASE("Reverse Linked List - Single Node", "[dsa_practice]")
{
  // Create a linked list with a single node: 1
  dsa_practice::NodeSingle *node = new dsa_practice::NodeSingle(1);

  // Reverse the list: should remain 1
  dsa_practice::NodeSingle *reversedHead = dsa_practice::reverseLinkedList(node);

  // Check that the head is still the same node
  REQUIRE(reversedHead == node);
  REQUIRE(reversedHead->value == 1);

  // Check that it still points to nullptr
  REQUIRE(reversedHead->next == nullptr);

  // Clean up
  delete node;
}

TEST_CASE("Reverse Linked List - Empty List", "[dsa_practice]")
{
  // Create an empty list
  dsa_practice::NodeSingle *head = nullptr;

  // Reverse the list: should return nullptr
  dsa_practice::NodeSingle *reversedHead = dsa_practice::reverseLinkedList(head);
  REQUIRE(reversedHead == nullptr);
}
