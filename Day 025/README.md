# Rotate Image

## 1. Problem Statement

Given a square matrix, rotate the matrix **90 degrees clockwise**.

For example:

```text
1 2 3
4 5 6
7 8 9
```

After rotating 90° clockwise:

```text
7 4 1
8 5 2
9 6 3
```

## 2. Concept

* Use a **2D matrix**.
* Create a new matrix to store the rotated values.
* For every element `matrix[i][j]`, place it at `result[j][n-1-i]`.
* Here, `i` represents the row and `j` represents the column.

## 3. Logic

The important line is:

```cpp
result[j][n - 1 - i] = matrix[i][j];
```

It means:

```text
Old position → New position

[i][j] → [j][n-1-i]
```

For a `3 × 3` matrix:

```text
matrix[0][0] → result[0][2]
matrix[0][1] → result[1][2]
matrix[0][2] → result[2][2]
```

So:

```text
1 → position [0][2]
2 → position [1][2]
3 → position [2][2]
```

The first row:

```text
1 2 3
```

becomes the last column:

```text
    1
    2
    3
```

Similarly, all elements are moved to their new positions.

## 4. Approach

1. Find the matrix size `n`.
2. Create a new `n × n` matrix called `result`.
3. Visit every element using two loops.
4. Move `matrix[i][j]` to `result[j][n-1-i]`.
5. Copy `result` back into `matrix`.
6. Print the rotated matrix.

## 5. Dry Run

Example:

```text
1 2 3
4 5 6
7 8 9
```

Here:

```text
n = 3
```

### Step-by-step

For `i = 0`:

```text
j = 0 → matrix[0][0] = 1
result[0][3-1-0] = result[0][2] = 1

j = 1 → matrix[0][1] = 2
result[1][2] = 2

j = 2 → matrix[0][2] = 3
result[2][2] = 3
```

For `i = 1`:

```text
j = 0 → 4 → result[0][1]
j = 1 → 5 → result[1][1]
j = 2 → 6 → result[2][1]
```

For `i = 2`:

```text
j = 0 → 7 → result[0][0]
j = 1 → 8 → result[1][0]
j = 2 → 9 → result[2][0]
```

Final `result`:

```text
7 4 1
8 5 2
9 6 3
```

Then:

```cpp
matrix = result;
```

updates the original matrix.

## 7. Time Complexity

**O(n²)** — We visit every element of the `n × n` matrix once.

## 8. Space Complexity

**O(n²)** — We create another `n × n` matrix to store the rotated result.
