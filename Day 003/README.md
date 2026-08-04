# Majority Element

## Problem
The **Majority Element** is the element that appears **more than n/2 times** in the array.

Example:
```text
Input:  [3, 2, 3]
Output: 3
```

---

# 1. Brute Force Approach

### Idea
Check every element one by one and count how many times it appears in the entire array.

### Steps
1. Pick one element.
2. Count its occurrences by scanning the whole array.
3. If its count is greater than `n/2`, return it.
4. Otherwise, check the next element.

### Complexity
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)

---

# 2. Sorting Approach

### Idea
Sort the array so that equal elements come together. Then count consecutive occurrences.

### Steps
1. Sort the array.
2. Traverse the sorted array.
3. Count how many times the current element appears continuously.
4. If the count becomes greater than `n/2`, return that element.

### Complexity
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(1)

---

# 3. Moore's Voting Algorithm (Optimal)

### Idea
Keep one element as the **candidate** and maintain a **count**.

- If the current element is the same as the candidate, increase the count.
- Otherwise, decrease the count.
- When the count becomes **0**, choose the current element as the new candidate.

Since the majority element appears more than half of the time, it cannot be completely cancelled by the other elements. Therefore, the final candidate is the majority element.

### Steps
1. Start with `count = 0`.
2. Traverse the array.
3. If `count` becomes `0`, make the current element the candidate.
4. Increase or decrease the count based on whether the current element matches the candidate.
5. After the traversal, return the candidate.

### Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)