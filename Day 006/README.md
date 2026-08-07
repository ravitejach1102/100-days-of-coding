# Shuffle the Array

## Description
This program shuffles the array by taking one element from the first half and then one element from the second half.

For example:

Input:
```cpp
{2, 5, 1, 3, 4, 7}
```

Output:
```cpp
{2, 3, 5, 4, 1, 7}
```

---

## Algorithm
1. Create an empty vector.
2. Traverse the first half of the array.
3. Add one element from the first half.
4. Add one element from the second half.
5. Repeat until all elements are added.
6. Return the shuffled array.

---

## Example

**Input**
```cpp
nums = {2, 5, 1, 3, 4, 7}
n = 3
```

**Output**
```cpp
2 3 5 4 1 7
```

---

## Time Complexity
**O(n)**

## Space Complexity
**O(n)**