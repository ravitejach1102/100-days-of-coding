# Concatenation of Array

## Platform
LeetCode

## Difficulty
Easy

## Approach
Created a new vector and added all the elements of the original array twice using nested loops.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Concepts Learned
- Vectors
- Nested Loops
- Array Traversal

# Buy and Sell Stock - C++

## Problem

Given an array of stock prices, find the maximum profit by buying a stock on one day and selling it on a later day.

**Condition:** You must buy before you sell.

### Example

**Input**

```text
7 1 5 3 6 4
```

**Output**

```text
Maximum Profit: 5
```

**Explanation**

* Buy at price **1**
* Sell at price **6**
* Profit = **5**

---

## Profit Formula

```text
Profit = Selling Price - Buying Price
```

---

## Best Buy Array

For the input:

```text
Prices = {7, 1, 5, 3, 6, 4}
```

The `bestBuy` array stores the minimum buying price before each day.

| Day | Price | Best Buy |
| --: | ----: | -------: |
|   0 |     7 |  INT_MAX |
|   1 |     1 |        7 |
|   2 |     5 |        1 |
|   3 |     3 |        1 |
|   4 |     6 |        1 |
|   5 |     4 |        1 |

So,

```text
bestBuy = {INT_MAX, 7, 1, 1, 1, 1}
```

---

## Profit Calculation

| Day | Selling Price | Best Buy | Profit |
| --: | ------------: | -------: | -----: |
|   0 |             7 |  INT_MAX |      0 |
|   1 |             1 |        7 |     -6 |
|   2 |             5 |        1 |      4 |
|   3 |             3 |        1 |      2 |
|   4 |             6 |        1 |    5 ✅ |
|   5 |             4 |        1 |      3 |

**Maximum Profit = 5**

---

## Approach

1. Create a `bestBuy` array.
2. Store the minimum buying price before each day.
3. Calculate the profit for each day using:

```text
Profit = Selling Price - Best Buy Price
```

4. Update the maximum profit.

---

## Time Complexity

* **O(n)**

## Space Complexity

* **O(n)**

---

## Code

The program contains **both implementations in the same file**:

* Vector implementation (active)
* Array implementation (commented out)

---

## Concepts Used

* Arrays
* Vectors
* Loops
* `min()`
* `max()`
* `INT_MAX`
* Time Complexity
* Space Complexity


# Single Number - C++

## Problem

Given an array where every element appears twice except one element, find the element that appears only once.

### Example

**Input**

```text
4 1 2 1 2
```

**Output**

```text
The single number is: 4
```

---

## Approach

* Initialize `result` as `0`.
* Traverse the array.
* Perform the XOR (`^`) operation with each element.
* Duplicate numbers cancel each other out.
* The remaining value is the single number.

---

## XOR Property

```text
a ^ a = 0
a ^ 0 = a
```

Example:

```text
4 ^ 1 ^ 2 ^ 1 ^ 2
= 4 ^ (1 ^ 1) ^ (2 ^ 2)
= 4 ^ 0 ^ 0
= 4
```

---

## Time Complexity

* **O(n)**

## Space Complexity

* **O(1)**

---

## Concepts Used

* Vectors
* Loops
* Bitwise XOR (`^`)
