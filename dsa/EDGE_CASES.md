# 🧪 The "Will It Break?" Edge Case Checklist
*Before you call the examiner, test these specific scenarios. If your code survives this, it survives anything.*

## 1. Multiple Stacks
- [ ] **The "High Five":** Push to Stack 1 and Stack 2 until they meet. Ensure the "Overflow" message appears exactly when they touch, not one step before or after.
- [ ] **The "Ghost Pop":** Try to pop from an empty Stack 1. Then try empty Stack 2.
- [ ] **The "Lonely Element":** Push one item, pop it, then display. Should show empty.

## 2. Circular Queue
- [ ] **The "Ouroboros":** Fill the queue completely. Delete one. Insert one. (This checks if the wrap-around logic works).
- [ ] **The "Reset":** Enqueue items, then Dequeue ALL of them. `front` and `rear` should reset to -1 (or initial state).

## 3. Doubly Linked List
- [ ] **The "Headshot":** Delete the first element. Does `head` update correctly?
- [ ] **The "Tailspin":** Delete the last element. Does the new last node have `next = NULL`?
- [ ] **The "Singleton":** Insert one element. Delete it. List should be empty (head is NULL).

## 4. Binary Search Tree
- [ ] **The "Root Canal":** Delete the Root node.
  - Case A: Root has no children.
  - Case B: Root has 1 child.
  - Case C: Root has 2 children (the complex swap).
- [ ] **The "Missing Person":** Search for a value that isn't there. Ensure it doesn't crash or loop infinitely.

## 5. Hashing
- [ ] **The "Full House":** Fill every single slot. Then try to insert one more. It should say "Table Full" gracefully.
- [ ] **The "Wrap Around Search":** Insert at index 9 (last slot). Insert another that hashes to 9 (should go to 0). Search for the second one to ensure the search wraps around too.
