# Fibonacci Number Using Recursion

## Description

This C++ program finds the **Nth Fibonacci number** using **recursion**.

In the Fibonacci sequence:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Each number is the sum of the previous two numbers.

## How It Works

The program uses a recursive function:

```cpp
fib(n) = fib(n-1) + fib(n-2)
```

### Base Case

If `n` is `0` or `1`, the function returns `n`.

```cpp
if(n <= 1) {
    return n;
}
```

### Recursive Case

For values greater than `1`:

```cpp
return fib(n-1) + fib(n-2);
```

The function keeps calling itself until it reaches the base case.

## Example

### Input

```text
6
```

### Output

```text
8
```

### Explanation

```text
fib(6)
= fib(5) + fib(4)
= 5 + 3
= 8
```

## Algorithm

1. Read the value of `n`.
2. Call `fib(n)`.
3. If `n` is `0` or `1`, return `n`.
4. Otherwise, calculate `fib(n-1) + fib(n-2)`.
5. Print the result.

## Time Complexity

```text
O(2^n)
```

The function makes many repeated recursive calls.

## Space Complexity

```text
O(n)
```

Because of the recursive call stack.

## Concepts Used

* C++
* Functions
* Recursion
* Base Case
* Recursive Case
* Fibonacci Sequence

# Power of Two

## Description

This C++ program checks whether a given number is a **power of 2**.

Examples of powers of 2:

```text
1, 2, 4, 8, 16, 32, 64, ...
```

The program uses a **bitwise AND (`&`) operator** to check this.

## How It Works

For a positive number `n`, a power of 2 has only **one `1` in its binary representation**.

Example:

```text
8  →  1000
7  →  0111
```

When we calculate:

```text
8 & 7 = 0
```

So, `8` is a power of 2.

The condition used is:

```cpp
(n & (n - 1)) == 0
```

## Algorithm

1. Read the number `n`.
2. Check if `n` is `0`.
3. Check that `n` is positive.
4. Calculate `n & (n - 1)`.
5. If the result is `0`, the number is a power of 2.
6. Print `Yes` or `No`.

## Example 1

### Input

```text
8
```

### Output

```text
Yes
```

### Explanation

```text
8  = 1000
7  = 0111

1000
&
0111
----
0000
```

Therefore, `8` is a power of 2.

## Example 2

### Input

```text
10
```

### Output

```text
No
```

Because `10` is not a power of 2.

## Time Complexity

```text
O(1)
```

The program performs only a few operations.

## Space Complexity

```text
O(1)
```

No extra memory is used.

## Concepts Used

* C++
* Functions
* Boolean (`bool`)
* Conditional statements
* Bitwise AND (`&`)
* Binary numbers
