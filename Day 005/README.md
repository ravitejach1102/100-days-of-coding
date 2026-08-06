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


# Length of Last Word

## Description

This C++ program finds the length of the last word in a given string. It starts from the end of the string because the last word is located there, making it the simplest and most efficient approach.

## Algorithm

### First `while` Loop

```cpp
while (i >= 0 && s[i] == ' ') {
    i--;
}
```

* Starts from the last character of the string.
* Skips all trailing spaces.
* Stops when it reaches the last character of the last word.

**Example**

```text
"Hello World   "
             ↑
```

The loop skips the spaces and stops at **`d`**.

### Second `while` Loop

```cpp
while (i >= 0 && s[i] != ' ') {
    length++;
    i--;
}
```

* Starts from the last character of the last word.
* Counts each character until a space or the beginning of the string is reached.
* The final count is the length of the last word.

**Example**

```text
Hello World
          ↑
```

Count:

* `d` → 1
* `l` → 2
* `r` → 3
* `o` → 4
* `W` → 5

So, the length of the last word is **5**.

## Example

**Input**

```text
Hello World
```

**Output**

```text
5
```

## Time Complexity

**O(n)**

* The first `while` loop skips trailing spaces.
* The second `while` loop counts the characters of the last word.
* Although there are two `while` loops, together they visit each character at most once.
* Therefore, the overall time complexity is **O(n)**.

## Space Complexity

**O(1)**

## Concepts Used

* Strings
* While Loops
* String Indexing
* Functions
* Conditional Statements


# Convert String to Lowercase

## Description

This C++ program converts all uppercase letters in a string to lowercase using ASCII values. Lowercase letters, digits, spaces, and special characters remain unchanged.

## Algorithm

1. Traverse each character of the string.
2. Check if the character is an uppercase letter (`'A'` to `'Z'`).
3. If it is uppercase, convert it to lowercase using:

   ```cpp
   s[i] = s[i] - 'A' + 'a';
   ```
4. Return the updated string.

## Logic Behind

```cpp
s[i] = s[i] - 'A' + 'a';
```

ASCII values:

| Character | ASCII Value |
| --------- | ----------: |
| A         |          65 |
| B         |          66 |
| C         |          67 |
| ...       |         ... |
| Z         |          90 |
| a         |          97 |
| b         |          98 |
| c         |          99 |
| ...       |         ... |
| z         |         122 |

### How it Works

Suppose the character is **'C'**.

```
'C' = 67
'A' = 65
'a' = 97
```

Step 1:

```cpp
'C' - 'A'
67 - 65 = 2
```

Step 2:

```cpp
2 + 'a'
2 + 97 = 99
```

Step 3:

```
99 = 'c'
```

So,

```cpp
'C' → 'c'
```

Another example:

```
'M' = 77

77 - 65 = 12
12 + 97 = 109
109 = 'm'
```

### Why does this work?

* `'A'` and `'a'` are the starting characters of the uppercase and lowercase alphabets.
* By subtracting `'A'`, we find the position of the uppercase letter in the alphabet.
* By adding `'a'`, we get the lowercase letter at the same position.

## Example

**Input**

```cpp
"HeLLo WoRLD"
```

**Output**

```text
hello world
```

## Time Complexity

**O(n)**

* `n` = Length of the string.
* The loop visits each character exactly once.

## Space Complexity

**O(1)**

* No extra memory is used except for a few variables.

## Concepts Used

* Strings
* ASCII Values
* Character Manipulation
* Loops (`for`)
* Conditional Statements (`if`)
* Functions
