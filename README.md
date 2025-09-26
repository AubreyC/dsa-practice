# Data Structure and Algorithm

## Ressources

Books / Tutorials:
- https://www.geeksforgeeks.org/dsa/
- "Cracking the coding interview : 189 programming interview questions and solutions"  - Gayle Laakmann McDowell

Exercices:
- Neetcode 150

### Structure:

- [x] Array Data Structure
- [x] String in Data Structure
- [x] Hashing in Data Structure
- [x] Linked List Data Structure
- [x] Stack Data Structure
- [x] Queue Data Structure
- [] Tree Data Structure
- [] Graph Data Structure
- [] Trie Data Structure

### Algorithms:

- [] Searching Algorithms
- [] Sorting Algorithms
- [] Introduction to Recursion
- [] Greedy Algorithms
- [] Graph Algorithms
- [] Dynamic Programming or DP
- [] Bitwise Algorithms

### Notes / Common Problems:

Find longest non-repeating substring:
- Two pointer: StartPtr & EndPtr
- Hash map / Set
- Move EndPtr and add char in Set until it is already in Set
- Move StartPtr until the repeated char, remove the char from the set and move it once

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
