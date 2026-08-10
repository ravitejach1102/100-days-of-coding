# LeetCode 78 – Subsets

## Problem

Given an array of integers, return all possible subsets of the array.

For example, for `[1, 2, 3]`, there are 8 possible subsets.

```text
[]
[1]
[2]
[3]
[1,2]
[1,3]
[2,3]
[1,2,3]
```

## Approach

I used **recursion and backtracking**.

For every element, there are two choices:

* Include the element
* Exclude the element

The recursion explores both choices until all elements are processed.

After including an element, `pop_back()` removes it before exploring the exclude choice. This is the **backtracking** step.

## Recursion Tree

The complete recursion tree for `[1, 2, 3]`:

![Subsets Recursion Tree](subset.png)

## Simple Logic

```text
Include → Go deeper → Backtrack → Exclude → Go deeper
```

When `i == nums.size()`, the current subset is added to `allsubsets`.

## Example

**Input:**

```text
[1, 2, 3]
```

**Output:**

```text
[1,2,3]
[1,2]
[1,3]
[1]
[2,3]
[2]
[3]
[]
```

## Complexity

**Time Complexity:** `O(2^n)`

Each element has 2 choices: include or exclude.

**Space Complexity:** `O(n)`

This is for the recursion stack and the current subset. The output space is not counted.

# Subsets II – Backtracking

## Problem

Given an integer array `nums` that may contain duplicate values, return **all possible subsets**.

The result should **not contain duplicate subsets**.

### Example

Input:

```text
nums = [1, 2, 2]
```

Output:

```text
[ ]
[ 1 ]
[ 1 2 ]
[ 1 2 2 ]
[ 2 ]
[ 2 2 ]
```

---

## Approach

We use **recursion + backtracking**.

For every element, we have two choices:

1. **Include** the element.
2. **Exclude** the element.

Because the array can contain duplicates, we first **sort the array**.

```cpp
sort(nums.begin(), nums.end());
```

After choosing **not to include** an element, we skip all duplicate values.

For example:

```text
[1, 2, 2]
    ↑  ↑
    same values
```

When we are at the first `2` and decide to exclude it, we skip the next `2`.

This prevents generating the same subset more than once.

---

## Recursion Tree

For:

```text
[1, 2, 2]
```

The idea is:

```text
                    []
                  /    \
               include  exclude
                 1        1
                /          \
              [1]           []
             /   \           \
            2     skip 2       2
           / \                  \
        [1,2] [1,2,2]          [2]
                               /   \
                            [2,2]   ...
```

The important part is:

```text
Include → choose the current element

Exclude → skip duplicate elements
```

---

## How Backtracking Works

Suppose:

```text
ans = [1, 2]
```

We go deeper and make more choices.

After returning from recursion:

```cpp
ans.pop_back();
```

removes the last element.

So we can try another choice.

For example:

```text
ans = [1]
      ↓
add 2
      ↓
ans = [1, 2]
      ↓
backtrack
      ↓
ans = [1]
```

This allows the same vector to be reused for different subsets.

---

## Duplicate Handling

First, sort the array:

```text
[1, 2, 2]
```

Now duplicate values are next to each other.

When excluding an element:

```cpp
int idx = i + 1;

while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
    idx++;
}
```

This skips duplicate values.

For example:

```text
i
↓
[1, 2, 2]
    ↑  ↑
    2  2
```

Instead of choosing the second `2` separately, we skip it.

This prevents duplicate subsets.

---

## Base Case

When we reach the end of the array:

```cpp
if (i == nums.size()) {
    allsubsets.push_back(ans);
    return;
}
```

It means we have made choices for all elements.

So we store the current subset.

---

## Algorithm

1. Sort the array.
2. Start recursion from index `0`.
3. Include the current element.
4. Recursively continue.
5. Remove the element using `pop_back()` (**backtracking**).
6. Skip duplicate elements.
7. Recursively explore the exclude choice.
8. When all elements are processed, store the subset.

---

## Time Complexity

There can be up to `2^n` subsets.

So the time complexity is approximately:

```text
O(2^n × n)
```

`n` is the number of elements.

Sorting takes:

```text
O(n log n)
```

---

## Space Complexity

The recursion uses:

```text
O(n)
```

space for the recursion stack.

The output itself can contain up to:

```text
O(2^n)
```

subsets.


# Permutations – Backtracking

## Problem

Given an array of numbers, generate **all possible arrangements (permutations)** of those numbers.

### Example

Input:

```text
[1, 2, 3]
```

Output:

```text
[1 2 3]
[1 3 2]
[2 1 3]
[2 3 1]
[3 2 1]
[3 1 2]
```

For `3` different numbers, there are:

```text
3! = 3 × 2 × 1 = 6
```

possible permutations.

---

## Approach

We use **recursion + backtracking**.

At every position, we try each available element.

For:

```text
[1, 2, 3]
```

At index `0`, we try:

```text
1
2
3
```

Then we recursively fill the next position.

---

## Recursion Tree

For `[1, 2, 3]`:

```text
                         [1 2 3]
                    /       |       \
                   1        2        3
                 /   \    /   \    /   \
                2     3  1     3  1     2
                |     |  |     |  |     |
              123   132 213   231 312   321
```

Each path from the top to the bottom gives one permutation.

---

## How the Code Works

### 1. Start from index `0`

```cpp
getPermutations(nums, 0, ans);
```

`idx` tells us which position we are currently filling.

---

### 2. Try every element

```cpp
for (int i = idx; i < nums.size(); i++)
```

We try placing every remaining element at position `idx`.

---

### 3. Swap

```cpp
swap(nums[idx], nums[i]);
```

The selected element is moved to the current position.

Example:

```text
[1, 2, 3]

swap index 0 and index 1

[2, 1, 3]
```

Now `2` is fixed at position `0`.

---

### 4. Recursion

```cpp
getPermutations(nums, idx + 1, ans);
```

Move to the next position and repeat the same process.

---

### 5. Backtracking

After recursion finishes:

```cpp
swap(nums[idx], nums[i]);
```

We swap the elements back.

This **undoes the previous choice** so that we can try another possibility.

For example:

```text
Choose:
[2, 1, 3]

Backtrack:
[1, 2, 3]

Try another choice...
```

This is why it is called **backtracking**.

---

## Base Case

```cpp
if (idx == nums.size()) {
    ans.push_back(nums);
    return;
}
```

When `idx` reaches the size of the array, all positions have been filled.

So we have found one complete permutation.

Example:

```text
[1, 2, 3]
```

is added to the answer.

---

## Important Idea

The main pattern is:

```text
Choose
  ↓
Swap
  ↓
Recursion
  ↓
Undo the swap
  ↓
Try the next choice
```

This is the basic pattern of **backtracking**.

---

## Example Walkthrough

For:

```text
[1, 2, 3]
```

First position:

```text
1
```

Then remaining positions produce:

```text
[1, 2, 3]
[1, 3, 2]
```

Backtrack and choose:

```text
2
```

Now:

```text
[2, 1, 3]
[2, 3, 1]
```

Backtrack and choose:

```text
3
```

Now:

```text
[3, 1, 2]
[3, 2, 1]
```

Therefore, all `6` permutations are generated.

---

## Time Complexity

For `n` elements, there are:

```text
n!
```

permutations.

Each permutation takes `O(n)` time to store.

Therefore:

```text
O(n × n!)
```

---

## Space Complexity

The recursion depth is `n`.

So the recursion stack uses:

```text
O(n)
```

The output contains all permutations, which requires:

```text
O(n × n!)
```

space.



