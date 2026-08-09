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
