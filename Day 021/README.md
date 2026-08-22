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
