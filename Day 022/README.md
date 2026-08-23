# Max Number of K-Sum Pairs

## 1. Problem Statement

Given an array and an integer `k`, find the maximum number of pairs whose sum is equal to `k`.

Each element can be used only once.

Example:

`nums = [1, 3, 2, 5, 3, 3]`
`k = 6`

Possible pairs:

`1 + 5 = 6`
`3 + 3 = 6`

So the answer is:

`2`

## 2. Concept

* Use a **map** to store the frequency of numbers.
* For every number, find the value needed to make the sum `k`.
* The required value is `k - nums[i]`.
* If the required value is available, make a pair and decrease its frequency.

## 3. Logic

Suppose the current number is `3` and:

`k = 6`

We need:

`6 - 3 = 3`

So we check whether `3` is already available in the map.

If it is available:

```cpp
m[ans] > 0
```

we found a pair.

Then:

```cpp
count++;
m[ans]--;
```

The frequency is decreased because that number has been used.

If the required number is not available, store the current number:

```cpp
m[nums[i]]++;
```

## 4. Approach

1. Create a map `m` to store frequencies.
2. Traverse the array.
3. Calculate `ans = k - nums[i]`.
4. Check if `ans` is available in the map.
5. If available, increase `count` and decrease its frequency.
6. Otherwise, store the current number in the map.
7. Return `count`.

## 5. Dry Run

Example:

`nums = [1, 3, 2, 5, 3, 3]`
`k = 6`

| Current | Needed (`6 - current`) | Map before        | Action                  |
| ------- | ---------------------: | ----------------- | ----------------------- |
| 1       |                      5 | `{}`              | Store `1`               |
| 3       |                      3 | `{1:1}`           | Store `3`               |
| 2       |                      4 | `{1:1, 3:1}`      | Store `2`               |
| 5       |                      1 | `{1:1, 3:1, 2:1}` | Pair `5 + 1`, count = 1 |
| 3       |                      3 | `{1:0, 3:1, 2:1}` | Pair `3 + 3`, count = 2 |
| 3       |                      3 | `{1:0, 3:0, 2:1}` | No `3` available        |

Final answer:

`2`

Pairs used:

```text
1 + 5 = 6
3 + 3 = 6
```

## 7. Time Complexity

**O(n log n)** — Each map insertion, lookup, and deletion takes `O(log n)`.

## 8. Space Complexity

**O(n)** — The map can store frequencies for up to `n` elements.


# Rotate Array to the Right by K Steps

## 1. Problem Statement

Given an array, rotate it to the **right** by `k` positions.

Example:

`nums = [1, 2, 3, 4, 5]`
`k = 2`

After rotating:

`[4, 5, 1, 2, 3]`

## 2. Concept

* Right rotation moves the last `k` elements to the front.
* The remaining elements move to the right.
* `k = k % n` handles cases where `k` is greater than the array size.
* A temporary vector is used to store the rotated elements.

## 3. Logic

For:

`[1, 2, 3, 4, 5]`

and:

`k = 2`

The last `2` elements are:

`[4, 5]`

The remaining elements are:

`[1, 2, 3]`

Put them together:

`[4, 5, 1, 2, 3]`

The important part of the code is:

```cpp
for(int i = n-k; i < n; i++)
```

This starts from `n-k` to collect the last `k` elements.

Then:

```cpp
for(int i = 0; i < n-k; i++)
```

collects the remaining elements.

Finally:

```cpp
nums = temp;
```

copies the temporary vector into `nums`.

## 4. Approach

1. Find the size of the array `n`.
2. Calculate `k = k % n`.
3. Create an empty temporary vector.
4. Add the last `k` elements to `temp`.
5. Add the remaining elements to `temp`.
6. Assign `temp` back to `nums`.

## 5. Dry Run

Example:

```text
nums = [1, 2, 3, 4, 5]
k = 2
```

### Step 1: Calculate `n` and `k`

```text
n = 5
k = 2 % 5 = 2
```

### Step 2: Take Last `k` Elements

Start:

```text
n - k = 5 - 2 = 3
```

Start from index `3`:

```text
index:  0  1  2  3  4
value:  1  2  3  4  5
                  ↑  ↑
```

Add:

`4, 5`

So:

`temp = [4, 5]`

### Step 3: Add Remaining Elements

Add:

`1, 2, 3`

Now:

`temp = [4, 5, 1, 2, 3]`

### Step 4: Update Original Array

```cpp
nums = temp;
```

Final:

`[4, 5, 1, 2, 3]`

## 7. Time Complexity

**O(n)** — Every element is copied into the temporary vector once.

## 8. Space Complexity

**O(n)** — The temporary vector stores all `n` elements.
