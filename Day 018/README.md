# Merge Sort

## 1. Problem Statement

Given an unsorted array, sort the elements in ascending order.

Example:

`[5, 2, 3, 1]`

After sorting:

`[1, 2, 3, 5]`

## 2. Concept

* **Merge Sort** uses the **Divide and Conquer** technique.
* Divide the array into smaller halves.
* Sort the smaller halves.
* Merge the sorted halves to get the final sorted array.

## 3. Logic

1. Find the middle of the array.
2. Divide the array into a left half and a right half.
3. Keep dividing until each part contains only one element.
4. Merge two sorted parts by comparing their elements.
5. Put the smaller element into a temporary array.
6. Copy the sorted elements back to the original array.

## 4. Approach

1. Call `divide()` with the complete array.
2. Find the middle index.
3. Recursively divide the left half.
4. Recursively divide the right half.
5. Call `merge()` to combine both sorted halves.
6. Repeat until the complete array is sorted.

## 5. Dry Run

Example:

`[5, 2, 3, 1]`

### Step 1: Divide

```text
[5, 2, 3, 1]
      /    \
  [5, 2]  [3, 1]
```

Divide again:

```text
[5] [2]    [3] [1]
```

### Step 2: Merge

Merge `[5]` and `[2]`:

`[2, 5]`

Merge `[3]` and `[1]`:

`[1, 3]`

Now:

```text
[2, 5]    [1, 3]
```

### Step 3: Final Merge

Compare the elements:

* `2` vs `1` → take `1`
* `2` vs `3` → take `2`
* `5` vs `3` → take `3`
* Take remaining `5`

Final array:

`[1, 2, 3, 5]`

## 7. Time Complexity

**O(n log n)** — The array is divided into `log n` levels and each level processes `n` elements.

## 8. Space Complexity

**O(n)** — A temporary array is used while merging.
