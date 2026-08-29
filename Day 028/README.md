# Median of Two Sorted Arrays

## Example

**Input:**
`nums1 = [1, 2]`
`nums2 = [3, 4]`

**Output:**
`2.5`

**Explanation:**
First, combine both arrays:

`[1, 2] + [3, 4] = [1, 2, 3, 4]`

The combined array has 4 elements, so the median is the average of the two middle elements.

Middle elements are `2` and `3`.

`Median = (2 + 3) / 2 = 2.5`

## Concept

**Array + Sorting**

We combine the elements of both arrays into one array and sort it. Then we find the middle element or the average of the two middle elements.

## Approach

1. Create an empty vector `arr` to store elements from both arrays.
2. Traverse `nums1` and add each element to `arr`.
3. Traverse `nums2` and add each element to `arr`.
4. Sort `arr` so that all elements are in increasing order.
5. Find the total number of elements using `arr.size()`.
6. If the size is **odd**, the middle element is the median.
7. If the size is **even**, there are two middle elements. Add them and divide by `2.0`.
8. Return the calculated median.

## Dry Run

**Input:**

`nums1 = [1, 2]`
`nums2 = [3, 4]`

### Step 1: Combine the arrays

Start with an empty array:

`arr = []`

Add elements from `nums1`:

`arr = [1, 2]`

Add elements from `nums2`:

`arr = [1, 2, 3, 4]`

### Step 2: Sort the array

After sorting:

`arr = [1, 2, 3, 4]`

### Step 3: Find the size

`n = 4`

Since `4 % 2 == 0`, the number of elements is even.

### Step 4: Find the two middle elements

For `[1, 2, 3, 4]`:

* First middle element = `arr[n/2 - 1]` = `arr[1]` = `2`
* Second middle element = `arr[n/2]` = `arr[2]` = `3`

### Step 5: Calculate median

`(2 + 3) / 2.0 = 2.5`

So, the answer is **2.5**.

## Complexity

* Time Complexity: O((m + n) log(m + n)) — Combining takes O(m+n), and sorting the combined array takes O((m+n) log(m+n)).
* Space Complexity: O(m + n) — A new array is created to store all elements from both arrays.
