# construct-uniform-parity-array

## Example

**Input:**

`nums = [1, 4, 7]`

**Output:**

`True`

**Explanation:**

The minimum element is `1`, which is **odd**.

The operation is to **subtract the minimum element from another element**.

So:

* **Odd − Odd = Even** → `7 − 1 = 6`
* **Even − Odd = Odd** → `4 − 1 = 3`

Since the minimum element is odd, an odd element can be changed into an even element.

Therefore, the answer is `True`.

## Concept

**Minimum Element + Parity Check**

We find the minimum element because it is used for the subtraction operation.
Then we check whether the minimum is odd or even.

## Approach

1. Find the minimum element of the array.
2. If the minimum is **odd**, return `true`.

   * We can subtract the odd minimum from an odd element:
     **Odd − Odd = Even**
3. If the minimum is **even**, check every element.
4. If any element is odd:

   * **Even − Odd = Odd**
   * So the odd element will remain odd.
   * Return `false`.
5. If all elements are even, return `true`.

## Dry Run

**Input:**

`nums = [1, 4, 7]`

### Step 1: Find minimum

`min = 1`

`1` is **odd**.

### Step 2: Apply the operation

For the odd element `7`:

`7 − 1 = 6`

**Odd − Odd = Even**

So the odd element can become even.

Therefore, we return:

`true`

**Output:** `True`

### Example with Even Minimum

**Input:**

`nums = [2, 3, 6]`

Minimum:

`min = 2` → **Even**

Now consider the odd element `3`:

`3 − 2 = 1`

**Odd − Even = Odd**

It is still odd.

Therefore, when the minimum is even, an odd element cannot become even.

So:

`return false`

**Output:** `False`

## Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(1)**
