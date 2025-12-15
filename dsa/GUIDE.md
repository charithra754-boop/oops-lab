# The "Don't Panic" Guide to DSA 🚀

Welcome to your personal DSA cheat sheet. This guide is designed to help you *visualize* the code so you don't just memorize it—you understand it.

---

## 1. Multiple Stacks (Two Stacks, One Array)
**The Concept:** Imagine a single long subway tunnel (the array). 
- **Stack 1** enters from the **Left** (Index 0) and builds inward.
- **Stack 2** enters from the **Right** (Index MAX-1) and builds inward.
- **Disaster:** If they meet in the middle, the tunnel is full (Overflow).

**The Golden Rule:**
> "Keep them separated."

**The Code You Must Remember:**
- **Condition for Insertion:** `if (top1 < top2 - 1)`
  - *Why?* There must be at least one empty space between `top1` and `top2`. If `top1` is adjacent to `top2` (e.g., index 4 and 5), the array is full.
- **Initialization:** `top1 = -1` (Left side empty), `top2 = MAX` (Right side empty).

---

## 2. Circular Queue
**The Concept:** A clock face. When the second hand reaches 12, it doesn't stop; it starts over at 1.
- Normal queues break because once `rear` hits the limit, you can't insert anymore, even if you deleted everything from the front!
- Circular queues fix this by wrapping around.

**The Golden Rule:**
> "Modulo `%` is your portal to the beginning."

**The Code You Must Remember:**
- **Next Position:** `(r + 1) % MAX`
  - *Why?* If `r` is 4 and `MAX` is 5, `(4+1) % 5` becomes `0`. Magic wrap-around!
- **Full Condition:** `if ((r + 1) % MAX == f)`
  - *Why?* If the *next* position for `rear` is where `front` is standing, we have caught up to the start of the line. Full!

---

## 3. Doubly Linked List (DLL)
**The Concept:** A conga line where everyone holds hands with the person in front **AND** the person behind.
- **Prev:** Pointer to the guy behind you.
- **Next:** Pointer to the guy in front of you.

**The Golden Rule:**
> "Don't let go of the old hand before grabbing the new one."

**The Code You Must Remember:**
- **Insertion (The Wiring):**
  1. `newNode->next = current->next;` (New guy grabs the person in front)
  2. `newNode->prev = current;` (New guy grabs the person behind)
  3. `current->next->prev = newNode;` (Person in front grabs New guy back)
  4. `current->next = newNode;` (Person behind grabs New guy forward)
- **Deletion:**
  - `temp->prev->next = temp->next;` (The guy behind me now points to the guy in front of me)
  - `temp->next->prev = temp->prev;` (The guy in front of me now points to the guy behind me)
  - *Result:* I am disconnected. `free(temp)`.

---

## 4. Binary Search Tree (BST)
**The Concept:** A distinct family tree.
- **Left Child:** Always *smaller* (or younger) than the parent.
- **Right Child:** Always *larger* (or older) than the parent.

**The Golden Rule:**
> "Divide and Conquer."

**The Code You Must Remember:**
- **Search/Insert:** It's a simple fork in the road.
  - `if (val < root->key) go left`
  - `if (val > root->key) go right`
- **Deletion (The Scary Part):**
  - **Case 1 (No kids):** Just delete it.
  - **Case 2 (One kid):** The parent adopts the grandchild directly.
  - **Case 3 (Two kids):** Find the **Inorder Successor** (Smallest node in the Right Subtree). Replace the value, then delete that successor node (which is easy because it has 0 or 1 child).

---

## 5. Tree Traversals
**The Concept:** How do you explore a maze?
- **Inorder:** Left, Visit, Right. (Returns sorted data in BST).
- **Preorder:** Visit, Left, Right. (Good for copying trees).
- **Postorder:** Left, Right, Visit. (Good for deleting trees).

**The Memory Trick:**
- **PRE**order: Print is **Pre** (Before children).
  - `printf(); traverse(left); traverse(right);`
- **IN**order: Print is **In** (Between children).
  - `traverse(left); printf(); traverse(right);`
- **POST**order: Print is **Post** (After children).
  - `traverse(left); traverse(right); printf();`

---

## 6. Static Hashing (Linear Probing)
**The Concept:** Assigned seating at a wedding table.
- Calculate your seat number: `Key % TableSize`.
- **Conflict:** "Hey, someone is sitting in my seat!"
- **Solution (Linear Probing):** "Fine, I'll just sit in the very next empty chair."

**The Golden Rule:**
> "If the door is locked, try the next one."

**The Code You Must Remember:**
- **Index:** `key % SIZE`
- **Probe Loop:**
  ```c
  for(i = 0; i < SIZE; i++) {
      probe = (index + i) % SIZE;
      if (h[probe] == empty) { insert; break; }
  }
  ```
- *Why the loop?* We check `index`, then `index+1`, then `index+2`... wrapping around with `%` until we find a spot or check the whole table.
