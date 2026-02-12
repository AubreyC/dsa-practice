# 📊 Data Structure Time & Space Complexity Cheat Sheet

## 🧱 Arrays
| Operation | Time |
|---------|------|
| Access (by index) | O(1) |
| Search | O(n) |
| Insert (end) | O(1) amortized |
| Insert (middle) | O(n) |
| Delete | O(n) |

---

## 🔗 Linked List (Singly / Doubly)
| Operation | Time |
|---------|------|
| Access | O(n) |
| Search | O(n) |
| Insert (given node) | O(1) |
| Insert (by value) | O(n) |
| Delete (given node) | O(1) |

---

## 📚 Stack
| Operation | Time |
|---------|------|
| Push | O(1) |
| Pop | O(1) |
| Peek | O(1) |
| Search | O(n) |

---

## 🚶 Queue / Deque
| Operation | Time |
|---------|------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |
| Search | O(n) |

---

## 🌳 Hash Table
| Operation | Average | Worst |
|---------|---------|-------|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Delete | O(1) | O(n) |

> Worst case happens due to hash collisions.

---

## 🌲 Binary Search Tree (BST)
| Operation | Average | Worst |
|---------|---------|-------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

---

## 🌳 Balanced BST (AVL / Red-Black Tree)
| Operation | Time |
|---------|------|
| Search | O(log n) |
| Insert | O(log n) |
| Delete | O(log n) |

---

## ⛰️ Heap (Min / Max)
| Operation | Time |
|---------|------|
| Insert | O(log n) |
| Delete (root) | O(log n) |
| Peek | O(1) |
| Build Heap | O(n) |

---

## 🧩 Trie (Prefix Tree)
| Operation | Time |
|---------|------|
| Insert | O(L) |
| Search | O(L) |
| Delete | O(L) |

> L = length of the word

---

## 🕸️ Graph (Adjacency List)
| Operation | Time |
|---------|------|
| Add Vertex | O(1) |
| Add Edge | O(1) |
| BFS / DFS | O(V + E) |

---

## 🧠 Space Complexity Summary
- Array: O(n)
- Linked List: O(n)
- Stack / Queue: O(n)
- Hash Table: O(n)
- Tree: O(n)
- Graph: O(V + E)

---

## 🚀 Quick Interview Tips
- Fast lookup → Hash Table
- Sorted data → Balanced BST
- Min / Max → Heap
- Prefix search → Trie
- LIFO / FIFO → Stack / Queue
