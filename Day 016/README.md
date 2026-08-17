# Merge Two Sorted Linked Lists

## 1. Problem Statement

Given two sorted linked lists, merge them into one sorted linked list.

Example:

`List 1: 1 -> 2 -> 4`
`List 2: 1 -> 3 -> 4`

Merged list:

`1 -> 1 -> 2 -> 3 -> 4 -> 4`

## 2. Concept

* Both linked lists are already sorted.
* Compare the values of the current nodes.
* Choose the smaller value and move that pointer forward.
* Recursion is used to continue merging the remaining nodes.

## 3. Logic

1. Check if either list is empty.
2. Compare the first nodes of both lists.
3. Keep the smaller node as the current node.
4. Recursively merge the remaining nodes.
5. Return the merged list.

## 4. Approach

1. Take the heads of both sorted lists.
2. If one list is empty, return the other list.
3. Compare `head1->data` and `head2->data`.
4. If `head1` is smaller, connect it with the merged remaining list.
5. Otherwise, connect `head2` with the merged remaining list.
6. Return the new head of the merged list.

## 5. Dry Run

Example:

`List 1: 1 -> 2 -> 4`
`List 2: 1 -> 3 -> 4`

### Step-by-step

* Compare `1` and `1` → take first `1`
* Compare `2` and `1` → take second `1`
* Compare `2` and `3` → take `2`
* Compare `4` and `3` → take `3`
* Compare `4` and `4` → take first `4`
* First list becomes empty → take remaining `4`

Final result:

`1 -> 1 -> 2 -> 3 -> 4 -> 4`

## 7. Time Complexity

**O(n + m)** — Each node from both lists is processed once.

## 8. Space Complexity

**O(n + m)** — Recursion uses stack space for the nodes being processed.

# Reorder Linked List

## 1. Problem Statement

Given a linked list, reorder it in this pattern:

`L0 -> L1 -> L2 -> ... -> Ln`

becomes:

`L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...`

Example:

`1 -> 2 -> 3 -> 4 -> 5`

becomes:

`1 -> 5 -> 2 -> 4 -> 3`

## 2. Concept

* Find the middle of the linked list using **slow and fast pointers**.
* Reverse the second half of the list.
* Merge the first half and reversed second half alternately.
* The list is reordered without creating new nodes.

## 3. Logic

1. Find the middle of the list.
2. Split the list into two halves.
3. Reverse the second half.
4. Take one node from the first half.
5. Take one node from the reversed second half.
6. Connect them alternately.
7. Continue until all nodes are merged.

## 4. Approach

1. Use `slow` and `fast` pointers to find the middle.
2. Split the list at the middle.
3. Reverse the second half.
4. Store the next nodes of both halves.
5. Connect one node from the left and one from the right.
6. Move both pointers forward.
7. Continue until the list is reordered.

## 5. Dry Run

Example:

**Original:**

`1 -> 2 -> 3 -> 4 -> 5`

### Step 1: Split the List

First half:

`1 -> 2 -> 3`

Second half:

`4 -> 5`

### Step 2: Reverse Second Half

`5 -> 4`

### Step 3: Merge Alternately

* Take `1`, then `5` → `1 -> 5`
* Take `2`, then `4` → `1 -> 5 -> 2 -> 4`
* `3` remains → `1 -> 5 -> 2 -> 4 -> 3`

**Final List:**

`1 -> 5 -> 2 -> 4 -> 3`

## 7. Time Complexity

**O(n)** — Finding the middle, reversing, and merging each take linear time.

## 8. Space Complexity

**O(1)** — Only pointer variables are used; no extra data structure is created.

# Reverse Linked List in K Groups

## 1. Problem Statement

Given a linked list and an integer `k`, reverse the nodes of the list in groups of `k`.

If the last group has fewer than `k` nodes, keep that group unchanged.

Example:

`1 -> 2 -> 3 -> 4 -> 5 -> 6`

For `k = 2`:

`2 -> 1 -> 4 -> 3 -> 6 -> 5`

## 2. Concept

* Divide the linked list into groups of `k` nodes.
* Check if `k` nodes are available before reversing.
* Reverse each group using pointers.
* **Recursion** is used to process the remaining groups.

## 3. Logic

1. Start from the current `head`.
2. Check whether `k` nodes are available.
3. If fewer than `k` nodes are available, return the list without changing it.
4. Recursively reverse the remaining groups first.
5. Reverse the current group of `k` nodes.
6. Connect the reversed group to the already processed part.
7. Return the new head of the reversed group.

## 4. Approach

1. Take `head` and `k`.
2. Count `k` nodes to check if a complete group exists.
3. Recursively process the remaining list.
4. Reverse the current `k` nodes.
5. Connect the last node of the current group to the result of recursion.
6. Return the new head.

## 5. Dry Run

Example:

`1 -> 2 -> 3 -> 4 -> 5 -> 6`

`k = 2`

### Step 1: Divide into Groups

`[1 -> 2] [3 -> 4] [5 -> 6]`

### Step 2: Process from the End

The recursion reaches the last group first:

`[5 -> 6]`

Reverse it:

`6 -> 5`

Then return to:

`[3 -> 4]`

Reverse it:

`4 -> 3`

Then return to:

`[1 -> 2]`

Reverse it:

`2 -> 1`

### Step 3: Connect Groups

Final list:

`2 -> 1 -> 4 -> 3 -> 6 -> 5`

Since every group contains exactly `2` nodes, all groups are reversed.

## 7. Time Complexity

**O(n)** — Each node is visited and reversed once.

## 8. Space Complexity

**O(n)** — Recursion uses stack space for the groups being processed.
