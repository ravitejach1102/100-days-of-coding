# Search in Rotated Sorted Array

## Description

This C++ program searches for a target element in a **rotated sorted array** using **Modified Binary Search**.

### Example

```cpp
Array:  4 5 6 7 0 1 2
Target: 0

Output: 4
```

The target `0` is present at index `4`.

## How It Works

In a normal binary search, the array is completely sorted.

But here, the array is **rotated**:

```text
4 5 6 7 | 0 1 2
```

At every step:

1. Find the middle element.
2. If the middle element is the target, return its index.
3. Check which side of the array is sorted.
4. Check if the target can be present in that sorted side.
5. Continue searching in the correct half.

### Simple Example

```text
4 5 6 7 | 0 1 2
      ↑
     mid
```

The left side `4 5 6 7` is sorted.

Since `0` is not between `4` and `7`, we search the **right side**.

```text
4 5 6 7 | 0 1 2
          ↑
        search
```

Eventually, we find `0` at index `4`.

## Algorithm

```text
Find middle
    ↓
Is middle the target?
    ↓ No
Find which half is sorted
    ↓
Can target be in that half?
    ↓
Search that half
    ↓
Repeat
```

## Example Code

```cpp
vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
int target = 0;
```

## Time Complexity

**O(log n)** — Modified Binary Search

## Space Complexity

**O(1)** — No extra array is used.


# Remove Element

## Problem

Given a vector `nums` and a value `val`, remove all occurrences of `val` from the vector.

Return the number of remaining elements.

## Example

### Input

```cpp
nums = {3, 2, 2, 3}
val = 3
```

### Output

```text
length: 2
array: 2 2
```

## Approach

We create a new vector called `ans`.

1. Traverse the original vector using a `for` loop.
2. Check each element.
3. If the element is **not equal** to `val`, add it to `ans`.
4. If the element is equal to `val`, skip it.
5. Copy `ans` back to `nums`.
6. Return the size of `nums`.

### Example Walkthrough

```text
nums = {3, 2, 2, 3}
val = 3
```

| Element | Condition  | Action       |
| ------- | ---------- | ------------ |
| 3       | `3 != 3` ❌ | Skip         |
| 2       | `2 != 3` ✅ | Add to `ans` |
| 2       | `2 != 3` ✅ | Add to `ans` |
| 3       | `3 != 3` ❌ | Skip         |

Final vector:

```text
ans = {2, 2}
```

## Time Complexity

**O(n)**

We visit every element once.

## Space Complexity

**O(n)**

We create a new vector `ans` to store the elements that are not equal to `val`.

## Key Idea

```text
If nums[i] != val
        ↓
Add nums[i] to ans

If nums[i] == val
        ↓
Skip it
```
