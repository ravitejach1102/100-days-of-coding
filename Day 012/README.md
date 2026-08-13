# Add Digits

## Problem

Given an integer `num`, repeatedly add all its digits until only one digit remains.

### Example

```text
38
↓
3 + 8 = 11
↓
1 + 1 = 2
```

Answer:

```text
2
```

---

## Basic Logic

First, we need to take each digit from the number.

For this, we use:

```text
num % 10
```

This gives the **last digit**.

Example:

```text
38 % 10 = 8
```

Then we remove the last digit using:

```text
num / 10
```

Example:

```text
38 / 10 = 3
```

So:

```text
38
 ↓
38 % 10 = 8   → get digit
38 / 10 = 3   → remove digit
```

We continue this until the number becomes `0`.

---

## Adding the Digits

We use a variable called `sum`.

Initially:

```text
sum = 0
```

For `38`:

```text
digit = 8
sum = 0 + 8
sum = 8
```

Then:

```text
digit = 3
sum = 8 + 3
sum = 11
```

Now we have:

```text
sum = 11
```

But `11` has two digits.

So we need to repeat the same process:

```text
11
↓
1 + 1
↓
2
```

Now `2` has only one digit, so we stop.

---

# Why O(1) Is Possible

The basic solution uses loops.

But this problem has a mathematical property called the **Digital Root**.

The important idea is that a number and the sum of its digits have the **same remainder when divided by 9**.

For example:

```text
38 % 9 = 2
```

And its digit sum is:

```text
3 + 8 = 11
```

Again:

```text
11 % 9 = 2
```

Then:

```text
1 + 1 = 2
```

So the final answer is `2`.

Another example:

```text
12345
```

Digit sum:

```text
1 + 2 + 3 + 4 + 5 = 15
1 + 5 = 6
```

Now:

```text
12345 % 9 = 6
```

Same answer.

---

## Why Do Digits Have This Property?

Look at the number `123`.

We can write it as:

```text
123 = 1 × 100 + 2 × 10 + 3
```

Now look at the powers of `10` when divided by `9`:

```text
10 % 9 = 1
100 % 9 = 1
1000 % 9 = 1
```

So, with respect to division by `9`, the place values behave like `1`.

Therefore:

```text
123
```

has the same remainder as:

```text
1 + 2 + 3
```

This is why we can repeatedly add digits and get the same final result using modulo `9`.

---

## One Special Case

If the number is exactly divisible by `9`, `% 9` gives `0`.

But the digital root should be `9`.

Example:

```text
18

1 + 8 = 9
```

But:

```text
18 % 9 = 0
```

So we use:

```cpp
1 + (num - 1) % 9
```

This gives:

```text
18 → 9
38 → 2
12345 → 6
```

---

## Complexity

```text
Time Complexity: O(1)
Space Complexity: O(1)
```

## What to Remember

### Basic digit extraction

```text
num % 10 → get the last digit
num / 10 → remove the last digit
```

### Optimization

Repeated digit sum is called the **Digital Root**.

For this problem, the Digital Root can be found in **O(1)** using modulo `9`.

The formula is:

```text
1 + (num - 1) % 9
```

Don't memorize the formula blindly. First understand the basic digit-sum approach, then understand why modulo `9` gives the same final digit.
