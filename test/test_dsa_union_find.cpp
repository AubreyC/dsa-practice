#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include "dsa_union_find.hpp"

TEST_CASE("UnionFind Constructor", "[dsa_practice]")
{
  SECTION("Constructor with size 0")
  {
    dsa_practice::UnionFind uf(0);
    // Should not crash, though not very useful
  }

  SECTION("Constructor with size 5")
  {
    dsa_practice::UnionFind uf(5);

    // Each element should be its own parent initially
    REQUIRE(uf.find(0) == 0);
    REQUIRE(uf.find(1) == 1);
    REQUIRE(uf.find(2) == 2);
    REQUIRE(uf.find(3) == 3);
    REQUIRE(uf.find(4) == 4);
  }
}

TEST_CASE("UnionFind Basic Find Operations", "[dsa_practice]")
{
  dsa_practice::UnionFind uf(5);

  SECTION("Find on single element")
  {
    REQUIRE(uf.find(0) == 0);
    REQUIRE(uf.find(2) == 2);
    REQUIRE(uf.find(4) == 4);
  }

  SECTION("Find with path compression")
  {
    // Union 0->1->2
    uf.unionSets(0, 1);
    uf.unionSets(1, 2);

    // Find 2 should return root (0) and compress path
    REQUIRE(uf.find(2) == 0);

    // After path compression, 2's parent should be 0 directly
    // Note: This tests internal behavior, but find should still work correctly
    REQUIRE(uf.find(2) == 0);
    REQUIRE(uf.find(1) == 0);
  }
}

TEST_CASE("UnionFind Basic Union Operations", "[dsa_practice]")
{
  dsa_practice::UnionFind uf(6);

  SECTION("Union two separate elements")
  {
    uf.unionSets(0, 1);
    REQUIRE(uf.find(0) == uf.find(1));
  }

  SECTION("Union already connected elements")
  {
    uf.unionSets(0, 1);
    uf.unionSets(1, 2); // Should not crash
    REQUIRE(uf.find(0) == uf.find(1));
    REQUIRE(uf.find(1) == uf.find(2));
    REQUIRE(uf.find(0) == uf.find(2));
  }

  SECTION("Multiple unions creating chain")
  {
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(1, 2);

    // All should be connected: 0-1-2-3
    REQUIRE(uf.find(0) == uf.find(1));
    REQUIRE(uf.find(1) == uf.find(2));
    REQUIRE(uf.find(2) == uf.find(3));
    REQUIRE(uf.find(0) == uf.find(3));
  }
}

TEST_CASE("UnionFind Union by Rank", "[dsa_practice]")
{
  dsa_practice::UnionFind uf(8);

  SECTION("Union with equal ranks")
  {
    // Initially all ranks are 0
    uf.unionSets(0, 1); // Both rank 0, 1 attaches to 0, 0's rank becomes 1

    uf.unionSets(2, 3); // Both rank 0, 3 attaches to 2, 2's rank becomes 1

    // Now union sets with rank 1
    uf.unionSets(0, 2); // rank 0=1, rank 2=1, so 2 attaches to 0, 0's rank becomes 2

    REQUIRE(uf.find(0) == uf.find(1));
    REQUIRE(uf.find(0) == uf.find(2));
    REQUIRE(uf.find(0) == uf.find(3));
  }

  SECTION("Union with different ranks")
  {
    // Create a set with higher rank
    uf.unionSets(0, 1); // 0 gets rank 1
    uf.unionSets(1, 2); // 0 gets rank 2

    // Union with lower rank element
    uf.unionSets(0, 3); // 3 (rank 0) attaches to 0 (rank 2)

    REQUIRE(uf.find(0) == uf.find(3));
    REQUIRE(uf.find(1) == uf.find(3));
    REQUIRE(uf.find(2) == uf.find(3));
  }
}

TEST_CASE("UnionFind Complex Scenarios", "[dsa_practice]")
{
  dsa_practice::UnionFind uf(10);

  SECTION("Multiple disjoint sets")
  {
    // Create three separate sets: {0,1,2}, {3,4}, {5,6,7,8}
    uf.unionSets(0, 1);
    uf.unionSets(1, 2);
    uf.unionSets(3, 4);
    uf.unionSets(5, 6);
    uf.unionSets(6, 7);
    uf.unionSets(7, 8);

    // Verify sets are separate
    REQUIRE(uf.find(0) == uf.find(1));
    REQUIRE(uf.find(1) == uf.find(2));
    REQUIRE(uf.find(3) == uf.find(4));
    REQUIRE(uf.find(5) == uf.find(6));
    REQUIRE(uf.find(6) == uf.find(7));
    REQUIRE(uf.find(7) == uf.find(8));

    // Verify different sets are not connected
    REQUIRE(uf.find(0) != uf.find(3));
    REQUIRE(uf.find(0) != uf.find(5));
    REQUIRE(uf.find(3) != uf.find(5));

    REQUIRE(uf.find(9) != uf.find(0)); // 9 is alone
  }

  SECTION("Connecting multiple sets")
  {
    // Start with separate sets
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);

    // Connect them all
    uf.unionSets(1, 2);
    uf.unionSets(3, 4);

    // All should be connected now
    REQUIRE(uf.find(0) == uf.find(1));
    REQUIRE(uf.find(1) == uf.find(2));
    REQUIRE(uf.find(2) == uf.find(3));
    REQUIRE(uf.find(3) == uf.find(4));
    REQUIRE(uf.find(4) == uf.find(5));
  }
}

TEST_CASE("UnionFind Edge Cases", "[dsa_practice]")
{
  SECTION("Size 1")
  {
    dsa_practice::UnionFind uf(1);
    REQUIRE(uf.find(0) == 0);

    // Union with itself should not crash
    uf.unionSets(0, 0);
    REQUIRE(uf.find(0) == 0);
  }

  SECTION("Size 2")
  {
    dsa_practice::UnionFind uf(2);

    // Initially separate
    REQUIRE(uf.find(0) == 0);
    REQUIRE(uf.find(1) == 1);

    // Union them
    uf.unionSets(0, 1);
    REQUIRE(uf.find(0) == uf.find(1));
  }
}
