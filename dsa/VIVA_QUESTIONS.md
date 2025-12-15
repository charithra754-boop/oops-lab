# 🔥 The "Grill the Student" Viva Questions
*Examiners love these. Be ready.*

## 1. Stacks & Queues
**Q: Real-world application of a Stack?**
A: The "Undo" button in Word, browser history (Back button), and function recursion in programming.

**Q: Real-world application of a Queue?**
A: Printer job scheduling, CPU task scheduling, or waiting in line for coffee.

**Q: Why use a Circular Queue instead of a normal one?**
A: In a normal queue, empty spaces created by dequeuing cannot be reused. Circular queues recycle that space.

**Q: What is "Stack Overflow"?**
A: When you try to push into a full stack. (Also, the website you copy code from).

## 2. Linked Lists
**Q: Advantage of Linked List over Array?**
A: Dynamic size (doesn't get full) and easy insertion/deletion (no shifting elements like in an array).

**Q: Disadvantage of Doubly Linked List?**
A: Requires extra memory for the `prev` pointer and more code to manage connections.

**Q: How do you find the middle of a linked list in one pass?**
A: Use two pointers: a "slow" one (moves 1 step) and a "fast" one (moves 2 steps). When "fast" reaches the end, "slow" is in the middle.

## 3. Trees (BST)
**Q: What makes a tree a "Binary Search Tree"?**
A: For every node, all left descendants are smaller, and all right descendants are larger.

**Q: Which traversal gives the values in sorted order?**
A: **Inorder** traversal (Left-Root-Right).

**Q: Worst-case time complexity for searching in a BST?**
A: **O(n)**. This happens if the tree is a straight line (skewed), effectively becoming a linked list. Balanced trees (like AVL) fix this to O(log n).

## 4. Hashing
**Q: What is a "Collision"?**
A: When two different keys calculate to the same index.

**Q: What is "Linear Probing"?**
A: A collision resolution technique where we search sequentially for the next empty slot.

**Q: What is the "Load Factor"?**
A: The ratio of elements to table size. If it gets too high, collisions increase drastically.
