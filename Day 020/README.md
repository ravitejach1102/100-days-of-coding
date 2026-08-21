# Count Primes 

## 1. Problem Statement

Given an integer `n`, count how many prime numbers are smaller than `n`.

Example:

`n = 10`

Prime numbers smaller than `10` are:

`2, 3, 5, 7`

Answer:

`4`

## 2. Concept

* We use the **Sieve of Eratosthenes**.
* For every prime number `i`, we mark its multiples as not prime.
* We start marking from `i * i` because smaller multiples were already handled by smaller prime numbers.
* We use `2 * i` to skip even multiples because we already removed all even numbers.

## 3. Logic

The important line is:

```cpp
for (int j = i * i; j < n; j += 2 * i)
```

It has **three parts**:

### `j = i * i`

This is where we start marking multiples.

Suppose:

`i = 3`

Then:

`i * i = 3 * 3 = 9`

So we start from:

`9`

Why not start from `3` or `6`?

Because:

* `3` itself is prime.
* `6 = 3 × 2` was already marked when we processed `2`.
* `9 = 3 × 3` is the first multiple of `3` that has not already been handled.

So we start from `9`.

### `j < n`

We only mark numbers smaller than `n`.

For:

`n = 20`

we can mark:

`9, 15`

but stop before reaching `20`.

### `j += 2 * i`

Normally, multiples of `i` are:

`i, 2i, 3i, 4i, 5i...`

For `i = 3`:

`3, 6, 9, 12, 15, 18...`

But `6, 12, 18` are even numbers.

We already marked all even numbers as not prime.

So we only need:

`9, 15`

The difference is:

`15 - 9 = 6`

And:

`2 * i = 2 * 3 = 6`

Therefore:

```cpp
j += 2 * i
```

moves:

`9 -> 15 -> 21 -> 27...`

It skips the even multiples.

## 4. Approach

1. Create a `isPrime` array.
2. Mark `0` and `1` as not prime.
3. Mark all even numbers as not prime.
4. Check only odd numbers.
5. For every prime `i`, start from `i * i`.
6. Mark its odd multiples using `j += 2 * i`.
7. Count the numbers still marked as prime.

## 5. Dry Run

Let's take:

`n = 20`

Suppose:

`i = 3`

### Start

```text
j = i * i
j = 3 * 3
j = 9
```

Now the loop is:

```text
j = 9
9 < 20  → mark 9

j = 9 + 6 = 15
15 < 20 → mark 15

j = 15 + 6 = 21
21 < 20 → false → stop
```

So we mark:

```text
9 ❌
15 ❌
```

We don't need to mark:

```text
6 ❌
12 ❌
18 ❌
```

because they are already even and were marked earlier.

### Why start from `i * i`?

For `i = 5`, the multiples are:

```text
5, 10, 15, 20, 25...
```

`10` was already handled by `2`.

`15` was already handled by `3`.

The first new multiple is:

```text
5 × 5 = 25
```

So we start from `i * i`.

### Simple Rule to Remember

```text
i * i
   ↓
Start from the first new multiple

2 * i
   ↓
Skip even multiples
```

For example, when `i = 5`:

```text
j = 25
j += 10

25 -> 35 -> 45 -> 55 -> ...
```

We skip:

```text
30, 40, 50...
```

because they are even.

## 7. Time Complexity

**O(n log log n)** — The Sieve efficiently marks the composite numbers.

## 8. Space Complexity

**O(n)** — The `isPrime` array stores information for every number from `0` to `n - 1`.

# Reverse Integer

## 1. Problem Statement

Given an integer, reverse its digits and return the reversed number.

Example:

`123`

Reversed number:

`321`

If the reversed number goes outside the range of a 32-bit integer, return `0`.

## 2. Concept

* Use `% 10` to get the last digit.
* Use `/ 10` to remove the last digit.
* Build the reversed number by multiplying it by `10` and adding the digit.
* Check for integer overflow before adding a new digit.

## 3. Logic

1. Start with `revNum = 0`.
2. Get the last digit using `n % 10`.
3. Check whether adding this digit will cause overflow.
4. Add the digit to `revNum`.
5. Remove the last digit using `n / 10`.
6. Repeat until `n` becomes `0`.
7. Return `revNum`.

The main formula is:

```cpp
revNum = revNum * 10 + dig;
```

For example, if:

`revNum = 12` and `dig = 3`

Then:

`12 × 10 + 3 = 123`

## 4. Approach

1. Store the number in `n`.
2. Initialize `revNum` to `0`.
3. Extract the last digit.
4. Check for overflow.
5. Add the digit to the reversed number.
6. Remove the last digit from `n`.
7. Continue until all digits are processed.

## 5. Dry Run

Example:

`n = 123`

### Step 1

```text
n = 123
dig = 123 % 10 = 3

revNum = 0 × 10 + 3
       = 3
```

Remove the last digit:

`n = 123 / 10 = 12`

### Step 2

```text
n = 12
dig = 12 % 10 = 2

revNum = 3 × 10 + 2
       = 32
```

`n = 12 / 10 = 1`

### Step 3

```text
n = 1
dig = 1 % 10 = 1

revNum = 32 × 10 + 1
       = 321
```

`n = 1 / 10 = 0`

Loop stops.

Final answer:

`321`

### Overflow Check

Before doing:

```cpp
revNum = revNum * 10 + dig;
```

we check:

```cpp
if(revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
```

This prevents the reversed number from going outside the range of a 32-bit integer.

## 7. Time Complexity

**O(log n)** — The loop runs once for each digit of the number.

## 8. Space Complexity

**O(1)** — Only a few integer variables are used.
