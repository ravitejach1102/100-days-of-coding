# Smallest Stable Index

## Example

**Input:**

`nums = [5, 0, 1, 4]`
`k = 3`

**Output:**

`1`

**Explanation:**

We need to find the first index `i` such that the difference between the **maximum and minimum elements from index `i` to the end** is at most `k`.

For index `1`, the subarray is:

`[0, 1, 4]`

Maximum = `4`
Minimum = `0`

`4 - 0 = 4`

Since `4 > 3`, index `1` is not stable.

For index `2`:

`[1, 4]`

Maximum = `4`
Minimum = `1`

`4 - 1 = 3`

Since `3 <= k`, index `2` is stable.

So the answer is **2**.

> **Note:** With the given code and input, the output is actually `2`, not `1`.

## Concept

**Maximum and Minimum + Nested Loop**

For each index, we consider the elements from that index to the end.
We find the maximum and minimum values and check whether their difference is at most `k`.

## Approach

1. Initialize `l` as `INT_MIN` to keep track of the maximum value seen so far.
2. Traverse the array using index `i`.
3. Update `l` using:
   `l = max(l, nums[i])`
4. For every `i`, create a new minimum value `s = INT_MAX`.
5. Start another loop from `i` to the end of the array.
6. Find the minimum element from index `i` to the end and store it in `s`.
7. Check:
   `l - s <= k`
8. If the condition is true, return the current index `i`.
9. If no index satisfies the condition, return `-1`.

## Dry Run

**Input:**

`nums = [5, 0, 1, 4]`
`k = 3`

### Index `0`

Elements from index `0`:

`[5, 0, 1, 4]`

Maximum `l = 5`
Minimum `s = 0`

`5 - 0 = 5`

`5 > 3` → Not stable.

### Index `1`

`l = max(5, 0) = 5`

Elements from index `1`:

`[0, 1, 4]`

Minimum `s = 0`

`5 - 0 = 5`

`5 > 3` → Not stable.

### Index `2`

`l = max(5, 1) = 5`

Elements from index `2`:

`[1, 4]`

Minimum `s = 1`

`5 - 1 = 4`

`4 > 3` → Not stable.

### Index `3`

`l = max(5, 4) = 5`

Elements from index `3`:

`[4]`

Minimum `s = 4`

`5 - 4 = 1`

`1 <= 3` → Stable.

Therefore, the function returns:

`3`

## Complexity

* Time Complexity: **O(n²)** — For every index, we scan the remaining elements to find the minimum.
* Space Complexity: **O(1)** — Only a few variables are used.
