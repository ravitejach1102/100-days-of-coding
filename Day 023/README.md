# Diagonal Sum

## 1. Problem Statement

Given a square matrix, find the sum of both diagonals.

If the matrix has an odd number of rows, the middle element belongs to both diagonals, so count it only once.

## 2. Concept

* Use a **2D matrix**.
* Main diagonal: `mat[i][i]`
* Other diagonal: `mat[i][n-i-1]`
* If the matrix size is odd, subtract the middle element once.

### Understanding `mat[i][i]`

Here, `i` represents the **row** and the second `i` represents the **column**.

For a `3 × 3` matrix:

```text
       j=0  j=1  j=2
i=0     1    2    3
i=1     4    5    6
i=2     7    8    9
```

For the main diagonal, row and column are always the same:

```text
mat[0][0] → 1
mat[1][1] → 5
mat[2][2] → 9
```

So we use:

```cpp
mat[i][i]
```

### Understanding `mat[i][n-i-1]`

For the other diagonal, we need the column to move from **right to left**.

For `n = 3`:

```text
i = 0 → n-i-1 = 3-0-1 = 2 → mat[0][2] → 3
i = 1 → n-i-1 = 3-1-1 = 1 → mat[1][1] → 5
i = 2 → n-i-1 = 3-2-1 = 0 → mat[2][0] → 7
```

So the column indexes are:

```text
2 → 1 → 0
```

The `-1` is needed because array indexes start from `0`.

Therefore:

```cpp
mat[i][n-i-1]
```

gives the other diagonal.

## 3. Logic

1. Find the matrix size `n`.
2. Use `mat[i][i]` to get the main diagonal.
3. Use `mat[i][n-i-1]` to get the other diagonal.
4. Add both diagonal sums.
5. If `n` is odd, the middle element was counted twice, so subtract it once.
6. Return the final sum.

## 4. Approach

1. Initialize `rsum` and `lsum` as `0`.
2. Run a loop from `i = 0` to `n-1`.
3. Add `mat[i][i]` to `rsum`.
4. Add `mat[i][n-i-1]` to `lsum`.
5. Add both sums.
6. If `n` is odd, subtract `mat[n/2][n/2]`.
7. Return the answer.

## 5. Dry Run

Example:

```text
1  2  3
4  5  6
7  8  9
```

Here:

```text
n = 3
```

### Main diagonal — `mat[i][i]`

```text
i = 0 → mat[0][0] → 1
i = 1 → mat[1][1] → 5
i = 2 → mat[2][2] → 9
```

Sum:

```text
1 + 5 + 9 = 15
```

### Other diagonal — `mat[i][n-i-1]`

```text
i = 0 → mat[0][2] → 3
i = 1 → mat[1][1] → 5
i = 2 → mat[2][0] → 7
```

Sum:

```text
3 + 5 + 7 = 15
```

### Final calculation

```text
15 + 15 = 30
```

The middle element `5` was counted twice.

So:

```text
30 - 5 = 25
```

**Answer: `25`**

## 7. Time Complexity

**O(n)** — The loop runs `n` times and checks two diagonal elements in each iteration.

## 8. Space Complexity

**O(1)** — Only a few extra variables are used.
