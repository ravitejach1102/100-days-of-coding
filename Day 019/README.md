# Two Sum

## 1. Problem Statement

Given an array and a target value, find two elements whose sum is equal to the target.

Return the **indices** of those two elements.

Example:

`nums = [2, 7, 11, 15]`
`target = 9`

`2 + 7 = 9`

Answer:

`[0, 1]`

## 2. Concept

* Use two loops to check pairs of elements.
* The first loop selects the first element.
* The second loop selects the next elements.
* If their sum equals the target, return their indices.

## 3. Logic

1. Start from the first element using `i`.
2. Start `j` from `i + 1` so the same element is not used twice.
3. Add `arr[i]` and `arr[j]`.
4. If the sum equals `target`, return `{i, j}`.
5. Continue checking all pairs if the sum does not match.
6. Return an empty vector if no pair is found.

## 4. Approach

1. Traverse the array using the first loop.
2. For every element, check all elements after it.
3. Compare their sum with `target`.
4. Return the indices when a matching pair is found.
5. Return an empty result if no pair exists.

## 5. Dry Run

Example:

`nums = [2, 7, 11, 15]`
`target = 9`

| `i` | `j` | Calculation | Result |
| --- | --- | ----------- | ------ |
| 0   | 1   | `2 + 7 = 9` | Found  |

The pair is:

`2 + 7 = 9`

Their indices are:

`0 1`

Final answer:

`[0, 1]`

## 7. Time Complexity

**O(n²)** — Two nested loops check the possible pairs.

## 8. Space Complexity

**O(1)** — Only a few variables are used apart from the returned result.

# Distribute Elements Into Two Arrays

## 1. Problem Statement

Given an array, divide its elements into two arrays based on the last element of each array.

* Put the first element in `arr1`.
* Put the second element in `arr2`.
* For every next element, compare the last elements of both arrays.
* Put the current element into the array whose last element is smaller.

Finally, append `arr2` to `arr1`.

Example:

`nums = [2, 1, 3]`

Result:

`[2, 3, 1]`

## 2. Concept

* Use two separate arrays: `arr1` and `arr2`.
* Compare the last elements using `.back()`.
* Add the current element to the array with the smaller last value.
* Finally, combine both arrays.

## 3. Logic

1. Put `nums[0]` into `arr1`.
2. Put `nums[1]` into `arr2`.
3. Start checking from `nums[2]`.
4. Compare `arr1.back()` and `arr2.back()`.
5. If `arr1.back()` is greater, add the element to `arr1`.
6. Otherwise, add it to `arr2`.
7. Append all elements of `arr2` to `arr1`.
8. Return `arr1`.

## 4. Approach

1. Create two empty arrays.
2. Add the first two elements to `arr1` and `arr2`.
3. Traverse the remaining elements.
4. Compare the last elements of both arrays.
5. Insert the current element into the appropriate array.
6. Append `arr2` to `arr1`.
7. Return the final array.

## 5. Dry Run

Example:

`nums = [2, 1, 3]`

### Step 1

First two elements:

`arr1 = [2]`
`arr2 = [1]`

### Step 2

Current element = `3`

Compare:

`arr1.back() = 2`
`arr2.back() = 1`

Since:

`2 > 1`

Add `3` to `arr1`.

Now:

`arr1 = [2, 3]`
`arr2 = [1]`

### Step 3

Append `arr2` to `arr1`:

`[2, 3] + [1]`

Final result:

`[2, 3, 1]`

## 7. Time Complexity

**O(n)** — Each element is processed once.

## 8. Space Complexity

**O(n)** — Two arrays are used to store the elements.

