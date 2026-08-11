# LeetCode 88 - Merge Sorted Array

## Problem

Merge two sorted arrays into `nums1` in sorted order.

`nums1` has extra space at the end to store the elements of `nums2`.

### Example

`nums1 = [1,2,3,0,0,0]`
`nums2 = [2,5,6]`

Output:

`[1,2,2,3,5,6]`

## Approach

Use three pointers from the **end**:

* `i` → last valid element of `nums1`
* `j` → last element of `nums2`
* `idx` → last position of `nums1`

Compare the elements from the back and place the larger element at `idx`.

This avoids overwriting the existing elements in `nums1`.

## Algorithm

1. Start `i` at `m-1`.
2. Start `j` at `n-1`.
3. Start `idx` at `m+n-1`.
4. Compare `nums1[i]` and `nums2[j]`.
5. Place the larger element at `nums1[idx]`.
6. Move the corresponding pointer backward.
7. Continue until one array is finished.
8. Copy any remaining elements of `nums2`.

## Dry Run

Given:

`nums1 = [1,2,3,0,0,0]`
`nums2 = [2,5,6]`

Initial:

* `i = 2` → `3`
* `j = 2` → `6`
* `idx = 5`

| Step | Compare    | Place          | Array           |
| ---- | ---------- | -------------- | --------------- |
| 1    | `3` vs `6` | `6` at index 5 | `[1,2,3,0,0,6]` |
| 2    | `3` vs `5` | `5` at index 4 | `[1,2,3,0,5,6]` |
| 3    | `3` vs `2` | `3` at index 3 | `[1,2,3,3,5,6]` |
| 4    | `2` vs `2` | `2` at index 2 | `[1,2,2,3,5,6]` |

Now `nums2` has no elements left.

Final result:

`[1,2,2,3,5,6]`


## Complexity

* **Time:** `O(m+n)`
* **Space:** `O(1)`

## Key Point

Merging from the **back** allows us to use the empty spaces in `nums1` without using an extra array.

## Important Note

This approach works because `nums1` has **extra space at the end** to store all elements of `nums2`.

For example:

`nums1 = [1,2,3,0,0,0]`

The last three positions are available for the merged elements.

**If `nums1` does not have extra space, this approach cannot be used directly.** In that case, we can use an **extra array** to store the merged result or use another suitable merging approach.

> **Key Point:** The `O(1)` space solution is possible because `nums1` already has enough space at the end.

