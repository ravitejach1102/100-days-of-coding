# Search in Rotated Sorted Array

## Description

This C++ program finds the index of a target element in a rotated sorted array using Modified Binary Search.

Example:

4 5 6 7 0 1 2

Target: 0

Output: 4

The target 0 is present at index 4.

## How It Works

First, we find the middle element.

Then we check which half of the array is sorted.

4 5 6 7 | 0 1 2
<--- L1 --->   <--- L2 --->

### L1 - Left Half is Sorted

If the left half is sorted:

- Check if the target is present in L1.
- If yes, search in the left half.
- If no, search in the right half.

### L2 - Right Half is Sorted

If the left half is not sorted, the right half is sorted.

- Check if the target is present in L2.
- If yes, search in the right half.
- If no, search in the left half.

## Simple Logic

Find Middle
    ↓
Is Middle = Target?
    ↓ No
Which half is sorted?
    ↓
L1 or L2
    ↓
Check whether target is in the sorted half
    ↓
Search Left or Right

## Example

```cpp
vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
int target = 0;