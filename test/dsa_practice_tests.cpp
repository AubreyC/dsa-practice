#include <algorithm>
#include <catch2/catch_test_macros.hpp>

// #include <iostream>

#include "dsa_practice.hpp"

TEST_CASE("Binary Search", "[dsa_practice]")
{
  std::vector<int> numbers = {1, 5, 3, 8, 6, 7, 33, 10, 11};
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

  auto ret = dsa_practice::merge(numbers1, numbers2);

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
  auto ret1 = dsa_practice::merge(leftSorted, rightSorted);
  REQUIRE(ret1 == rightSorted);

  auto ret2 = dsa_practice::merge(rightSorted, leftSorted);
  REQUIRE(ret2 == rightSorted);
}

TEST_CASE("Merge - Both empty", "[dsa_practice]")
{
  std::vector<int> leftSorted = {};
  std::vector<int> rightSorted = {};
  auto ret = dsa_practice::merge(leftSorted, rightSorted);
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
