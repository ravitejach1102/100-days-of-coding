# Slow and Fast Pointer - Middle of Linked List

## Main Idea

We use two pointers:

* slow moves 1 step at a time.
* fast moves 2 steps at a time.

Both start from the head.

The main idea is:

When fast reaches the end, slow will be at the middle.

## Odd Number of Nodes

Example:

10 -> 20 -> 30 -> 40 -> 50

There are 5 nodes, so there is only one middle node.

Movement:

Start:
slow = 10
fast = 10

After 1 iteration:
slow = 20
fast = 30

After 2 iterations:
slow = 30
fast = 50

Now fast cannot move 2 more steps.

So slow is at 30.

Middle = 30

## Even Number of Nodes

Example:

10 -> 20 -> 30 -> 40 -> 50 -> 60

There are 6 nodes.

An even-sized list has two middle nodes:

30 and 40

Movement:

Start:
slow = 10
fast = 10

After 1 iteration:
slow = 20
fast = 30

After 2 iterations:
slow = 30
fast = 50

After 3 iterations:
slow = 40
fast = NULL

So slow is at 40.

Middle returned by this method = 40

Important:

For an odd-length list:

* There is one middle node.
* The method returns that middle node.

For an even-length list:

* There are two middle nodes.
* This method returns the second middle node.

## Why Fast Moves 2 Steps

slow moves one step:

slow = slow->next;

fast moves two steps:

fast = fast->next->next;

Because fast moves twice as fast as slow, when fast reaches the end, slow has travelled approximately half of the list.

Therefore, slow points to the middle.

## Why We Use This Condition

while (fast != NULL && fast->next != NULL)

We need to check both because fast moves two nodes at a time.

If fast or fast->next is NULL, fast cannot move two steps safely.

## Key Concept

slow -> 1 step
fast -> 2 steps

Both start at the beginning.

fast reaches the end first.

slow reaches the middle.

This is called the Slow and Fast Pointer Technique.

## Complexity

Time Complexity: O(n)

Space Complexity: O(1)

We only use two extra pointers, slow and fast.

# Palindrome Linked List

## Problem

Check whether a singly linked list is a palindrome.

A linked list is a palindrome if it reads the same from left to right and right to left.

For example:

1 -> 2 -> 2 -> 1

Output:

true

## Approach

The solution uses three steps:

1. Find the middle of the linked list using slow and fast pointers.
2. Reverse the second half of the linked list.
3. Compare the first half with the reversed second half.

## Step 1: Find the Middle

Use two pointers:

Node* slow = head;
Node* fast = head;

- slow moves one step at a time.
- fast moves two steps at a time.

For the list:

1 -> 2 -> 2 -> 1

slow reaches the beginning of the second half.

## Step 2: Reverse the Second Half

Initialize:

Node* curr = slow;
Node* prev = NULL;

The second half is:

2 -> 1 -> NULL

After reversing:

1 -> 2 -> NULL

During reversal, prev keeps track of the previous node.

At the end, prev points to the first node of the reversed second half.

So:

Node* back = prev;

Now back starts from the beginning of the reversed second half.

## Step 3: Compare Both Halves

Initialize:

Node* front = head;
Node* back = prev;

front starts from the beginning of the list.

back starts from the beginning of the reversed second half.

Compare their values:

if (front->data != back->data)

If any values are different, return false.

If all values match, return true.

## Dry Run

Consider:

1 -> 2 -> 2 -> 1 -> NULL

### Step 1: Find the Middle

Initial:

slow = 1
fast = 1

First iteration:

slow = 2
fast = 2

Second iteration:

slow = 2
fast = NULL

The loop stops because fast becomes NULL.

So slow points to the beginning of the second half.

### Step 2: Reverse the Second Half

Initial:

curr = 2
prev = NULL

First iteration:

next = 1
2 -> NULL
prev = 2
curr = 1

Second iteration:

next = NULL
1 -> 2
prev = 1
curr = NULL

After reversal:

prev -> 1 -> 2 -> NULL

Therefore:

back = prev

So:

back -> 1 -> 2 -> NULL

### Step 3: Compare

front starts at the head:

front -> 1 -> 2 -> 2 -> 1

back starts at prev:

back -> 1 -> 2

Comparison:

1 == 1
2 == 2

All values match.

Therefore:

true

## Why This Approach?

The solution reverses the second half of the linked list instead of using an extra array.

This reduces the extra space required by the algorithm.

## Complexity

Time Complexity: O(n)

Space Complexity: O(1)

## Key Concept

Find the middle
-> Reverse the second half
-> Compare both halves
-> All values match -> Palindrome
-> Different value -> Not a Palindrome
