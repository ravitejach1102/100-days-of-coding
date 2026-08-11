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


# Remove Duplicates from Sorted Array

## Problem Statement

Given a sorted array, remove the duplicate elements **in-place** so that each element appears only once.

Return the number of unique elements.

### Example

**Input:**
`[1, 1, 2, 2, 3]`

**Output:**
`3`

The first 3 elements of the array should be:

`[1, 2, 3]`

---

## Approach

Since the array is already **sorted**, duplicate elements will always be next to each other.

We use two pointers:

* **`i`** → scans the array and finds new unique elements.
* **`k`** → keeps track of the position where the next unique element should be placed.

The first element is always unique, so we start `k` from `1`.

Whenever `nums[i]` is different from the previous element:

1. Place `nums[i]` at position `k`.
2. Increase `k`.

At the end, `k` represents the number of unique elements.

---

## Logic

The main condition is:

`nums[i] != nums[i - 1]`

* If they are equal → the current element is a duplicate, so skip it.
* If they are different → it is a new unique element, so place it at index `k`.

### Why does this work?

Because the array is sorted, all duplicates are together.

For example:

`[1, 1, 2, 2, 3]`

We only need to check whether the current element is different from the previous element.

---

## Dry Run

### Input

`[1, 1, 2, 2, 3]`

Initially:

* `k = 1`
* First element `1` is already considered unique.

| `i` | Current | Previous | Action                     | Array         |
| --- | ------: | -------: | -------------------------- | ------------- |
| 1   |       1 |        1 | Duplicate → skip           | `[1,1,2,2,3]` |
| 2   |       2 |        1 | New element → place at `k` | `[1,2,2,2,3]` |
| 3   |       2 |        2 | Duplicate → skip           | `[1,2,2,2,3]` |
| 4   |       3 |        2 | New element → place at `k` | `[1,2,3,2,3]` |

At the end:

`k = 3`

So the unique elements are:

`[1, 2, 3]`

Only the first `k` elements are important.

---

## Algorithm

1. Set `k = 1`.
2. Start scanning the array from index `1`.
3. Compare the current element with the previous element.
4. If they are different:

   * Store the current element at position `k`.
   * Increment `k`.
5. If they are the same, skip the element.
6. Return `k`.

---

## Time Complexity

**O(n)**

We scan the array only once.

## Space Complexity

**O(1)**

No extra array is used. The changes are made directly inside the original array.

---

## Key Concept

> Since the array is sorted, duplicates are adjacent.
> We keep only the first occurrence of each value and move unique elements toward the beginning of the array.

### Important

This solution works because the input array is **sorted**.

If the array is not sorted, this approach cannot directly be used. We would need to sort the array first or use another technique.
