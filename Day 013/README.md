# Pascal's Triangle

## Problem

Given an integer `numRows`, generate the first `numRows` rows of Pascal's Triangle.

### Example

If `numRows = 4`:

```text
1
1 1
1 2 1
1 3 3 1
```

## Logic

We build Pascal's Triangle one row at a time.

Every row follows 3 simple rules:

1. The first element is always `1`.
2. The middle elements are found by adding two numbers from the previous row.
3. The last element is always `1`.

### Example

Suppose the previous row is:

```text
1 2 1
```

To create the next row:

```text
1 3 3 1
```

We calculate the middle elements:

```text
1 + 2 = 3
2 + 1 = 3
```

So the new row becomes:

```text
1 3 3 1
```

## How the Code Works

```cpp
row.push_back(1);
```

This adds `1` at the beginning of every row.

Then we calculate the middle elements:

```cpp
row.push_back(ans[i-1][j-1] + ans[i-1][j]);
```

Here:

* `ans[i-1]` means the previous row.
* `j-1` means the number before the current position.
* `j` means the current position.
* We add these two numbers to get the new number.

Finally, we add `1` at the end:

```cpp
row.push_back(1);
```

Then we store the completed row:

```cpp
ans.push_back(row);
```

## Simple Way to Remember

Think like this:

```text
Start with 1
     ↓
Add two numbers from the previous row
     ↓
End with 1
     ↓
Store the row
```

## Complexity

* **Time Complexity:** O(n²)
* **Space Complexity:** O(n²)

## Key Learning

`vector<vector<int>>` is used because Pascal's Triangle has multiple rows, and each row can have a different number of elements.
