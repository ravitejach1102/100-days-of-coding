# Check Divisibility by Digit Sum and Product

## 1. Problem Statement

Given a positive integer `n`, find:

* The **sum of its digits**
* The **product of its digits**

Add these two values together and check whether `n` is divisible by this result.

Return `true` if it is divisible; otherwise, return `false`.

Example:

`n = 99`

Digit sum:

`9 + 9 = 18`

Digit product:

`9 × 9 = 81`

Total:

`18 + 81 = 99`

Since:

`99 % 99 = 0`

Answer: `true`

## 2. Concept

* Use `% 10` to get the last digit.
* Use `/ 10` to remove the last digit.
* Calculate digit sum and digit product together.
* Check divisibility using the `%` operator.

## 3. Logic

1. Store the original number in `copy`.
2. Start `sum = 0` and `prod = 1`.
3. Extract each digit using `n % 10`.
4. Add the digit to `sum`.
5. Multiply the digit with `prod`.
6. Remove the last digit using `n / 10`.
7. Calculate `total = sum + prod`.
8. Check whether `copy % total == 0`.

**Important:** Your code currently uses:

```cpp
if(copy == tot)
```

That checks whether the number is **equal** to the total.

For the stated problem, it should be:

```cpp
if(copy % tot == 0)
```

because we need to check **divisibility**.

## 4. Approach

1. Save the original number.
2. Find the sum of all digits.
3. Find the product of all digits.
4. Add sum and product.
5. Use `%` to check whether the original number is divisible by the total.
6. Return `true` or `false`.

## 5. Dry Run

Example:

`n = 99`

### Step 1: Find digits

First digit:

`99 % 10 = 9`

```text
sum = 0 + 9 = 9
prod = 1 × 9 = 9
```

Remove digit:

`99 / 10 = 9`

Second digit:

`9 % 10 = 9`

```text
sum = 9 + 9 = 18
prod = 9 × 9 = 81
```

Remove digit:

`9 / 10 = 0`

### Step 2: Calculate Total

```text
total = sum + prod
      = 18 + 81
      = 99
```

### Step 3: Check Divisibility

```text
99 % 99 = 0
```

Remainder is `0`, so:

```text
Answer = true
```

## 7. Time Complexity

**O(log n)** — We process each digit of the number once.

## 8. Space Complexity

**O(1)** — Only a few integer variables are used.

# Distinct Prime Factors

## 1. Problem Statement

Given an array of positive integers, find the total number of **distinct prime factors** present in all the numbers.

A prime factor should be counted only once, even if it appears multiple times.

Example:

`nums = [2, 4, 3, 7, 10, 6]`

Prime factors are:

* `2` → `2`
* `4` → `2`
* `3` → `3`
* `7` → `7`
* `10` → `2, 5`
* `6` → `2, 3`

Distinct prime factors:

`{2, 3, 5, 7}`

Answer:

`4`

## 2. Concept

* **Prime Factorization:** Break each number into its prime factors.
* **Set STL:** A `set` stores only **unique values**, so duplicate prime factors are automatically ignored.
* For each factor, divide it completely using a `while` loop.
* If a prime factor remains after the loop, insert it into the set.

### `set` STL

A `set` is an STL container that stores **unique elements** in sorted order.

For example:

```cpp
set<int> factors;

factors.insert(2);
factors.insert(3);
factors.insert(2);
factors.insert(5);
```

The set contains:

```text
{2, 3, 5}
```

The second `2` is not stored again.

So in this problem, `set` is useful because we need **distinct** prime factors.

## 3. Logic

1. Create a set called `factors`.
2. Take each number from the array.
3. Try dividing it by numbers starting from `2`.
4. If `j` divides the number, insert `j` into the set.
5. Keep dividing by `j` until it is no longer a factor.
6. If a number greater than `1` remains, insert it into the set.
7. Return `factors.size()`.

## 4. Approach

1. Create `set<int> factors`.
2. Traverse every number in `nums`.
3. Start checking factors from `2`.
4. If `n % j == 0`, insert `j` into the set.
5. Divide `n` by `j` repeatedly.
6. After the loop, insert `n` if `n > 1`.
7. Return the size of the set.

## 5. Dry Run

Example:

`nums = [2, 4, 3, 7, 10, 6]`

### Process `2`

`2` is prime.

Set:

`{2}`

### Process `4`

`4 = 2 × 2`

`2` is already in the set.

Set:

`{2}`

### Process `3`

`3` is prime.

Set:

`{2, 3}`

### Process `7`

`7` is prime.

Set:

`{2, 3, 7}`

### Process `10`

`10 = 2 × 5`

Insert `2` and `5`.

Set:

`{2, 3, 5, 7}`

### Process `6`

`6 = 2 × 3`

Both are already present.

Final set:

`{2, 3, 5, 7}`

Therefore:

`factors.size() = 4`

**Answer: `4`**

## 7. Time Complexity

**O(n × √m × log p)** — For each of the `n` numbers, we check factors up to `√m`; inserting into the set takes `O(log p)`.

## 8. Space Complexity

**O(p)** — The set stores the distinct prime factors, where `p` is the number of distinct prime factors.


# Maximum Product of Two Elements in an Array

## 1. Problem Statement

Given an array, choose two different elements and return the maximum value of:

`(nums[i] - 1) * (nums[j] - 1)`

To get the maximum product, we need the two largest elements.

Example:

`nums = [3, 4, 5, 2]`

Two largest elements are `5` and `4`.

Result:

`(5 - 1) * (4 - 1) = 12`

## 2. Concept

* Find the **largest** and **second largest** elements.
* Use two variables: `mx` and `smx`.
* Update them while traversing the array.
* Calculate the final product using the two largest values.

## 3. Logic

1. Start `mx` and `smx` with `INT_MIN`.
2. Traverse every element.
3. If the current element is greater than `mx`, move `mx` to `smx`.
4. Make the current element the new `mx`.
5. Otherwise, if it is greater than `smx`, update `smx`.
6. Calculate `(mx - 1) * (smx - 1)`.

## 4. Approach

1. Initialize `mx` and `smx` to `INT_MIN`.
2. Traverse the array once.
3. Find the largest element in `mx`.
4. Find the second largest element in `smx`.
5. Subtract `1` from both values.
6. Multiply them and return the result.

## 5. Dry Run

Example:

`nums = [3, 4, 5, 2]`

| Element | `mx` |   `smx` |
| ------- | ---: | ------: |
| 3       |    3 | INT_MIN |
| 4       |    4 |       3 |
| 5       |    5 |       4 |
| 2       |    5 |       4 |

So:

`mx = 5`
`smx = 4`

Calculate:

```text
(mx - 1) * (smx - 1)

= (5 - 1) * (4 - 1)

= 4 * 3

= 12
```

**Answer: `12`**

## 7. Time Complexity

**O(n)** — The array is traversed only once.

## 8. Space Complexity

**O(1)** — Only two variables are used to store the largest values.


# Find All Numbers Disappeared in an Array

## 1. Problem Statement

Given an array of `n` integers, where each number is between `1` and `n`, find all numbers from `1` to `n` that do not appear in the array.

Example:

`nums = [4, 3, 2, 7, 8, 2, 3, 1]`

Numbers from `1` to `8` are:

`1 2 3 4 5 6 7 8`

Numbers `5` and `6` are missing.

Answer:

`[5, 6]`

## 2. Concept

* Use a **set** to store all numbers that appear in the array.
* A `set` stores only unique values.
* Use `find()` to check whether a number exists in the set.
* If `find()` returns `s.end()`, the number is not present.

## 3. Logic

1. Create an empty set `s`.
2. Insert every array element into the set.
3. Check every number from `1` to `n`.
4. Use `s.find(i)` to check if the number exists.
5. If `s.find(i) == s.end()`, the number is missing.
6. Add the missing number to `result`.

### What does `find()` do?

```cpp
s.find(i)
```

searches for `i` inside the set.

If `i` exists:

```cpp
s.find(i) != s.end()
```

If `i` does not exist:

```cpp
s.find(i) == s.end()
```

## 4. Approach

1. Create a `set<int>`.
2. Insert all elements of `nums` into the set.
3. Loop from `1` to `n`.
4. Search each number using `find()`.
5. If it is not found, add it to `result`.
6. Return the result.

## 5. Dry Run

Example:

`nums = [4, 3, 2, 7, 8, 2, 3, 1]`

### Step 1: Insert into Set

After inserting all elements:

`set = {1, 2, 3, 4, 7, 8}`

Duplicates like `2` and `3` are stored only once.

### Step 2: Check `1` to `8`

| Number | Found in Set? | Result  |
| ------ | ------------- | ------- |
| 1      | Yes           | —       |
| 2      | Yes           | —       |
| 3      | Yes           | —       |
| 4      | Yes           | —       |
| 5      | No            | Add `5` |
| 6      | No            | Add `6` |
| 7      | Yes           | —       |
| 8      | Yes           | —       |

Final result:

`[5, 6]`

## 7. Time Complexity

**O(n log n)** — Inserting and searching in a `set` takes `O(log n)`.

## 8. Space Complexity

**O(n)** — The set can store up to `n` unique numbers.


# Missing Number

## 1. Problem Statement

Given an array containing `n` different numbers from `0` to `n`, find the one number that is missing.

Example:

`nums = [0, 1]`

Numbers should be:

`0, 1, 2`

The missing number is:

`2`

## 2. Concept

* The numbers from `0` to `n` have a known sum.
* We calculate the **expected sum** using a formula.
* We calculate the **actual sum** of the array.
* The difference between them is the missing number.

## 3. Logic

The sum of numbers from `0` to `n` is:

```cpp
n * (n + 1) / 2
```

For example, if `n = 3`:

```text
0 + 1 + 2 + 3 = 6
```

Using the formula:

```text
3 × 4 / 2 = 6
```

Then:

```text
Missing Number = Expected Sum - Actual Sum
```

## 4. Approach

1. Find `n` using `nums.size()`.
2. Calculate the expected sum from `0` to `n`.
3. Calculate the actual sum of all array elements.
4. Subtract actual sum from expected sum.
5. Return the difference.

## 5. Dry Run

Example:

`nums = [0, 1]`

### Step 1: Find `n`

```text
n = nums.size()
n = 2
```

### Step 2: Calculate Expected Sum

```text
expected = n × (n + 1) / 2
         = 2 × 3 / 2
         = 3
```

Numbers should be:

`0 + 1 + 2 = 3`

### Step 3: Calculate Actual Sum

```text
actual = 0 + 1
       = 1
```

### Step 4: Find Missing Number

```text
expected - actual
= 3 - 1
= 2
```

**Answer: `2`**

## 7. Time Complexity

**O(n)** — The array is traversed once to calculate the actual sum.

## 8. Space Complexity

**O(1)** — Only a few integer variables are used.
