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
