# Subarray Sum Equals K

## 1. Problem Statement

Given an array and an integer `k`, find how many continuous subarrays have a sum equal to `k`.

Example:

`nums = [1, 2, 3]`
`k = 3`

Subarrays with sum `3`:

* `[1, 2]`
* `[3]`

Answer: `2`

## 2. Concept

* A **subarray** is a continuous part of an array.
* Use two loops to consider every possible starting and ending position.
* Keep a running sum instead of calculating the sum again.
* Increase the count whenever the running sum becomes `k`.

## 3. Logic

1. Start from each index.
2. Set `currSum = 0`.
3. Move from the starting index to the end of the array.
4. Add each element to `currSum`.
5. If `currSum == k`, increase the count.
6. Return the total count.

## 4. Approach

1. Start the outer loop from index `0`.
2. Reset `currSum` to `0`.
3. Use the inner loop to extend the subarray.
4. Add the current element to `currSum`.
5. Check if `currSum` equals `k`.
6. Increase `countsum` if it matches.
7. Return `countsum`.

## 5. Dry Run

Example:

`nums = [1, 2, 3]`
`k = 3`

### Start = 0

* `[1]` → sum = `1`
* `[1, 2]` → sum = `3` → **count = 1**
* `[1, 2, 3]` → sum = `6`

### Start = 1

* `[2]` → sum = `2`
* `[2, 3]` → sum = `5`

### Start = 2

* `[3]` → sum = `3` → **count = 2**

Final answer:

`2`

## 7. Time Complexity

**O(n²)** — Two nested loops check all possible subarrays.

## 8. Space Complexity

**O(1)** — Only a few variables are used apart from the input array.
