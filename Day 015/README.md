# Reverse a Linked List

## 1. Problem Statement

Given a singly linked list, reverse the order of its nodes.

For example:

`1 -> 2 -> 3 -> 4 -> NULL`

After reversing:

`4 -> 3 -> 2 -> 1 -> NULL`

## 2. Concept

* A linked list contains nodes connected using `next` pointers.
* To reverse the list, we change the direction of these pointers.
* We use three pointers: `prev`, `curr`, and `next`.
* Finally, `head` is updated to the new first node.

## 3. Logic

1. Start with `curr = head` and `prev = NULL`.
2. Store the next node in `next`.
3. Change `curr->next` to point to `prev`.
4. Move `prev` and `curr` one step forward.
5. Repeat until `curr` becomes `NULL`.
6. Set `head = prev`.

## 4. Approach

1. Create a linked list.
2. Set `curr` to `head`.
3. Set `prev` to `NULL`.
4. Reverse each node's `next` pointer.
5. Move to the next node.
6. Set `head` to `prev`.
7. Print the reversed list.

## 5. Dry Run

Example:

`1 -> 2 -> 3 -> 4 -> NULL`

| Step | `prev` | `curr` | Change      |
| ---- | ------ | ------ | ----------- |
| 1    | NULL   | 1      | `1 -> NULL` |
| 2    | 1      | 2      | `2 -> 1`    |
| 3    | 2      | 3      | `3 -> 2`    |
| 4    | 3      | 4      | `4 -> 3`    |
| 5    | 4      | NULL   | Stop        |

Final list:

`4 -> 3 -> 2 -> 1 -> NULL`

## 7. Time Complexity

**O(n)** — Each node is visited once.

## 8. Space Complexity

**O(1)** — Only a few pointer variables are used.


# Detect Cycle and Find Cycle Start in a Linked List

## 1. Problem Statement

Given a singly linked list, check whether it contains a cycle.

If a cycle exists, find the node where the cycle starts.

Example:

`1 -> 2 -> 3 -> 4 -> 5`

If `5` points back to `1`, a cycle exists and the cycle starts at node `1`.

## 2. Concept

* A cycle occurs when a node points back to an earlier node.
* We use **Floyd's Cycle Detection Algorithm**.
* Two pointers, `slow` and `fast`, are used.
* `slow` moves one step and `fast` moves two steps.

## 3. Logic

1. Start both `slow` and `fast` at `head`.
2. Move `slow` one step and `fast` two steps.
3. If they meet, a cycle exists.
4. Move `slow` back to `head`.
5. Move both pointers one step at a time.
6. When they meet again, that node is the start of the cycle.

## 4. Approach

1. Create the linked list.
2. Create a cycle by connecting `tail` to `head`.
3. Use `slow` and `fast` to detect the cycle.
4. If they do not meet, there is no cycle.
5. If they meet, move `slow` to `head`.
6. Move both pointers one step until they meet.
7. Return the meeting node as the cycle start.

## 5. Dry Run

Example:

`1 -> 2 -> 3 -> 4 -> 5`
`↑                 ↓`
`└─────────────────┘`

The cycle starts at node `1`.

### Detect Cycle

* `slow` moves 1 step.
* `fast` moves 2 steps.
* Continue moving until both pointers meet.
* They meet inside the cycle, so a cycle exists.

### Find Cycle Start

Move `slow` back to `head`.

Then move both one step at a time:

* `slow = 1`, `fast = 4`
* `slow = 2`, `fast = 5`
* `slow = 3`, `fast = 1`
* `slow = 4`, `fast = 2`
* `slow = 5`, `fast = 3`
* `slow = 1`, `fast = 4`

They continue until they meet at **node 1**.

So, the cycle starts at node `1`.

## 7. Time Complexity

**O(n)** — The list is traversed a limited number of times.

## 8. Space Complexity

**O(1)** — Only `slow` and `fast` pointers are used.
