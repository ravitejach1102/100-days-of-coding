# Minimum Size Subarray Sum

## Example

**Input:**

```text
target = 7
nums = [2, 3, 1, 2, 4, 3]
```

**Output:**

```text
2
```

**Explanation:**
The subarrays whose sum is at least `7` include `[2,3,1,2]`, `[3,1,2,4]`, `[4,3]`, etc.

The shortest one is `[4,3]`, whose sum is `7`.

So, the minimum length is **2**.

## Concept

**Sliding Window**

We use two pointers to maintain a continuous subarray.
When the sum becomes at least the target, we shrink the window from the left to find a smaller valid subarray.

## Approach

1. Set `si = 0` to represent the starting index of the window.
2. Use `sum` to store the sum of the current window.
3. Traverse the array using `i`.
4. Add `nums[i]` to `sum`.
5. Whenever `sum >= target`, we have found a valid subarray.
6. Calculate its length using:
   `i - si + 1`
7. Update `ans` with the smaller length.
8. Remove `nums[si]` from the sum and move `si` forward.
9. Continue shrinking while `sum >= target`.
10. If no valid subarray was found, return `0`.

## Dry Run

**Input:**

`target = 7`
`nums = [2, 3, 1, 2, 4, 3]`

### Start

`si = 0`
`sum = 0`
`ans = 7`

### Add 2

`sum = 2`

`sum < 7`, so continue.

Window: `[2]`

### Add 3

`sum = 5`

`sum < 7`, so continue.

Window: `[2,3]`

### Add 1

`sum = 6`

`sum < 7`, so continue.

Window: `[2,3,1]`

### Add 2

`sum = 8`

Now `sum >= 7`.

Window: `[2,3,1,2]`
Length = `4`

`ans = 4`

Remove `2` from the left:

`sum = 6`
`si = 1`

### Add 4

`sum = 10`

Window: `[3,1,2,4]`
Length = `4`

Remove `3`:

`sum = 7`
`si = 2`

Window: `[1,2,4]`
Length = `3`

Remove `1`:

`sum = 6`
`si = 3`

### Add 3

`sum = 9`

Window: `[2,4,3]`
Length = `3`

Remove `2`:

`sum = 7`
`si = 4`

Window: `[4,3]`
Length = `2`

`ans = 2`

Remove `4`:

`sum = 3`
`si = 5`

The minimum length found is **2**.

## Complexity

* Time Complexity: **O(n)** — Each element is added to and removed from the window at most once.
* Space Complexity: **O(1)** — Only a few variables are used.
