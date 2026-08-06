# Reverse String

## Description

This C++ program reverses the characters of a string stored in a vector using the two-pointer technique.

## Algorithm

1. Initialize two pointers:

   * `st` at the beginning.
   * `end` at the end.
2. Swap the characters at `st` and `end`.
3. Move `st` forward and `end` backward.
4. Repeat until `st` is no longer less than `end`.
5. Print the reversed string.

## Example

**Input**

```cpp
{'h', 'e', 'l', 'l', 'o'}
```

**Output**

```
olleh
```

## Time Complexity

**O(n)**

* `n` = Number of characters

## Space Complexity

**O(1)**

## Concepts Used

* Vectors
* Two-Pointer Technique
* Functions
* Loops (`while`)
* `swap()` Function

# Score of a String

## Description

This C++ program calculates the score of a string by adding the absolute difference between the ASCII values of every two consecutive characters.

## Header File Used

```cpp
#include <cmath>
```

The `<cmath>` library provides the `abs()` function, which returns the absolute (positive) value of a number.

## Algorithm

1. Traverse the string from the first character to the second-last character.
2. Find the absolute difference between the ASCII values of consecutive characters using `abs()`.
3. Add each difference to the total score.
4. Print the final score.

## Example

**Input**

```cpp
"hello"
```

**Output**

```
13
```

**Explanation**

* |'h' - 'e'| = 3
* |'e' - 'l'| = 7
* |'l' - 'l'| = 0
* |'l' - 'o'| = 3

Total score = **13**

## About `abs()`

`abs()` is a built-in C++ function from the **`<cmath>`** library that returns the absolute (positive) value of a number.

Example:

```cpp
abs(-25) = 25
abs(7) = 7
```

## Time Complexity

**O(n)**

* `n` = Length of the string

## Space Complexity

**O(1)**

## Concepts Used

* Strings
* Loops (`for`)
* Functions
* `<cmath>` Library
* `abs()` Function
* ASCII Values
