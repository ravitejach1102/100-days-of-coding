# Contains Duplicate

## Example

**Input:**

```text
nums = [1, 2, 3, 1]
```

**Output:**

```text
True
```

**Explanation:**
The number `1` appears twice in the array, so the array contains a duplicate.

## Concept

**Set**

A `set` stores only unique elements. We check whether an element is already present before inserting it.

## Approach

1. Create an empty `set` called `s`.
2. Traverse the array one element at a time.
3. For each element, use `s.find(nums[i])` to check if it is already present in the set.
4. If the element is found, it means the element appeared before, so return `true`.
5. If the element is not found, insert it into the set.
6. Continue until all elements are checked.
7. If no duplicate is found, return `false`.

## Dry Run

**Input:**

`nums = [1, 2, 3, 1]`

### Step 1

Current element = `1`

`1` is not in the set.

Insert `1`.

`set = {1}`

### Step 2

Current element = `2`

`2` is not in the set.

Insert `2`.

`set = {1, 2}`

### Step 3

Current element = `3`

`3` is not in the set.

Insert `3`.

`set = {1, 2, 3}`

### Step 4

Current element = `1`

`1` is already in the set.

So, a duplicate is found.

Return `true`.

**Output:** `True`

## Complexity

* Time Complexity: **O(n log n)** — Each `set` search and insertion takes O(log n).
* Space Complexity: **O(n)** — The set can store up to `n` elements.
