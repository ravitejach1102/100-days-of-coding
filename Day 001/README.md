# Binary Search

## Problem
Given a sorted array of integers and a target value, return the index of the target if it exists. Otherwise, return -1.

## Approach
I used the Binary Search algorithm. Since the array is sorted, I repeatedly checked the middle element and reduced the search range based on whether the target was smaller or larger than the middle value.

## Algorithm
1. Initialize two pointers: `left` and `right`.
2. Find the middle element.
3. If the middle element is the target, return its index.
4. If the target is smaller, search the left half.
5. If the target is larger, search the right half.
6. Repeat until the target is found or the search range becomes empty.

## Time Complexity
O(log n)

## Space Complexity
O(1)

## Concepts Learned
- Binary Search
- Divide and Conquer
- Searching in a Sorted Array
- Time Complexity Analysis

## Language
C++