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
