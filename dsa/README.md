# DSA Lab Programs 🧠

Here are your 12 essential programs for the lab exam, simplified and ready to go.

| Program File | Lines | The "Don't Forget" Logic / Fun Explanation |
| :--- | :---: | :--- |
| **01_pointers.c** | 51 | **The Treasure Map.**<br>`&` (Address Of) is the coordinates.<br>`*` (Dereference) is digging up the treasure at those coordinates.<br>Pointer Arithmetic: Moving the map `+1` moves you by `sizeof(int)` bytes, not just 1 byte. |
| **02_dynamic_memory.c** | 67 | **The Hotel Booking.**<br>`malloc`: Book a room (unclean).<br>`calloc`: Book a room + room service cleans it (sets to 0).<br>`realloc`: Move to a bigger suite.<br>`free`: **Checkout!** If you don't `free`, you leak memory (money). |
| **03_structure.c** | 48 | **The Backpack.**<br>Instead of carrying 3 separate loose items (int, char, float), zip them all into one `struct Student` backpack. Access items inside with a dot `.` (e.g., `s.name`). |
| **04_stack.c** | 66 | **Stack of Plates.**<br>**LIFO** (Last In, First Out).<br>Only touch the `top`.<br>`push`: `top++`, put plate.<br>`pop`: take plate, `top--`.<br>Check `top == -1` for empty. |
| **05_queue.c** | 68 | **Ticket Counter Line.**<br>**FIFO** (First In, First Out).<br>Enter at `rear` (join line), Leave from `front` (get ticket).<br>Reset `front` & `rear` to -1 if the queue becomes empty. |
| **06_circular_queue.c** | 84 | **The Round Table.**<br>Don't waste space! If you hit the end of the array, wrap around to index 0.<br>Logic: `rear = (rear + 1) % MAX`.<br>Full if `(rear + 1) % MAX == front`. |
| **07_multiple_stacks_queues.c** | 130 | **The Shared Shelf.**<br>Two stacks fighting for space in one array.<br>Stack 1 starts at `0` and grows right (`top1++`).<br>Stack 2 starts at `MAX` and grows left (`top2--`).<br>Full when `top1 < top2 - 1` is FALSE (they crash). |
| **08_doubly_linked_list.c** | 113 | **Holding Hands.**<br>Each node holds hands with the guy behind (`prev`) and the guy ahead (`next`).<br>Insert: Connect 4 hands (NewNode's prev/next & Neighbors' prev/next).<br>Delete: Bypass the node (Neighbor A holds Neighbor B's hand directly). |
| **09_singly_linked_list.c** | 172 | **The Conga Line.**<br>You only know who is in front of you (`next`). You can't look back.<br>**Critical**: Never lose the `head` pointer, or you lose the whole list.<br>To delete: Stop *before* the target node so you can re-link the chain. |
| **10_tree_traversals.c** | 64 | **The Camera Angles.**<br>Where is the Root?<br>**Pre**-order: Root First (`Root` -> Left -> Right)<br>**In**-order: Root Middle (Left -> `Root` -> Right)<br>**Post**-order: Root Last (Left -> Right -> `Root`) |
| **11_bst.c** | 92 | **The Bouncer.**<br>Smaller value? Go **Left**.<br>Larger value? Go **Right**.<br>Duplicate? usually ignored.<br>Delete is tricky: If the node has 2 kids, replace it with the **smallest guy from the right side** (inorder successor). |
| **12_static_hashing.c** | 72 | **The Parking Lot.**<br>Calculate spot: `key % size`.<br>Spot taken? **Drive to the next slot** (Linear Probing).<br>Search? Go to calculated spot, if not there, check next slots until found or empty. |

## 🚀 Quick Commands
To compile and run any of these:
```bash
gcc dsa/04_stack.c -o stack
./stack
```

## ⚠️ Exam Survival Guide (Mnemonics)
*   **Pointers**: `&` = Where, `*` = What.
*   **Linked Lists**: Always check `if (head == NULL)` first.
*   **Queue**: `front` tracks who is next to be served, `rear` tracks the new guy.
*   **Recursion (Trees)**: Trust the function to do its job for the child nodes. Don't overthink the sub-steps.
