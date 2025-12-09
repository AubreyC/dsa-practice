

// #include "dsa_heap.hpp"
// #include "dsa_practice.hpp"
// #include "structure.hpp"

#include "dsa_backtracking.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string_view>
#include <unistd.h>
#include <vector>

// using namespace std;

// vector<int> dailyTemperatures(vector<int> &temperatures)
// {
//   std::stack<std::pair<int, int>> stack;
//   vector<int> ret(temperatures.size(), 0);

//   for (int idx = 0; idx < temperatures.size(); idx++)
//   {
//     if (stack.empty())
//     {
//       stack.push({temperatures[idx], idx});
//     }
//     else
//     {
//       while (!stack.empty() && stack.top().first <= temperatures[idx])
//       {
//         ret[stack.top().second] = idx - stack.top().second;
//         stack.pop();
//       }
//       stack.push({temperatures[idx], idx});
//     }
//   }
//   return ret;

//   //
//   // std::vector<int> test = {30, 38, 30, 36, 35, 40, 28};
//   // auto ret = dailyTemperatures(test);

//   // for (auto n : ret)
//   // {
//   //   std::cout << n << " " << std::endl;
//   // }
// }

// int largestRectangleArea(vector<int> &heights)
// {
//   auto it = std::max_element(heights.begin(), heights.end());
//   if (it == heights.end())
//   {
//     return 0;
//   }

//   int maxHeight = *it;

//   int ret = 0;
//   for (int currentHeight = 1; currentHeight <= maxHeight; currentHeight++)
//   {
//     std::cout << "checking: " << currentHeight << std::endl;
//     int currentRect = 0;
//     for (auto bar : heights)
//     {
//       std::cout << "bar: " << bar << std::endl;
//       if (bar >= currentHeight)
//       {
//         currentRect++;
//         std::cout << "currentRect: " << currentRect << std::endl;
//       }
//       else
//       {
//         currentRect = currentRect * currentHeight;
//         std::cout << "currentRect done: " << currentRect << std::endl;
//         ret = std::max(currentRect, ret);
//         currentRect = 0;
//       }
//     }
//     if (currentRect > 0)
//     {
//       currentRect = currentRect * currentHeight;
//       std::cout << "currentRect done: " << currentRect << std::endl;
//       ret = std::max(currentRect, ret);
//     }
//   }
//   return ret;
// }

// int largestRectangleAreaBis(vector<int> &heights)
// {
//   std::stack<std::pair<int, int>> stack;
//   int ret = 0;
//   for (int idx = 0; idx < heights.size(); idx++)
//   {
//     if (stack.empty())
//     {
//       stack.push({heights[idx], idx});
//     }
//     else
//     {
//       if (heights[idx] > stack.top().first)
//       {
//         stack.push({heights[idx], idx});
//       }
//       else if (heights[idx] < stack.top().first)
//       {
//         int lastPopIndex = 0;
//         while (!stack.empty() && heights[idx] < stack.top().first)
//         {
//           int rect = stack.top().first * (idx - stack.top().second);
//           ret = std::max(ret, rect);
//           lastPopIndex = stack.top().second;
//           stack.pop();
//         }

//         stack.push({heights[idx], lastPopIndex});
//       }
//     }
//   }

//   while (!stack.empty())
//   {
//     int rect = stack.top().first * (heights.size() - stack.top().second);
//     ret = std::max(ret, rect);
//     stack.pop();
//   }

//   return ret;
// }

// void printVector(const std::vector<int> &values)
// {
//   for (const auto v : values)
//   {
//     std::cout << v << " ";
//   };
//   std::cout << "" << std::endl;
// }

int main(int argc, char *argv[])
{
  std::vector<int> nums = {4, 5, 6, 7, 8};

  auto result = dsa_practice::computePermutation(nums, 3);
  for (auto &p : result)
  {
    for (int v : p)
    {
      std::cout << v << ", ";
    }
    std::cout << "" << std::endl;
  }
}
