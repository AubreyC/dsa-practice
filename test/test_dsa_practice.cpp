#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include "dsa_heap.hpp"
#include "dsa_linked_list.hpp"
#include "dsa_lru_cache.hpp"
#include "dsa_search_sort.hpp"

TEST_CASE("Binary Search", "[dsa_practice]")
{
  std::vector<int> numbers = {
    1,
    3,
    5,
    6,
    7,
    8,
    10,
    11,
    33,
  };
  int target = 33;
  bool found = std::find(numbers.begin(), numbers.end(), target) != numbers.end();

  auto ret = dsa_practice::binarySearch(numbers, target);
  REQUIRE(ret.has_value() == found);
}

TEST_CASE("Binary Search - Empty", "[dsa_practice]")
{
  std::vector<int> numbers = {};
  auto ret = dsa_practice::binarySearch(numbers, 42);
  REQUIRE_FALSE(ret.has_value());
}

TEST_CASE("Binary Search - Single element", "[dsa_practice]")
{
  std::vector<int> numbers = {7};
  auto hit = dsa_practice::binarySearch(numbers, 7);
  REQUIRE(hit.has_value());

  auto miss = dsa_practice::binarySearch(numbers, 9);
  REQUIRE_FALSE(miss.has_value());
}

TEST_CASE("Merge", "[dsa_practice]")
{
  std::vector<int> numbers1 = {1, 5, 2, 8, 6, 7, 33, 10, 11};
  std::sort(numbers1.begin(), numbers1.end());

  std::vector<int> numbers2 = {2, 7, 2, 4, 37, 9, 10, 16};
  std::sort(numbers2.begin(), numbers2.end());

  auto ret = dsa_practice::mergeSorted(numbers1, numbers2);

  // Ground truth:
  std::vector<int> truth(numbers1.size() + numbers2.size(), 0);
  auto itTruth = truth.begin();
  itTruth = std::copy(numbers1.begin(), numbers1.end(), itTruth);
  itTruth = std::copy(numbers2.begin(), numbers2.end(), itTruth);
  std::sort(truth.begin(), truth.end());

  REQUIRE(ret == truth);
}

TEST_CASE("Merge - Either empty", "[dsa_practice]")
{
  std::vector<int> leftSorted = {};
  std::vector<int> rightSorted = {1, 2, 3};
  auto ret1 = dsa_practice::mergeSorted(leftSorted, rightSorted);
  REQUIRE(ret1 == rightSorted);

  auto ret2 = dsa_practice::mergeSorted(rightSorted, leftSorted);
  REQUIRE(ret2 == rightSorted);
}

TEST_CASE("Merge - Both empty", "[dsa_practice]")
{
  std::vector<int> leftSorted = {};
  std::vector<int> rightSorted = {};
  auto ret = dsa_practice::mergeSorted(leftSorted, rightSorted);
  REQUIRE(ret.empty());
}

TEST_CASE("Merge Sort", "[dsa_practice]")
{
  const std::vector<int> numbers = {1, 5, 3, 8, 6, 7, 33, 10, 11};
  auto ret = dsa_practice::mergeSort(numbers);

  auto numbersSorted = numbers;
  std::sort(numbersSorted.begin(), numbersSorted.end());
  REQUIRE(ret == numbersSorted);
}

TEST_CASE("Merge Sort - Empty", "[dsa_practice]")
{
  const std::vector<int> numbers = {};
  auto ret = dsa_practice::mergeSort(numbers);
  REQUIRE(ret.empty());
}

TEST_CASE("Merge Sort - Single element", "[dsa_practice]")
{
  const std::vector<int> numbers = {5};
  auto ret = dsa_practice::mergeSort(numbers);
  REQUIRE(ret == numbers);
}

TEST_CASE("LRU Cache - 1", "[dsa_practice]")
{
  dsa_practice::LRUCache LRUCache(2);

  LRUCache.put(1, 10);
  REQUIRE(LRUCache.get(1) == 10);
  LRUCache.put(2, 20);
  LRUCache.put(3, 30);
  REQUIRE(LRUCache.get(2) == 20);
  REQUIRE(LRUCache.get(3) == 30);
  REQUIRE(LRUCache.get(1) == -1);
}

TEST_CASE("LRU Cache - 2", "[dsa_practice]")
{
  dsa_practice::LRUCache LRUCache(2);

  LRUCache.put(1, 1);
  LRUCache.put(2, 2);
  REQUIRE(LRUCache.get(1) == 1);
  LRUCache.put(3, 3);
  REQUIRE(LRUCache.get(2) == -1);
  LRUCache.put(4, 4);
  REQUIRE(LRUCache.get(1) == -1);
  REQUIRE(LRUCache.get(3) == 3);
  REQUIRE(LRUCache.get(4) == 4);
}

TEST_CASE("Heap", "[dsa_practice]")
{
  std::vector<int> test = {1, 44, 3, 4, 23, 25, 6, 56};
  dsa_practice::Heap heap;

  for (const auto v : test)
  {
    heap.add(v);
  };

  std::vector<int> testSorted;
  while (!heap.empty())
  {
    auto top = heap.top();
    if (top)
    {
      testSorted.push_back(top.value());
      heap.pop();
    }
  }

  std::sort(test.begin(), test.end());
  REQUIRE(test == testSorted);
}
