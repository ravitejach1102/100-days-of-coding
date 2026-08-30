# Implement Stack Using Two Queues

## Example

**Input:**

```text
push(1)
push(2)
push(3)
pop()
pop()
pop()
```

**Output:**

```text
3
2
1
```

**Explanation:**
A stack follows **LIFO (Last In, First Out)**.
So, `3` is inserted last and must be removed first.

The two queues are used in such a way that the latest inserted element always stays at the **front of `q1`**.

## Concept

**Queue + Stack**

A queue normally follows **FIFO**, but we use two queues to make it behave like a stack.
During `push()`, we rearrange the elements so the newest element comes to the front.

## Approach

### Push Operation

Suppose we want to push `3`.

1. Move all elements from `q1` to `q2`.
2. Insert the new element `3` into `q1`.
3. Move all elements from `q2` back to `q1`.
4. Now the new element is at the **front of `q1`**.

For example:

After `push(1)`:

`q1 = [1]`

After `push(2)`:

* Move `1` → `q2`
* Add `2` → `q1`
* Move `1` back

`q1 = [2, 1]`

After `push(3)`:

`q1 = [3, 2, 1]`

So the front of `q1` always contains the **top of the stack**.

### Pop Operation

Since the top element is always at the front of `q1`:

1. Take `q1.front()`.
2. Remove it using `q1.pop()`.
3. Return the removed value.

### Top Operation

Simply return `q1.front()` because the front element is the top of the stack.

### Empty Operation

Check whether `q1` is empty.

## Dry Run

**Operations:**

```text
push(1)
push(2)
push(3)
pop()
pop()
pop()
```

### `push(1)`

`q1 = [1]`

### `push(2)`

Move `1` to `q2`:

`q2 = [1]`

Add `2` to `q1`:

`q1 = [2]`

Move `1` back:

`q1 = [2, 1]`

### `push(3)`

Move `[2, 1]` to `q2`.

Add `3`:

`q1 = [3]`

Move `[2, 1]` back:

`q1 = [3, 2, 1]`

### `pop()`

Front = `3`

`q1 = [2, 1]`

Output: `3`

### `pop()`

Front = `2`

`q1 = [1]`

Output: `2`

### `pop()`

Front = `1`

`q1 = []`

Output: `1`

Final output:

```text
3
2
1
```

## Complexity

* Time Complexity: **O(n)** for `push()` because elements are moved between the two queues. `pop()`, `top()`, and `empty()` take **O(1)**.
* Space Complexity: **O(n)** because the elements are stored in two queues.


# Implement Queue Using Two Stacks

## Example

**Input:**

```text
push(1)
push(2)
push(3)
pop()
pop()
pop()
```

**Output:**

```text
1
2
3
```

**Explanation:**
A queue follows **FIFO (First In, First Out)**.

Since `1` was inserted first, it must be removed first. The two stacks are used to keep the oldest element at the top of `s1`.

## Concept

**Stack + Queue**

We use two stacks to implement queue operations.
During `push()`, elements are rearranged so that the **first inserted element always stays at the top of `s1`**.

## Approach

### Push Operation

When adding a new element:

1. Move all elements from `s1` to `s2`.
2. Push the new element into `s1`.
3. Move all elements from `s2` back to `s1`.
4. Now the oldest element is again at the top of `s1`.

For example:

After `push(1)`:

` s1 = [1]`

After `push(2)`:

* Move `1` to `s2`
* Push `2` into `s1`
* Move `1` back

` s1 = [2, 1]`

The top of `s1` is `1`, which is the front of the queue.

After `push(3)`:

` s1 = [3, 2, 1]`

So, the top of `s1` always represents the **front of the queue**.

### Pop Operation

1. Take the top element of `s1`.
2. Remove it using `s1.pop()`.
3. Return the removed element.

Since the oldest element is always at the top, this follows FIFO.

### Front Operation

Return `s1.top()` because the top element of `s1` is the front of the queue.

### Empty Operation

Check whether `s1` is empty.

## Dry Run

**Operations:**

```text
push(1)
push(2)
push(3)
pop()
pop()
pop()
```

### `push(1)`

` s1 = [1]`

Top = `1`

### `push(2)`

Move `1` from `s1` to `s2`:

` s2 = [1]`

Push `2` into `s1`:

` s1 = [2]`

Move `1` back to `s1`:

` s1 = [2, 1]`

Top = `1`

### `push(3)`

Move `[2, 1]` to `s2`.

Push `3`:

` s1 = [3]`

Move `[2, 1]` back:

` s1 = [3, 2, 1]`

Top = `1`

### `pop()`

Top = `1`

Remove `1`:

` s1 = [3, 2]`

Output: `1`

### `pop()`

Top = `2`

Remove `2`:

` s1 = [3]`

Output: `2`

### `pop()`

Top = `3`

Remove `3`:

` s1 = []`

Output: `3`

Final output:

```text
1
2
3
```

## Complexity

* Time Complexity: **O(n)** for `push()` because all existing elements may be moved between the stacks. `pop()`, `front()`, and `empty()` take **O(1)**.
* Space Complexity: **O(n)** because the elements are stored in the two stacks.
