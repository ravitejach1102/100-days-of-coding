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

# Running Sum of 1D Array

## Problem
Given an integer array `nums`, return the running sum of the array. The running sum at each index is the sum of all the elements from the beginning of the array up to that index.

## Approach
I initialized a variable `sum` to store the cumulative sum. I traversed the array from left to right, added each element to `sum`, and stored the updated value in a new vector. Finally, I returned the resulting vector containing the running sums.

## Algorithm
1. Create an empty vector `result`.
2. Initialize a variable `sum` with `0`.
3. Traverse the array from the first element to the last.
4. Add the current element to `sum`.
5. Store `sum` in the `result` vector.
6. Return the `result` vector.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Concepts Learned
- Arrays
- Vectors
- Running Sum
- Prefix Sum
- Array Traversal

## Language
C++

# Sorting a Vector

## Platform
HackerRank

## Difficulty
Easy

## Approach
Stored the elements in a vector and used the C++ STL `sort()` function to arrange them in ascending order.

## Time Complexity
O(n log n)

## Space Complexity
O(1)

## Concepts Learned
- Vectors
- STL sort()
- Sorting