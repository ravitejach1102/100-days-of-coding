# Power Function Using Binary Exponentiation

## Problem

Calculate `x^n` efficiently without multiplying `x` repeatedly `n` times.

## Approach

The solution uses **Binary Exponentiation**.

Instead of calculating:

`x × x × x × ...`

we repeatedly square `x` and divide the exponent by `2`.

For example:

`2^10`

Binary representation of `10` is:

`1010`

The algorithm checks each bit of the exponent:

* If the current exponent is odd, multiply `ans` by `x`.
* Square `x`.
* Divide the exponent by `2`.
* Continue until the exponent becomes `0`.

## Handling Special Cases

* If `n == 0` → answer is `1`.
* If `x == 0` → answer is `0`.
* If `x == 1` → answer is `1`.
* If `x == -1`:

  * Even `n` → `1`
  * Odd `n` → `-1`
* If `n < 0`, convert the problem using:

`x^(-n) = 1 / x^n`

So `x` is changed to `1/x` and the exponent is made positive.

## Dry Run

Consider:

`x = 2, n = 10`

Initial:

`ans = 1`

`x = 2`

`binform = 10`

| Step | binform | Odd? |  ans | x after squaring |
| ---- | ------: | ---- | ---: | ---------------: |
| 1    |      10 | No   |    1 |                4 |
| 2    |       5 | Yes  |    4 |               16 |
| 3    |       2 | No   |    4 |              256 |
| 4    |       1 | Yes  | 1024 |            65536 |

Finally:

`ans = 1024`

Therefore:

`2^10 = 1024`

## Why Binary Exponentiation?

A normal approach takes **O(n)** time because it performs multiplication `n` times.

Binary exponentiation reduces this to **O(log n)** because the exponent is divided by `2` in every iteration.

## Complexity

**Time Complexity:** `O(log |n|)`

**Space Complexity:** `O(1)`

## Key Concept

The main idea is:

**If the exponent is even:**

`x^n = (x^(n/2))²`

**If the exponent is odd:**

`x^n = x × x^(n-1)`

Binary exponentiation uses this idea iteratively to calculate the power efficiently.
