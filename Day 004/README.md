# Palindrome Number

## Problem
Given an integer `x`, determine whether it is a palindrome. A palindrome number reads the same forward and backward.

## Approach
- If the number is negative, return `false`.
- Store the original number.
- Reverse the digits of the number.
- Compare the reversed number with the original number.
- If both are equal, return `true`; otherwise, return `false`.

## Example

**Palindrome**
```
Input: 121

Original Number : 121
Reversed Number : 121

Output: true
```

**Not a Palindrome**
```
Input: 123

Original Number : 123
Reversed Number : 321

Output: false
```

## Algorithm
1. Check if the number is negative.
2. Store the original number.
3. Reverse the number digit by digit.
4. Compare the original number with the reversed number.
5. Return the result.

## Time Complexity
- **O(log n)**

## Space Complexity
- **O(1)**

# Find Numbers with Even Number of Digits

## Description
This C++ program counts how many numbers in a list have an even number of digits.

## Algorithm
1. Traverse each number in the array/vector.
2. Count the number of digits using a `while` loop.
3. If the digit count is even, increase the answer by 1.
4. Print the final count.

## Example

**Input**
```cpp
{12, 345, 2, 6, 7896}
```

**Output**
```
2
```

**Explanation**
- 12 → 2 digits ✅
- 345 → 3 digits ❌
- 2 → 1 digit ❌
- 6 → 1 digit ❌
- 7896 → 4 digits ✅

Total numbers with even digits = **2**.

## Time Complexity
**O(n × d)**

- `n` = Number of elements
- `d` = Number of digits in each number

## Space Complexity
**O(1)**

## Concepts Used
- Arrays
- Vectors
- Loops (`for`, `while`)
- Functions
- Conditional Statements (`if`)
- Integer Division