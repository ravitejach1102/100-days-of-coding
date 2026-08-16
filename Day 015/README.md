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
