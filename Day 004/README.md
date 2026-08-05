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