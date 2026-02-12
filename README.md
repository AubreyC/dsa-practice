# Data Structures and Algorithms

Data Structures and Algorithms practice with notes and implementation.

## Ressources

**Books**
- "Cracking the coding interview : 189 programming interview questions and solutions"  - Gayle Laakmann McDowell

**Website**
- [DSA Tutorial - Learn Data Structures and Algorithms](https://www.geeksforgeeks.org/dsa/)
- [NeetCode](https://neetcode.io/roadmap)
- [LeetCode](https://leetcode.com/)

## Concepts:

**Topics:**
- Memory (Stack vs. Heap)
- Recursion
- Dynamic Programming
- Big O: Time and Space

### Structure:

 **Topics:**
- Arrays / Vector
- Hashing
- Two Pointers
- Stack
- Binary search
- Sliding Window
- Linked List
- Trees
- Tries
- Backtracking
- Heap / Priority queue
- Graphs
- Dynamming programming:
  - 1D
  - 2D
- Bit manipulation
- Math & Geometry

**Implementation:**
- [x] Array Data Structure
- [x] String in Data Structure
- [x] Hashing in Data Structure
- [x] Linked List Data Structure
- [x] Stack Data Structure
- [x] Queue Data Structure
- [x] Tree Data Structure
    - BFS search tree (Breadth-First Search)
    - Binary search tree validation
    - Convert traversal list -> Tree
    - Convert Tree -> traversal list
- [] Graph Data Structure
- [] Trie Data Structure

### Algorithms:

**Topics:**
- Algorithms
- Breadth-First Search
- Depth-First Search
- Binary Search Merge Sort
- Quick Sort

**Implementation:**
- [] Searching Algorithms
- [] Sorting Algorithms
- [] Introduction to Recursion
- [] Greedy Algorithms
- [] Graph Algorithms
- [] Dynamic Programming or DP
- [] Bitwise Algorithms

### Miscellaneous Topics

- [] Rotation vs Permutation
- [] Multiplication / Addition incremental numbers
- [] Factorial

### Specific exercices:

**Must know**:
Array / String:
- Implement merge sort
- Implement Binary search
- Impelement tri-search
- Detect cycle in graph (with proof)

Map / Priority queue:
- Min / Max priority queue with custom comparator
- Find K top elements

Two pointers:
- Find middle of linked list
- Find middle of array

Linked list:
- LRU implementation
- Inverse linked list

Binary Tree:
- Binary Tree Level Order Traversal
- Depth First Search:
- Bread First search: Go through tree level by level (use a stack)
- Vector to Tree and Tree to vector

Binary Search Tree:
- search algo
- insertion
- deletion

Backtracking:
- All permutation of size k
- All combination of size k

**Commons exercices:**:
- Reverse linked list
- Find longest non-repeating substring:**
  - Two pointer: StartPtr & EndPtr
  - Hash map / Set
  - Move EndPtr and add char in Set until it is already in Set
  - Move StartPtr until the repeated char, remove the char from the set and move it once
- Find repeating cycle
- Construct Binary Tree from Preorder and Inorder Traversal
- Maximum path in a Binary Tree
- Heapify
- Create priority queue with custom structure and custom comparator
```
       auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        };

       std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> maxHeap(compare);
```
- Merge K sorted list
- Largest common parent of two nodes in binary tree
- Find median of 2 sorted lists

Backtracking:
- All permutation of size k:
  - backtracking (recursion): at each step genetate a n new solution by adding
- All combination of size k:
  - backtracking (recusion): binary tree with each steps:
    - option 1: add current value and recusive
    - option 2: do not add current value and remove current value from the pool of possible value (move index to the right)

### Complexity:

- Heap:
  -  heap sort: `O(nLogn)`
  -  insert, delete, extractMax, and decreaseKey: `O(log N)`

### Notes / Common Problems:

### Hash Data Structure

- **Description:**
  - Holds pairs of `[key: value]` (or just keys)
  - Allows access to values by their key.

- **Implementation:**
  - Data stored in an array of lists (buckets).
  - A hash function computes the index:  `Index = Hash(Key) % size(Array)`.
  - Upon collision, the list at the computed index is searched for the key-value pair
  - Re-hashing involves increasing the array size and recomputing indices.

- **`C++ STL`:**
  - `std::unordered_map` and `std::unordered_set` in C++.

- **Application:**
  - Used in databases, caches, and any scenario requiring fast key-based lookup.

- **Advantage / Disadvantage:**
  - Advantages:
    - Average `O(1)` time complexity for search, insert, and delete operations.
  - Disadvantage:
    - Worst case `O(n)` if many collisions occur or during re-hashing.
    - Requires extra memory for maintaining buckets.

### Linked List

- **Description:**
  - A sequence of nodes
  - Each node contains a value and a pointer to the next (and optionally previous node).

- **Common Implementation:**
  - Can be singly linked (one pointer to next node) or doubly linked (pointers to next and previous nodes).

- **`C++ STL`:**
  `std::list` in C++ (doubly linked list).

- **Application:**
  - Used in queues, deques, LRU caches, and scenarios where dynamic size and efficient insert/delete operations are needed.

- **Advantage / Disadvantage:**
  - Advantage:
    - Constant time insertions and deletions.
    - Dynamic size with no need to reallocate or copy.
  - Disadvantage:
    - No direct access (linear search required), slow access time
    - Poor cache locality due to non-contiguous memory allocation.

### Stack Data Structure

- **Description:**
  - A linear data structure that follows Last In, First Out (LIFO) order.

- **Common Implementation:**
  - Typically implemented using arrays or linked lists.

- **`C++ STL`:**
  `std::stack<T>` in C++.

- **Application:**
  - Used for Undo/Redo functionality, function call contexts (recursion), expression evaluation, and backtracking algorithms.

- **Advantage / Disadvantage:**
  - Advantage:
    - Simple, efficient LIFO access with `O(1)` push and pop operations.
  - Disadvantage:
    - Limited access (only top element accessible).

### Queue Data Structure

- **Description:**
  - A linear data structure that follows First In, First Out (FIFO) order.

- **Common Implementation:**
  - Often implemented using arrays or linked lists.

- **`C++ STL`:**
  - `std::queue<T>` in C++.

- **Application:**
  - Used in task scheduling, breadth-first search, buffering, and asynchronous data processing.
  - Producer / Consumer pattern

- **Advantage / Disadvantage:**
  - Advantage:
    - Simple FIFO access with `O(1)` enqueue and dequeue operations.
  - Disadvantage:
    - Limited access (only front and rear accessible).

### Tree Data Structure

**Tree:**
- Root node: No parent, Some children node
- Each node: One parent, Some children node

Types of Tree
- Binary Tree : Every node has at most two children
- Ternary Tree : Every node has at most three children
- N-ary Tree : Every node has at most n children.

Binary Search Tree (BTS):
- Each node has up to two children maximum
- For each node `n`: All left descendents <= `n` < all right descendents

Balanced Binary Tree:
-  A binary tree where the difference in heights between the left and right subtrees of any node is minimal (often defined as at most 1).

Complete Binary Trees:
- A binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Full Binary Tree:
- A binary tree where every node has either 0 or 2 children.

Perfect Binary Tree:
- A perfect binary tree is one that is both full and complete.
- All leaf nodes will be at the same level, and this level has the maximum number of nodes.

Binary Heap: Min Heap or Max heap
- Must be a Complete Binary Trees
-  Min Heap (opposite for Max heap):
  - Key at the root must be the smallest among all the keys in the heap
  - This property must hold true recursively for all nodes.

### Graph

Topics:
- Depth First Search or DFS for a Graph
- Priority Queue


