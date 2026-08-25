# Missing Multiple

## 1. Problem Statement

Given an array `nums` and a number `k`, find the **smallest positive multiple of `k`** that is not present in the array.

For example, if `k = 2` and `2, 4, 6, 8` are present, the answer is `10`.

## 2. Concept

* Use a **set** to store the elements of the array.
* A set allows us to quickly check whether an element exists.
* Generate multiples of `k` one by one.
* Return the first multiple that is missing.

## 3. Logic

1. Store all elements of `nums` in a set.
2. Start with `i = 1`.
3. Calculate the multiple using `k * i`.
4. Check if `k * i` exists in the set.
5. If it does not exist, return it.
6. Otherwise, increase `i` and check the next multiple.

## 4. Approach

1. Create an empty set `s`.
2. Insert every element of `nums` into the set.
3. Initialize `i = 1`.
4. Use a `while` loop to check multiples.
5. If `k * i` is not found, return `k * i`.
6. Otherwise, increment `i`.

## 5. Dry Run

Example:

```text
nums = {8, 2, 3, 4, 6}
k = 2
```

Set contains:

```text
{2, 3, 4, 6, 8}
```

Now check the multiples of `2`:

| `i` | `k * i` | Present? | Action      |
| --: | ------: | :------: | ----------- |
|   1 |     `2` |    Yes   | Continue    |
|   2 |     `4` |    Yes   | Continue    |
|   3 |     `6` |    Yes   | Continue    |
|   4 |     `8` |    Yes   | Continue    |
|   5 |    `10` |    No    | Return `10` |

So the answer is:

```text
10
```

## 7. Time Complexity

**O(n log n)** — Inserting `n` elements into a `set` takes `O(n log n)` time.

## 8. Space Complexity

**O(n)** — The set can store up to `n` elements.
