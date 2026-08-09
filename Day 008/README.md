# Trapping Rain Water

## Description

This C++ program finds how much rain water can be trapped between buildings.

### Input

```text
[4, 2, 0, 3, 2, 5]
```

### Output

```text
9
```

## Graph

```markdown
## Graph

```text
5              █
4  █░░░░░░░░░░░█
3  ███░░░█░░░███
2  ███░░░██░████
1  ███░░░██░████
0  █████████████
   ------------
   4 2 0 3 2 5

░ = Water
█ = Building

Water = 2 + 4 + 1 + 2 = 9 units

## Approach

For every index, we find:

* `leftmax` → Maximum height on the left
* `rightmax` → Maximum height on the right

Then calculate:

```text
Water = min(leftmax, rightmax) - height[i]
```

### Example

For index `2`:

```text
Height = 0
Left Max = 4
Right Max = 5

Water = min(4, 5) - 0
      = 4
```

Water at each index:

```text
[0, 2, 4, 1, 2, 0]
```

Total:

```text
0 + 2 + 4 + 1 + 2 + 0 = 9
```

## Algorithm

1. Find the maximum height from the left.
2. Find the maximum height from the right.
3. Calculate water using `min(leftmax, rightmax) - height`.
4. Add all water values.

## Complexity

**Time:** `O(n)`

**Space:** `O(n)`

## Concepts Used

* Vectors
* Arrays
* `max()`
* `min()`
* Prefix Maximum
* Suffix Maximum



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


# Product of Array Except Self

## Description

Given an array, create a new array where each position contains the **product of all elements except the element at that position**.

### Example

Input:

```text
[1, 2, 3, 4]
```

Output:

```text
[24, 12, 8, 6]
```

### Why?

For each position:

```text
1 → 2 × 3 × 4 = 24
2 → 1 × 3 × 4 = 12
3 → 1 × 2 × 4 = 8
4 → 1 × 2 × 3 = 6
```

---

## Main Idea

For every element, we divide the other elements into two parts:

```text
Left side  | Current | Right side
```

For example:

```text
Array:  1   2   3   4
             ↑
           index 1
```

For `2`:

```text
Left  = 1
Right = 3 × 4 = 12

Answer = Left × Right
       = 1 × 12
       = 12
```

So, we calculate:

```text
Answer[i] = Left Product[i] × Right Product[i]
```

---

# Step 1: Find Left Product

The **left product** means:

> Product of all elements that are present to the **left of the current element**.

For the array:

```text
[1, 2, 3, 4]
```

The left products are:

```text
Index:          0   1   2   3
Array:          1   2   3   4
Left Product:   1   1   2   6
```

### How?

For index `0`, there is nothing on the left.

So:

```text
left[0] = 1
```

We use `1` because multiplying by `1` does not change the result.

For index `1`:

```text
left[1] = left[0] × nums[0]
        = 1 × 1
        = 1
```

For index `2`:

```text
left[2] = left[1] × nums[1]
        = 1 × 2
        = 2
```

For index `3`:

```text
left[3] = left[2] × nums[2]
        = 2 × 3
        = 6
```

Therefore:

```text
Left Product = [1, 1, 2, 6]
```

The code is:

```cpp
for(int i = 1; i < n; i++){
    left[i] = left[i-1] * nums[i-1];
}
```

---

# Step 2: Find Right Product

The **right product** means:

> Product of all elements that are present to the **right of the current element**.

For:

```text
[1, 2, 3, 4]
```

The right products are:

```text
Index:           0   1   2   3
Array:           1   2   3   4
Right Product:  24  12   4   1
```

### How?

For index `3`, there is nothing on the right.

So:

```text
right[3] = 1
```

For index `2`:

```text
right[2] = right[3] × nums[3]
         = 1 × 4
         = 4
```

For index `1`:

```text
right[1] = right[2] × nums[2]
         = 4 × 3
         = 12
```

For index `0`:

```text
right[0] = right[1] × nums[1]
         = 12 × 2
         = 24
```

Therefore:

```text
Right Product = [24, 12, 4, 1]
```

The code is:

```cpp
for(int i = n-2; i >= 0; i--){
    right[i] = right[i+1] * nums[i+1];
}
```

Notice that this loop goes **from right to left**.

---

# Step 3: Multiply Left Product and Right Product

Now we have:

```text
Array:          [1,  2, 3, 4]

Left Product:   [1,  1, 2, 6]

Right Product:  [24, 12, 4, 1]
```

For every index:

```text
Answer = Left Product × Right Product
```

### Index 0

```text
Left  = 1
Right = 24

Answer = 1 × 24 = 24
```

### Index 1

```text
Left  = 1
Right = 12

Answer = 1 × 12 = 12
```

### Index 2

```text
Left  = 2
Right = 4

Answer = 2 × 4 = 8
```

### Index 3

```text
Left  = 6
Right = 1

Answer = 6 × 1 = 6
```

Therefore:

```text
Answer = [24, 12, 8, 6]
```

The code is:

```cpp
for(int i = 0; i < n; i++){
    ans[i] = left[i] * right[i];
}
```

---

# Complete Example

```text
Array:          [1,  2,  3,  4]
                  ↓   ↓   ↓   ↓

Left Product:   [1,  1,  2,  6]

Right Product:  [24, 12,  4,  1]

                  ↓   ↓   ↓   ↓

Answer:         [24, 12,  8,  6]
```

Another way to understand it:

```text
Index 0:
1 | 2 3 4
Left = 1
Right = 2×3×4 = 24
Answer = 1×24 = 24

Index 1:
1 2 | 3 4
Left = 1
Right = 3×4 = 12
Answer = 1×12 = 12

Index 2:
1 2 3 | 4
Left = 1×2 = 2
Right = 4
Answer = 2×4 = 8

Index 3:
1 2 3 4 |
Left = 1×2×3 = 6
Right = 1
Answer = 6×1 = 6
```

---

# Algorithm

1. Create a `left` array and initialize it with `1`.
2. Calculate the product of elements on the left of each position.
3. Create a `right` array and initialize it with `1`.
4. Calculate the product of elements on the right of each position.
5. Multiply `left[i]` and `right[i]`.
6. Store the result in `ans[i]`.
7. Return the answer array.

---

# Example

### Input

```text
[1, 2, 3, 4]
```

### Output

```text
24 12 8 6
```

---

# Time Complexity

```text
O(n)
```

We traverse the array three times.

Even though there are three loops, each loop takes `O(n)`:

```text
O(n) + O(n) + O(n) = O(n)
```

---

# Space Complexity

```text
O(n)
```

We use three additional arrays:

```text
left
right
ans
```

Each contains `n` elements.

---

# Concepts Used

* C++
* Vectors
* Arrays
* Prefix Product
* Suffix Product
* For Loops
* Array Traversal
* Time Complexity
* Space Complexity

